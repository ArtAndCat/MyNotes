
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
    
- **`-DarchetypeArtifactId=maven-archetype-quickstart`**  
    指定使用的模板（原型）ID。`maven-archetype-quickstart` 是 Maven 官方提供的简单 Java 项目模板。
    
- **`-DinteractiveMode=false`**  
    关闭交互模式，使用命令行传入的参数一次性生成，不询问任何额外选项。

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