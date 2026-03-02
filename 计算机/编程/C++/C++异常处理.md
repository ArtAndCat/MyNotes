



关键字：
`__PRETTY_FUNCTION__`  返回函数名（C++的，C的只有FUN...）
`__LINE__` 返回行数   (继承于C)
比如
```cpp
cout << __PRETTY_FUNCTION__ << ':' << __LINE__;
return -1;
```
#### 基础语法：三步曲
---
1. throw - 抛出异常
2. try - 尝试执行可能抛出异常的代码
3. catch - 捕获并处理异常
小小例子
```cpp

```
#### 2.1 C++ 标准异常层次结构
```txt
std::exception (所有标准异常的基类)
│
├── std::logic_error (逻辑错误 - 程序逻辑有问题)
│   │
│   ├── std::invalid_argument (无效参数)
│   │   - 传递给函数的参数值不被接受
│   │   - 例：给sqrt()传负数，给字符串转换函数传非法格式
│   │
│   ├── std::domain_error (定义域错误)
│   │   - 参数值在数学函数定义域之外
│   │   - 例：数学运算中的非法值
│   │
│   ├── std::length_error (长度错误)
│   │   - 试图创建超出最大允许长度的对象
│   │   - 例：std::string 或 std::vector 长度超出限制
│   │
│   └── std::out_of_range (越界错误)
│       - 访问容器时索引超出有效范围
│       - 例：访问 vector[100]，但vector只有10个元素
│
├── std::runtime_error (运行时错误 - 执行期间发生的问题)
│   │
│   ├── std::range_error (范围错误)
│   │   - 计算结果超出有意义的范围
│   │   - 例：浮点数转换时精度丢失太大
│   │
│   ├── std::overflow_error (上溢错误)
│   │   - 算术运算结果超出类型能表示的最大值
│   │   - 例：int 最大是2147483647，再加1就会溢出
│   │
│   ├── std::underflow_error (下溢错误)
│   │   - 算术运算结果太小，超出类型能表示的最小正值
│   │   - 例：浮点数太小，超出精度范围
│   │
│   └── std::system_error (系统错误)
│       - 底层操作系统调用失败
│       - 包含错误码，可以获取系统特定的错误信息
│       - 例：文件操作失败，网络连接失败
│
├── std::bad_alloc (内存分配失败)
│   - 当 new 或 new[] 无法分配请求的内存时抛出
│   - 例：内存不足，分配超大数组
│
├── std::bad_cast (类型转换失败)
│   - dynamic_cast 对引用类型转换失败时抛出
│   - 例：基类引用转派生类引用，但实际不是派生类
│
├── std::bad_typeid (类型信息错误)
│   - typeid 运算符应用于空指针时抛出
│
├── std::bad_exception (意外异常)
│   - 函数声明了异常规范但抛出了未列出的异常
│
├── std::bad_function_call (函数调用错误)
│   - 调用空的 std::function 对象时抛出
│   - 例：std::function<void()> f; f();
│
├── std::bad_weak_ptr (弱指针错误)
│   - 通过已过期（expired）的 weak_ptr 创建 shared_ptr 时抛出
│
├── ios_base::failure (输入输出错误)
│   - 流操作失败时抛出
│   - 例：文件读取失败，格式化错误
│
└── future_error (future/promise错误)
    - std::future 或 std::promise 相关操作失败
    - 例：对同一个 promise 多次设置值
```

##### 例子:
```cpp
#include <iostream>
#include <stdexcept>

// 1. throw - 抛出异常
void checkAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("年龄不能为负数");
    }
    if (age > 150) {
        throw std::out_of_range("年龄超出合理范围");
    }
    std::cout << "年龄有效: " << age << std::endl;
}

// 2. try - 尝试执行可能抛出异常的代码
// 3. catch - 捕获并处理异常
int main() {
    try {
        checkAge(-5);      // 会抛出 invalid_argument
        checkAge(200);     // 不会执行到这里
    }
    catch (const std::invalid_argument& e) {
        std::cout << "参数错误: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "范围错误: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "其他错误: " << e.what() << std::endl;
    }
    
    std::cout << "程序继续执行..." << std::endl;
}
```

```cpp
// 最佳实践：
void process_with_retry() {
    for (int i = 0; i < 3; ++i) {
        try {
            do_operation();  // 可能失败的操作
            break;  // 成功则退出循环
        }
        catch (const std::exception& e) {
            if (i == 2) throw;  // 最后一次尝试失败，重新抛出
            std::cout << "重试 " << (i + 1) << "/3\n";
        }
    }
}
```
实际项目中的选择
```cpp
// 场景1：库开发 - 通常用异常
class DatabaseConnection {
public:
    void connect() {
        if (!try_connect()) {
            throw ConnectionFailed("无法连接数据库");
        }
    }
};

// 场景2：高性能计算 - 可能禁用异常
// 编译时加 -fno-exceptions（但很多标准库会受影响）

// 场景3：嵌入式系统 - 通常不用异常（资源有限）

// 场景4：游戏开发 - 混合使用
// 关键路径用返回码，高层逻辑用异常
```
