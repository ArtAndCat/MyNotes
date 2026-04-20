



代码结构
```java
// ---------- main 类（只做初始化）----------
public class WebApp {
    public static void main(String[] args) {
        // 1. 加载配置（db.properties）
        // 2. 初始化连接池（HikariDataSource）
        // 3. 创建业务对象（GameService），把连接池传进去
        // 4. 启动 HTTP 服务器，把业务对象绑定到 URL 路径上
        // 5. 服务器进入事件循环，阻塞 main 线程
    }
}

// ---------- 业务逻辑类（每个请求调用一次）----------
public class GameService {
    private final HikariDataSource dataSource;  // 从构造器传入

    public List<Game> getAllGames() {
        try (Connection conn = dataSource.getConnection()) {  // 借连接
            // 执行查询，返回结果
        }  // 自动归还连接
    }
}
```




---

## 一、命令行程序的结构（你当前的代码）

**特点**：
- 程序入口 `main` 方法直接驱动整个流程
- 所有逻辑线性执行，执行完进程退出
- 资源（如数据库连接）在需要时创建，用完关闭

**文件结构**：


```txt
hello-app/
├── pom.xml
└── src/
    └── main/
        └── java/
            └── com/
                └── example/
                    └── App.java          # 所有逻辑都在这一个文件里
```

**代码骨架**（简化版）：

```java
public class App {
    public static void main(String[] args) {
        // 1. 初始化资源（数据库连接等）
        // 2. 读取用户输入（Scanner）
        // 3. 处理业务逻辑（访问数据库）
        // 4. 输出结果（System.out）
        // 5. 进程结束，资源由 OS 回收
    }
}
```

---

## 二、Web 程序的基本结构（原生 HttpServer 版本）

**核心变化**：

- `main` 只负责启动 HTTP 服务器并绑定路由
- 业务逻辑抽取到独立的类中（如 `GameService`）
- 每个 HTTP 请求触发一次业务方法调用
- 数据库连接通过连接池管理（常驻内存）
- 
**文件结构**：

```txt
hello-web/
├── pom.xml
└── src/
    └── main/
        ├── java/
        │   └── com/
        │       └── example/
        │           ├── WebApp.java         # 入口，启动服务器
        │           ├── GameService.java    # 业务逻辑（数据库操作）
        │           └── model/
        │               └── Game.java       # 数据模型类（POJO）
        └── resources/
            └── db.properties               # 数据库配置文件

```
**代码骨架**：

### 1. 数据模型类 `Game.java`

java

package com.example.model;
import java.time.LocalDate;
public class Game {
    private String name;
    private double time;
    private LocalDate date;
    // 构造器、getter、setter 略
}

### 2. 业务逻辑类 `GameService.java`


```java
package com.example;
import com.example.model.Game;
import javax.sql.DataSource;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
public class GameService {
    private final DataSource dataSource;  // 连接池
    public GameService(DataSource dataSource) {
        this.dataSource = dataSource;
    }
    public List<Game> getAllGames() throws SQLException {
        List<Game> games = new ArrayList<>();
        String sql = "SELECT name, time, date FROM gamesData";
        try (Connection conn = dataSource.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
            while (rs.next()) {
                Game g = new Game();
                g.setName(rs.getString("name"));
                g.setTime(rs.getDouble("time"));
                g.setDate(rs.getDate("date").toLocalDate());
                games.add(g);
            }
        }
        return games;
    }
    // 其他方法：addGame, updateGame, deleteGame...
}
```
### 3. 入口类 `WebApp.java`（启动 HTTP 服务器）


```java
package com.example;
import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;
import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;
import java.io.*;
import java.net.InetSocketAddress;
import java.nio.charset.StandardCharsets;
public class WebApp {
    public static void main(String[] args) throws IOException {
        // 1. 初始化连接池
        HikariConfig config = new HikariConfig("/db.properties");
        DataSource dataSource = new HikariDataSource(config);
        // 2. 创建业务对象
        GameService gameService = new GameService(dataSource);
        // 3. 创建 HTTP 服务器，监听 8080 端口
        HttpServer server = HttpServer.create(new InetSocketAddress(8080), 0);
        
        // 4. 绑定路由：/games -> 处理函数
        server.createContext("/games", exchange -> {
            // 处理 GET 请求，返回 JSON 格式的游戏列表
            if ("GET".equals(exchange.getRequestMethod())) {
                try {
                    List<Game> games = gameService.getAllGames();
                    String json = convertToJson(games); // 你需要实现一个简单的 JSON 转换
                    exchange.getResponseHeaders().set("Content-Type", "application/json; charset=UTF-8");
                    exchange.sendResponseHeaders(200, json.getBytes(StandardCharsets.UTF_8).length);
                    try (OutputStream os = exchange.getResponseBody()) {
                        os.write(json.getBytes(StandardCharsets.UTF_8));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    exchange.sendResponseHeaders(500, -1);
                }
            } else {
                exchange.sendResponseHeaders(405, -1); // Method Not Allowed
            }
        });
        // 5. 启动服务器
        server.start();
        System.out.println("服务器已启动，访问 http://localhost:8080/games");
    }
}
```
**注意**：原生 `HttpServer` 中 JSON 转换需手写或引入 `com.fasterxml.jackson` 库。后面会讲变种。

---

## 三、常见变种：引入 JSON 库和框架

### 变种 1：使用 Jackson 处理 JSON

在 `pom.xml` 添加：


```
<dependency>
    <groupId>com.fasterxml.jackson.core</groupId>
    <artifactId>jackson-databind</artifactId>
    <version>2.17.0</version>
</dependency>
```

然后在 `WebApp` 中：


```java
import com.fasterxml.jackson.databind.ObjectMapper;
ObjectMapper mapper = new ObjectMapper();
String json = mapper.writeValueAsString(games);
```
### 变种 2：使用 Spring Boot（企业标准）

**文件结构**：
```txt
spring-game/
├── pom.xml
└── src/
    └── main/
        ├── java/
        │   └── com/
        │       └── example/
        │           ├── Application.java       # Spring Boot 启动类
        │           ├── controller/
        │           │   └── GameController.java
        │           ├── service/
        │           │   └── GameService.java
        │           ├── mapper/                # 如果用 MyBatis
        │           └── model/
        │               └── Game.java
        └── resources/
            ├── application.properties         # Spring Boot 配置
            └── db.properties                  # 可选，也可以直接写在 application.properties
```

**核心代码片段**：

`GameController.java`：

```java
@RestController
@RequestMapping("/games")
public class GameController {
    @Autowired
    private GameService gameService;
    @GetMapping
    public List<Game> getAllGames() {
        return gameService.getAllGames();
    }
    @PostMapping
    public void addGame(@RequestBody Game game) {
        gameService.addGame(game);
    }
}
```
**Spring Boot 的优势**：
- 自动 JSON 转换（Jackson 集成）
- 自动参数绑定（`@RequestBody`）
- 内嵌 Tomcat 服务器，无需手动启动 `HttpServer`
- 依赖注入（`@Autowired`）自动管理对象创建

---

## 四、关键设计原则（防屎山）

|原则|说明|反例|
|---|---|---|
|**单一职责**|一个类只做一件事。`GameService` 只处理业务逻辑，不处理 HTTP 细节。|在 `main` 里写 SQL。|
|**依赖注入**|对象所需的依赖（如 `DataSource`）通过构造器传入，而不是内部 `new`。|`GameService` 里 `new HikariDataSource()`。|
|**面向接口编程**|使用 `DataSource` 接口类型声明变量，而不是具体实现类。便于切换连接池。|`HikariDataSource dataSource = new HikariDataSource()`（虽然也能工作，但不够灵活）。|
|**分层架构**|表现层（Controller）→ 业务层（Service）→ 数据层（DAO/Repository）|在 Controller 里直接写 JDBC 代码。|

---

## 五、总结：从命令行到 Web 的思维转换表

|命令行程序|Web 程序|
|---|---|
|程序执行一次即退出|服务器持续运行，处理多个请求|
|输入来自 `System.in`|输入来自 HTTP 请求参数/请求体|
|输出到 `System.out`|输出 HTTP 响应体（JSON/HTML）|
|资源在方法内创建销毁|资源（连接池）在启动时初始化，全局共享|
|线性流程|事件驱动（请求到达时调用对应方法）|
|单线程|多线程并发处理请求|

---

这些内容你可以整理成笔记。当你需要进一步深入某个变种（比如 Spring Boot 详细配置、MyBatis 整合）时，我们再展开。