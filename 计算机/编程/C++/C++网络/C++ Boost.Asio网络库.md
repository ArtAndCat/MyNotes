
需要安装!

```sh
sudo pacman -S boost
```

```cpp
#include <boost/asio.hpp>
```


[[C++ 网络项目列表]]



```cpp
    // 1. 所有 Asio 程序都需要一个 io_context 对象
    boost::asio::io_context io_context;
```

```cpp
    // 2. 创建解析器，将域名和端口解析为网络端点 客户端使用
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve("bilibili.com", "80"); // 同步解析
```

```cpp
// 2. 创建 acceptor 对象，监听 12345 端口（IPv4 任意地址）  服务端用
boost::asio::ip::tcp::acceptor acceptor(io_context,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 12345));
```

```cpp
    // 3. 创建 socket 并连接到其中一个端点  客户端
    boost::asio::ip::tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints); // 同步连接
```

```cpp
// 3. 接受一个客户端连接（阻塞）服务端用
boost::asio::ip::tcp::socket socket(io_context);
acceptor.accept(socket);
```

```cpp
    // 4. 发送 HTTP 请求
    std::string request =
        "GET / HTTP/1.1\r\n"
        "Host: bilibili.com\r\n"
        "Connection: close\r\n\r\n";
    boost::asio::write(socket, boost::asio::buffer(request));
```

```cpp
    // 5. 接收响应
    std::string response;
    boost::system::error_code error;
    while (true)
    {
        char buf[1024];
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if (error == boost::asio::error::eof)
            break; // 连接关闭
        else if (error)
            throw boost::system::system_error(error); // 其他错误
        response.append(buf, len);
    }

    std::cout << response << std::endl;

    return 0;
}
```

## Boost.Asio 常见操作步骤笔记

Boost.Asio 的核心是 `io_context`，所有 I/O 对象（socket、acceptor、timer 等）都依赖它。下面按场景总结标准操作步骤。


### 1. 通用基础

#### 初始化
```cpp
boost::asio::io_context io;          // I/O 执行上下文
```
#### 运行事件循环
- **同步模式**：调用 `io.run()`，阻塞直到所有操作完成。
- **异步模式**：调用 `io.run()`，等待异步操作完成（通常在 `main()` 最后）。
- 多线程并发：多个线程调用 `io.run()`，线程池模式。

#### 清理
- 析构 `io_context` 或等待 `run()` 返回。

---

### 2. 同步操作

#### 2.1 同步 TCP 客户端
1. 创建 `io_context`。
2. 创建 `resolver`，调用 `resolve()` 将域名/服务解析为端点列表。
3. 创建 `socket`。
4. 调用 `connect(socket, endpoints)` 连接。
5. 调用 `write()` 或 `read_some()` / `read()` 进行数据传输。
6. 检查 `error_code` 或捕获异常。
7. 关闭 socket（析构自动关闭）。

#### 2.2 同步 TCP 服务器
1. 创建 `io_context`。
2. 创建 `acceptor`，绑定 `endpoint`（指定地址和端口）。
3. 调用 `acceptor.listen()`（可选，构造函数可同时监听）。
4. 循环：
   - 创建 `socket`。
   - 调用 `acceptor.accept(socket)` 阻塞等待客户端连接。
   - 对 `socket` 进行 `read_some()` / `write()` 交互。
   - 关闭连接（socket 析构或显式 close）。
5. 停止 acceptor 或跳出循环。

---

### 3. 异步操作

异步操作需要提供**回调函数**（函数对象、lambda、std::bind），操作立即返回，回调在操作完成时由 `io_context` 调用。

#### 3.1 异步 TCP 客户端
1. 创建 `io_context`。
2. 创建 `resolver`，调用 `async_resolve()`，传入回调。
   - 回调参数：`error_code`，`endpoints`。
3. 在回调中：
   - 创建 `socket`（通常用 `shared_ptr` 管理生命周期）。
   - 调用 `async_connect()`，传入回调。
4. 在连接回调中：
   - 若成功，调用 `async_write()` 或 `async_read_some()`。
   - 继续链式回调。
5. 调用 `io_context.run()` 启动事件循环。

#### 3.2 异步 TCP 服务器
1. 创建 `io_context`。
2. 创建 `acceptor`，绑定并监听。
3. 调用 `acceptor.async_accept()`，传入回调。
   - 回调参数：`error_code`，新 `socket`。
4. 在回调中：
   - 立即再次调用 `async_accept()` 以接受下一个连接。
   - 对新 `socket` 调用 `async_read()` / `async_write()`（同样使用 `shared_ptr` 管理）。
5. 在读写回调中继续异步读写或关闭连接。
6. 调用 `io_context.run()`。

---

### 4. 定时器

#### 同步定时器
```cpp
boost::asio::steady_timer timer(io);
timer.expires_after(std::chrono::seconds(5));
timer.wait();                     // 阻塞 5 秒
```

#### 异步定时器
```cpp
boost::asio::steady_timer timer(io);
timer.expires_after(std::chrono::seconds(5));
timer.async_wait([](boost::system::error_code ec) {
    if (!ec) std::cout << "Timeout\n";
});
io.run();
```

---

### 5. 错误处理

- **同步**：用 `boost::system::error_code` 重载避免异常，或 `try-catch` 捕获 `boost::system::system_error`。
- **异步**：回调函数的第一个参数是 `error_code`，检查后处理。

```cpp
// 同步
boost::system::error_code ec;
size_t len = socket.read_some(buffer, ec);
if (ec == boost::asio::error::eof) { /* 对方关闭 */ }
else if (ec) throw boost::system::system_error(ec);

// 异步
socket.async_read_some(buffer, [](boost::system::error_code ec, size_t len) {
    if (!ec) { /* 处理数据 */ }
    else if (ec == boost::asio::error::eof) { /* 正常关闭 */ }
    else { /* 错误 */ }
});
```

---

### 6. 多线程并发

- 创建 `io_context`。
- 在多个线程中调用 `io_context::run()`。
- 所有异步回调会由这些线程任意执行（需要保护共享数据）。

```cpp
boost::asio::io_context io;
auto work = std::make_shared<boost::asio::io_context::work>(io); // 防止 run 立即返回
std::vector<std::thread> threads;
for (int i = 0; i < 4; ++i) threads.emplace_back([&] { io.run(); });
// 提交异步操作...
work.reset();           // 允许 run 退出
for (auto& t : threads) t.join();
```

---

### 7. 资源管理

- **异步回调中捕获 `shared_ptr` 以保证对象存活**。
- 常用模式：`std::make_shared<Session>(std::move(socket))`，然后在回调中捕获 `shared_ptr`。
- 避免使用裸 `this`，除非确保对象生命周期。

```cpp
class Session : public std::enable_shared_from_this<Session> {
public:
    void start() {
        auto self = shared_from_this();
        socket.async_read_some(buffer, [this, self](error_code ec, size_t len) {
            // 使用 self 确保对象存活
        });
    }
};
```

---

### 8. 其他常见操作

#### 8.1 取消异步操作
```cpp
socket.cancel();   // 取消该 socket 上的所有异步操作
timer.cancel();    // 取消定时器
```

#### 8.2 停止 io_context
```cpp
io.stop();   // 停止事件循环，正在运行的回调可能中断
```

#### 8.3 处理信号
```cpp
boost::asio::signal_set signals(io, SIGINT, SIGTERM);
signals.async_wait([](error_code, int signo) {
    // 处理退出信号
});
```

---

### 总结

| 场景 | 开头 | 中间 | 结尾 |
|------|------|------|------|
| **同步客户端** | io_context, resolver, socket | resolve, connect, read/write | 错误检查, 自动析构 |
| **同步服务器** | io_context, acceptor | bind, listen, accept 循环, 每个连接读写 | 停止监听, 关闭 socket |
| **异步客户端** | io_context, resolver, shared_ptr<socket> | async_resolve → async_connect → async_write/read | io.run(), 回调中处理完成 |
| **异步服务器** | io_context, acceptor | async_accept 循环, 每连接异步读写 | io.run(), 停止 acceptor |
| **定时器** | steady_timer | expires_after, async_wait 或 wait | 回调或继续 |

掌握这些基本步骤，就能灵活使用 Boost.Asio 构建各种网络应用。








### 1. 常见的服务器并发模型

|模型|实现方式|优点|缺点|
|---|---|---|---|
|**1:1（每连接一线程）**|同步 accept，为每个客户端创建线程|简单，逻辑直白，适合低并发|线程开销大，内存占用高，上下文切换频繁，C10K 问题突出|
|**线程池 + 同步**|多个线程各自 accept，或由主线程 accept 后分发给线程池|比 1:1 节省线程|同步 I/O 仍会阻塞线程，线程数仍受限制|
|**单线程异步**|一个线程运行 `io_context::run()`，所有连接通过异步回调处理|极低开销，无锁，适合高并发|回调代码复杂（可用协程简化），不能利用多核 CPU|
|**多线程异步**|多个线程运行 `io_context::run()`，共享同一个 `io_context`|可扩展多核，高并发|需要处理回调中的线程安全（共享数据加锁或设计成无共享）|

