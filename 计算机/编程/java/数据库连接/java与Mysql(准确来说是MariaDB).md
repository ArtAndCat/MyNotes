
[[MySQL]] 
打开通过 Maven构建工具 创建的项目 打开pom.xml  

 **添加 MySQL 驱动依赖**：  
    在 `<dependencies>` 标签内加入：
```xml
<dependency>
    <groupId>com.mysql</groupId>
    <artifactId>mysql-connector-j</artifactId>
    <version>8.2.0</version>
</dependency>
```

快速项目:
```java
//src/main/java/com/example/App.java
package com.example;  // 包名，对应目录结构 com/example/App.java

// 导入 JDBC 核心类，都位于 java.sql 包
import java.sql.*;

public class App {
    public static void main(String[] args) {
        // 1. 数据库连接 URL（类似 C++ 里的连接字符串）
        // 格式：jdbc:mysql://主机:端口/数据库名?参数
        // 3306 是 MySQL 默认端口
        String url = "jdbc:mysql://localhost:3306/testdb";
        String user = "root";
        String password = "你的密码";  // 改成你实际设置的 MariaDB root 密码

        // 2. try-with-resources 语法（Java 7+ 特性）
        // 小括号内的资源会在 try 代码块结束后自动调用 close() 方法释放
        // 这解决了 C++ 里容易忘记 delete/free 的问题，也不用手写析构函数
        try (Connection conn = DriverManager.getConnection(url, user, password);  // 建立 TCP 连接，握手认证
             Statement stmt = conn.createStatement();                               // 创建一个 SQL 语句载体
             ResultSet rs = stmt.executeQuery("SELECT * FROM student")) {           // 执行查询，返回结果集（类似迭代器）

            // 3. 遍历结果集
            // rs.next() 将游标移动到下一行，有数据返回 true，否则 false
            while (rs.next()) {
                // 通过列名获取当前行的字段值
                int id = rs.getInt("id");           // 对应数据库 INT 类型
                String name = rs.getString("name"); // 对应 VARCHAR 类型

                System.out.println("ID: " + id + ", Name: " + name);
            }
            // 4. try-with-resources 自动关闭 rs -> stmt -> conn，反序释放资源
        } catch (SQLException e) {
            // 5. 数据库相关异常统一捕获
            e.printStackTrace();  // 打印错误堆栈，便于调试
        }
        // 注意：没有 delete 语句，Java 的 GC 最终会回收这些对象（但 JDBC 资源还是显式关闭为好）
    }
}
```

添加表和数据(如果没有) 
```mysql
CREATE DATABASE testdb;
USE testdb;
CREATE TABLE student(id INT PRIMARY KEY, name VARCHAR(20));
INSERT INTO student VALUES(1, 'ZhangSan');
```


编译+运行
```sh
mvn compile exec:java -Dexec.mainClass="com.example.App"
```

so
```java
// 1. 数据库连接 URL（类似 C++ 里的连接字符串）
// 格式：jdbc:mysql://主机:端口/数据库名?参数
// 3306 是 MySQL 默认端口
String url = "jdbc:mysql://localhost:3306/testdb";
String user = "root";
String password = "114514"; // 改成你实际设置的 MariaDB root 密码
```


