
# 安装
### arch

```sh
sudo pacman -S maven
```


# 生成与运行：
### 1. 用 Maven 快速生成一个项目骨架：

打开一个空的项目目录 
```sh
mvn archetype:generate -DgroupId=com.example -DartifactId=hello-app -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
```
- **`mvn archetype:generate`**  
    Maven 命令，调用 `archetype` 插件的 `generate` 目标（goal），用于根据项目模板生成新项目骨架。
- **`-DgroupId=com.example`**  
    定义项目的 **groupId**，通常为公司/组织域名的倒序，用于唯一标识项目所属组，类似 C++ 命名空间。
- **`-DartifactId=hello-app`**  
    定义项目的 **artifactId**，即项目/模块名，最终生成的 JAR 文件名会以此命名。
- **`-DarchetypeArtifactId=maven-archetype-quickstart`**      更多请看补充内容 [[java Maven构建工具#常用 Archetype 模板速查表]]
    指定使用的模板（原型）ID。`maven-archetype-quickstart` 是 Maven 官方提供的简单 Java 项目模板。
- **`-DinteractiveMode=false`**  
    关闭交互模式，使用命令行传入的参数一次性生成，不询问任何额外选项。

#### 1.2 更多!!  (前期学习建议叠起来)
######  核心定位参数 (基本)

- **`-DgroupId`**：定义项目的组织ID，通常为公司域名的反写（如 `com.yourcompany`），类似于Java中的包命名空间。
- **`-DartifactId`**：定义项目的唯一标识符，生成的JAR包和项目目录都会以此命名。
- **`-Dversion`**：定义项目的初始版本，如 `1.0-SNAPSHOT`。
- **`-Dpackage`**：指定项目源码的根包名。如果省略，默认会使用 `groupId` 的值。

###### 指定模板参数 (模板)

- **`-DarchetypeGroupId`**：指定模板所属的组织ID。若不指定，默认为 `org.apache.maven.archetypes`。
- **`-DarchetypeArtifactId`**：指定要使用的模板ID，如 `maven-archetype-quickstart`。
- **`-DarchetypeVersion`**：指定所用模板的版本。
- **`-DarchetypeCatalog`**：指定查找模板的目录，如 `internal`, `local`, `remote`。
- **`-Dfilter`**：配合`archetypeCatalog`使用，可按关键词过滤并只显示名称匹配的模板列表。

###### 控制与行为参数 (高级)

- **`-DinteractiveMode`**：是否以交互模式运行。设为 `false` 则直接使用提供的参数创建项目，无需等待用户确认。
- **`-DcreateProjectDirectory`**：是否在生成项目时为其创建一个与 `artifactId` 同名的根目录。
- **`-DoutputDirectory`**：指定项目生成的输出路径。
- **`-DremoteRepositories`**：指定用于查找模板的远程Maven仓库地址。
- **`-DupdateSnapshots`**：是否强制更新SNAPSHOT版本的模板。
- **`-Dgenerate`**：是否执行“生成”操作。
- **`-Doverwrite`**：是否允许覆盖已存在的文件。
- **`-Ddebug`**：是否开启调试日志输出。
- **`-DnoTests`**：是否跳过单元测试代码的生成。
- **`-DnoExamples`**：是否跳过示例代码的生成。
- **`-DfailOnMissing`**：如果指定的模板找不到，是否让构建失败。

### 2. 进入生成目录，编译并运行：

```sh
cd hello-app
mvn compile
mvn exec:java -Dexec.mainClass="com.example.App"
```

- **`mvn exec:java`**  
    Maven 命令，调用 `exec-maven-plugin` 插件的 `java` 目标，用于在 Maven 构建生命周期中直接运行某个 Java 类的主方法。
- **`-Dexec.mainClass="com.example.App"`**  
    传递给 `exec` 插件的参数，指定要执行的主类全限定名（包含包路径），此处为 `com.example.App`。

#### 2.2 更多!! (前期学习建议叠起来)
###### 核心定位参数 (基本)

- **`-Dexec.mainClass`**：指定要执行的Java类的完全限定名。
- **`-Dexec.args`**：传递给 `main` 方法的命令行参数，参数之间用空格分隔。
- **`-Dexec.classpathScope`**：指定类路径的范围，例如 `compile`（默认）、`runtime` 或 `test`。

##### 环境与配置参数 (高级)

- **`-Dexec.workingdir`**：指定Java程序执行时的工作目录。
- **`-Dexec.environmentVariables`**：为执行的进程设置环境变量，格式为 `NAME=VALUE`。
- **`-Dexec.systemProperties`**：设置Java系统属性，格式为 `name=value`。
- **`-Dexec.jvmArguments`**：传递额外的参数给JVM，如 `-Xmx1024m`。
- **`-Dexec.includeProjectDependencies`**：是否在类路径中包含项目的编译依赖。
- **`-Dexec.includePluginDependencies`**：是否包含插件的依赖。

###### 进程控制与I/O参数 (高级)

- **`-Dexec.skip`**：是否跳过此次执行。
- **`-Dexec.timeout`**：设置程序执行的超时时间。
- **`-Dexec.standardInput`**：指定标准输入的来源，如 `XMLyes` 或一个文件路径。
- **`-Dexec.standardOutput`**：指定标准输出的重定向文件路径。
- **`-Dexec.standardError`**：指定标准错误输出的重定向文件路径。
- **`-Dexec.failIfExecutableFails`**：如果可执行程序返回了非零的退出码，是否导致Maven构建失败。
- **`-Dexec.successExitCodes`**：指定被视为“成功”的退出码列表。
- **`-Dexec.ignoreExitCode`**：是否忽略程序的退出码。
- **`-Dexec.background`**：是否在后台执行程序。
- **`-Dexec.newProcess`**：是否强制在新进程中执行（对于 `exec:java` 来说，通常默认在当前VM中执行）。
- **`-Dexec.detach`**：是否分离执行（即启动后立即返回，不等待程序结束）。
- **`-Dexec.wait`**：是否等待子进程结束。
- **`-Dexec.killAfter`**：在超时后是否强制终止进程。
### 补充:

这些参数的具体用法和默认值可能会随插件的版本而变化。最准确的信息源始终是 **Maven 插件的官方文档**。
1. **`archetype:generate` 官方文档** [点我](https://maven.apache.org/archetype/maven-archetype-plugin/generate-mojo.html) 可找到最新的参数列表和详细说明。
2. **`exec:java` 官方文档** [点我](https://www.mojohaus.org/exec-maven-plugin/java-mojo.html) 提供了`exec:java`目标最权威的参考。


### 当前项目 `hello-app` 的文件结构解析(补充内容)

```txt
hello-app/
├── pom.xml                # Maven 核心配置文件（依赖、插件、项目信息）
├── src/
│   ├── main/
│   │   ├── java/          # 你的手写 Java 源码放这里（包路径对应子目录）
│   │   │   └── com/example/App.java
│   │   └── resources/     # 配置文件（如 application.properties）、SQL 脚本、图片等
│   └── test/
│       ├── java/          # 单元测试代码放这里（与 main 同包结构）
│       └── resources/     # 测试专用资源
└── target/                # 编译输出目录（mvn compile 后生成，可随时删除）
    ├── classes/           # 编译后的 .class 文件
    └── ...
```

### 不同参数（archetype）构建的项目区别(补充内容)

|参数 `-DarchetypeArtifactId` 值|生成内容|适用场景|
|---|---|---|
|`maven-archetype-quickstart`|基础 Java 项目（就是你现在这个）|练手、纯 Java SE 程序|
|`maven-archetype-webapp`|包含 `src/main/webapp` 和 `WEB-INF/web.xml`|传统 Servlet/JSP 项目（较老）|
|`spring-boot-starter-parent` 系列|内置 Spring Boot 启动类与配置|现代企业后端主流|

**核心结论**：无论哪个 archetype，**`src/main/java`、`src/main/resources`、`src/test/java` 这三者关系是永恒不变的**。企业项目只是在 `pom.xml` 里多了一堆依赖和插件而已。

### 更详细的项目结构(补充内容)
#### 结构一：单体应用结构（你接下来最可能遇到）

这是企业中小型项目、或你合作方给一个"简单后端服务"时最常见的结构。它在 Maven 标准目录布局的基础上，增加了代码分层的概念。

**本质：Maven 标准布局 + Spring Boot 分层**

Maven 的标准目录是所有 Java 项目的基石，你现在的 `hello-app` 已经遵循了这套约定，所以 Maven 才能自动找到源码和资源去编译[](https://maven.apache.org/guides/introduction/introduction-to-the-standard-directory-layout.html?from_column=20423&from=20423)[](https://m.yisu.com/zixun/1050485.html)。

在此基础上，企业项目会在 `src/main/java` 下的包内，按**职责**进一步分层[](https://developer.aliyun.com/article/1667821)[](https://blog.csdn.net/flyingcloude/article/details/155021945)：
```txt
project-root/                     # 企业项目根目录
├── pom.xml                       # Maven配置文件
├── src/
│   ├── main/
│   │   ├── java/
│   │   │   └── com/
│   │   │       └── company/      # 公司域名倒写
│   │   │           └── project/  # 项目名
│   │   │               ├── Application.java    # 启动类（放根包下，才能自动扫描子包）
│   │   │               ├── controller/         # 控制层：接收HTTP请求
│   │   │               │   └── UserController.java
│   │   │               ├── service/            # 业务层：核心业务逻辑
│   │   │               │   ├── UserService.java        # 接口
│   │   │               │   └── impl/
│   │   │               │       └── UserServiceImpl.java # 实现
│   │   │               ├── mapper/             # 持久层：数据库操作（也叫dao）
│   │   │               │   └── UserMapper.java
│   │   │               ├── entity/             # 实体层：数据库表映射对象
│   │   │               │   └── User.java
│   │   │               ├── dto/                # 数据传输对象：前端交互专用
│   │   │               ├── config/             # 配置类
│   │   │               └── util/               # 工具类
│   │   └── resources/
│   │       ├── application.yml                 # Spring Boot主配置
│   │       ├── static/                         # 静态资源（CSS/JS/图片）
│   │       └── mapper/                         # MyBatis SQL映射文件
│   └── test/                                   # 单元测试（与main结构镜像）
└── target/                                     # 编译输出（不提交Git）
```

**核心分层职责速查表**：

|层级|注解|职责|
|---|---|---|
|`controller/`|`@RestController`|接收 HTTP 请求，参数校验，返回 JSON|
|`service/`|`@Service`|业务逻辑编排，事务控制（`@Transactional`）|
|`mapper/`|`@Mapper`|数据库 CRUD 操作（MyBatis 常用）|
|`entity/`|`@Entity` 或 POJO|与数据库表一一对应的 Java 对象|
|`dto/`|无（POJO）|前端传参、后端返回的专用对象，避免直接暴露 entity|

这种结构各司其职，改数据库只动 `mapper` 和 `entity`，改业务逻辑只动 `service`，改接口只动 `controller`，边界清晰。

---

#### 结构二：Maven 多模块结构（中大型项目标准）

当项目规模变大，单模块会让代码膨胀、构建变慢。企业会把项目拆成多个 **Maven 模块（Module）**，每个模块独立编译打包，之间通过依赖关联。

**典型的多模块结构**：

```txt
parent-project/                   # 父项目（只包含 pom.xml，无代码）
├── pom.xml                       # 父 POM：统一管理版本、插件、子模块列表
├── common/                       # 公共模块：工具类、常量、异常、统一返回格式
├── entity/                       # 实体模块：数据库表对应的 Java 对象（可选）
├── mapper/                       # 持久层模块：数据库操作接口
├── service/                      # 业务层模块：核心业务逻辑
├── api/                          # 接口定义模块：DTO 和 Feign 接口（微服务用）
└── web/                          # Web 层模块：Controller + 启动类
```

**模块依赖关系**（只能"向下"依赖）[](https://juejin.cn/post/7544841261800374322)[](https://www.javacodegeeks.com/2025/06/multimodule-spring-boot-projects-with-maven-gradle-best-practices.html)：

```txt
web → service → mapper → entity → common
  ↘       ↘        ↘        ↘
   └──────┴────────┴────────┘  (所有模块都可以依赖 common)
```

**父 POM 的关键配置**[](https://www.javacodegeeks.com/2025/06/multimodule-spring-boot-projects-with-maven-gradle-best-practices.html)：

```txt
<groupId>com.company</groupId>
<artifactId>parent-project</artifactId>
<version>1.0.0</version>
<packaging>pom</packaging>   <!-- 父项目必须是 pom -->
<modules>
    <module>common</module>
    <module>entity</module>
    <module>mapper</module>
    <module>service</module>
    <module>web</module>
</modules>
```

**好处**：

- 代码复用：`common` 模块被所有模块共享
- 构建加速：改 `web` 模块只编译 `web`，不动其他模块
- 团队并行：不同小组负责不同模块，互不干扰
- 依赖清晰：强制单向依赖，不会出现循环引用

**你接下来遇到的企业项目，大概率就是这种结构**——一个父项目下挂着多个模块，你会被分配做其中某个模块的功能。

---

#### 结构三：微服务架构结构（大型分布式系统）

微服务本质是**多个独立的多模块项目**，每个微服务都是一个独立的 Spring Boot 应用，有自己的数据库和配置，服务之间通过 HTTP/RPC 通信[](https://www.codefather.cn/post/2006181509941227522)。

```txt
microservice-platform/
├── service-gateway/              # 网关服务（路由、鉴权、限流）
├── service-user/                 # 用户服务（独立的多模块项目）
├── service-order/                # 订单服务（独立的多模块项目）
├── service-product/              # 商品服务（独立的多模块项目）
└── common-starters/              # 共享 Starter（安全、日志、缓存等）
    ├── common-security-starter/
    ├── common-log-starter/
    └── common-cache-starter/
```

每个服务内部，可能又是一个"结构二"那样的多模块项目。你目前不需要深入这个层级，但知道"微服务 = 多个独立项目的集合"即可。

---

### 各企业结构为什么会有差异？

虽然"标准布局 + 分层"是共识，但具体到不同企业会有这些差异[](https://www.w3cschool.cn/alibaba_java/)：

1. **包命名规范**：有的要求 `com.company.project.module`，有的直接用 `com.company.module`
    
2. **分层粒度**：有的会拆分出 `manager/` 层（通用业务处理）、`integration/` 层（外部服务调用）
    
3. **模块划分方式**：有的按技术层分（common/mapper/service/web），有的按业务域分（user/order/product），各有利弊
    
4. **配置文件组织**：有的用 `application.yml`，有的用 `application.properties`，有的按环境拆分（`application-dev.yml`）
    

阿里《Java 开发手册》专门有一个"工程结构"章节规范这些，很多企业会以此为蓝本制定自己的规范。

---

### 对你的实用建议

你当前还在"先学 Java 基础"阶段，**结构一（单体分层）是你接下来最可能在企业项目中遇到的形态**。建议先把这个结构跑通，理解各层的职责和调用关系。



# 笔记补充内容

## 
### 常用 Archetype 模板速查表

| 参数 `-DarchetypeArtifactId` 值    | 生成内容                                     | 适用场景                  |
| ------------------------------- | ---------------------------------------- | --------------------- |
| `maven-archetype-quickstart`    | 基础 Java 项目（就是你现在这个）                      | 练手、纯 Java SE 程序       |
| `maven-archetype-webapp`        | 包含 `src/main/webapp` 和 `WEB-INF/web.xml` | 传统 Servlet/JSP 项目（较老） |
| `spring-boot-starter-parent` 系列 | ==内置 Spring Boot 启动类与配置==                | 现代企业后端主流              |

#### 基础模板

- **`maven-archetype-quickstart`**
    
    - **用途**：生成一个最简单的标准 Java 项目（JAR）[](https://cloud.tencent.com.cn/developer/article/1773579?from=15425)。
        
    - **何时使用**：开发一个Java库、命令行工具，或者任何不需要Web容器的Java应用[](https://cloud.tencent.com.cn/developer/article/1704358?from=15425)。
        
    - **⭐ 对你的意义**：这是我们之前创建 `hello-app` 时用的，你现在**99%的情况都会用它**来练习或开发工具。
        

#### Web开发模板

- **`maven-archetype-webapp`**
    
    - **用途**：生成一个基础的Java Web应用程序项目（WAR）[](https://cloud.tencent.com.cn/developer/article/1773579?from=15425)[](https://maven.apache.org/archetypes/index.html)。
        
    - **何时使用**：创建传统的、需要部署到Tomcat等Web容器的Java Web项目（如Servlet/JSP应用）[](https://cloud.tencent.com.cn/developer/article/1704358?from=15425)。
        
    - **对你的意义**：如果你想学传统的 Java Web 开发（Servlet/JSP），可以从这里开始。但请注意，现代后端开发更多使用 Spring Boot 这类嵌入式框架，其项目结构与此有所不同。
        

#### 其他模板

- **`maven-archetype-plugin`**
    
    - **用途**：生成一个示例 Maven 插件项目[](https://maven.apache.org/archetypes/index.html)。
        
    - **何时使用**：当你需要开发自定义的 Maven 插件以扩展其功能时。
        
    - **对你的意义**：目前用不上，这是开发 Maven 自身工具时用的。
        
- **`maven-archetype-site`**
    
    - **用途**：生成一个示例 Maven 项目站点[](https://maven.apache.org/archetypes/index.html)。
        
    - **何时使用**：为你的项目生成一个包含文档、报告等信息的标准网站。
        
    - **对你的意义**：目前用不上，等你需要为项目写正式文档时再考虑。
        

> **补充说明**：Maven官方提供的Archetype模板还有许多，如用于生成EJB、Portlet等特定技术栈的[](https://maven.apache.org/archetypes/index.html)。但对于入门和一般后端开发，上述几种已基本够用。

#### 如何使用与发现模板

- **如何指定**：使用命令 `mvn archetype:generate -DarchetypeArtifactId=maven-archetype-quickstart`[](https://cloud.tencent.com.cn/developer/article/1773579?from=15425)。如果省略此参数，默认使用的就是 `maven-archetype-quickstart`[](https://maven.org.cn/plugins-archives/maven-archetype-plugin-1.0-alpha-7/usage.html)[](https://www.sonatype.com/maven-complete-reference/using-maven-archetypes)。
    
- **如何发现更多模板**：
    
    1. **最简单的方法**：只运行 `mvn archetype:generate`，Maven 会进入**交互模式**，列出大量可用模板，你只需输入编号来选择[](https://www.sonatype.com/maven-complete-reference/using-maven-archetypes)。
        
    2. **主动查询**：你可以访问 [Maven 官方 Archetype 目录](https://maven.apache.org/archetypes/index.html) 查看完整的官方列表[](https://cloud.tencent.com.cn/developer/article/1704358?from=15425)。此外，许多第三方框架（如 Spring、Vaadin等）也提供自己的 `archetypeArtifactId`，用于快速生成特定框架的项目脚手架。


###
###
###