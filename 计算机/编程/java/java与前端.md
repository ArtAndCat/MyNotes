
 
在数据库项目基础上  在App.java旁边


记得改你的密码 和数据库的参数什么的

```java
// GameHttpServer.java
package com.example;

import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class GameHttpServer {

    public static void main(String[] args) throws IOException {
        // 1. 创建 HTTP 服务器，监听 8080 端口
        HttpServer server = HttpServer.create(new InetSocketAddress(8080), 0);

        // 2. 把 URL 路径 "/games" 绑定到处理类 GameHandler 上
        server.createContext("/games", new GameHandler());

        // 3. 启动服务器（进入事件循环，类似 SDL 的 while(running)）
        server.start();
        System.out.println("服务器已启动，访问 http://localhost:8080/games 查看数据");
    }

    // 内部类：处理 /games 请求
    static class GameHandler implements HttpHandler {
        // 数据库连接信息（暂时硬编码，后面再抽到配置文件）
        private static final String URL = "jdbc:mysql://localhost:3306/testdb";
        private static final String USER = "root";
        private static final String PASSWORD = "114514"; // 改成你的密码

        @Override
        public void handle(HttpExchange exchange) throws IOException {
            // 4. 设置响应头：允许跨域（方便你用本地 HTML 测试），内容类型为 JSON
            exchange.getResponseHeaders().set("Content-Type", "application/json; charset=utf-8");
            exchange.getResponseHeaders().set("Access-Control-Allow-Origin", "*");

            // 5. 从数据库查询所有游戏数据
            List<String> gameList = new ArrayList<>();
            try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
                 Statement stmt = conn.createStatement();
                 ResultSet rs = stmt.executeQuery("SELECT name, time, date FROM gamesData")) {

                while (rs.next()) {
                    String name = rs.getString("name");
                    double time = rs.getDouble("time");
                    String date = rs.getDate("date").toString();
                    // 拼成 JSON 对象字符串
                    gameList.add(String.format("{\"name\":\"%s\", \"time\":%.2f, \"date\":\"%s\"}",
                                               name, time, date));
                }
            } catch (SQLException e) {
                e.printStackTrace();
                // 返回错误信息
                String error = "{\"error\": \"数据库查询失败\"}";
                exchange.sendResponseHeaders(500, error.getBytes().length);
                try (OutputStream os = exchange.getResponseBody()) {
                    os.write(error.getBytes());
                }
                return;
            }

            // 6. 把 List 拼接成 JSON 数组
            String json = "[" + String.join(",", gameList) + "]";
            byte[] responseBytes = json.getBytes("utf-8");

            // 7. 发送 HTTP 响应（状态码 200，响应体长度）
            exchange.sendResponseHeaders(200, responseBytes.length);
            try (OutputStream os = exchange.getResponseBody()) {
                os.write(responseBytes);
            }
        }
    }
}
```

