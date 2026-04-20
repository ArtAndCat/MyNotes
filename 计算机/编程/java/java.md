 #Java #编程 #大 




格式：
```java
//这里写类  怎么这里写不了函数和变量（学C++学的）
public class 文件名 {//Java文件中只能有一个public的类
    //在这里写函数和成员变量静态变量
    public static void main(String[] args) {//主函数
        //这里写局部变量和逻辑什么的
        System.out.println("Hello World"); // 输出Hello World
    }
}
```
[访问修饰符](java访问修饰符.md)
[[static 修饰符]]
[[main(String() args)是什么？]]
变量声明方式：
```java
<权限访问修饰符> [一般修饰符] <类型> <名称> [ = 初始值];
```
数组声明方式：
````java
int[][]... 名字 = new int[数字][]..//这啥？？
//int 名字[][]...  也可以但不推荐
````

[[Java黑马教程]]（空的）
### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">生成与执行</font></div>
先跟着教材整环境  部分基础知识这里不会记录  

```sh
javac Main.java # 生成
java Main # 运行
```

我们都知道C++中有Makefile(构建工具) java也没有类似的呢? 有的兄弟 有的
  Java 企业级用的是 **Maven** 或 **Gradle** 作用类似：管理依赖、编译、打包、运行测试。
- [[java Maven构建工具]]   用于后端  补充: [[javaMaven 与 git]]
- [[java Gradle构建工具]]   用于Android 或 Kotlin 项目
 
### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">基础</font></div>


[[java专业术语]]
[[java关键字]]





### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">更多</font></div>

[[Math类]]

[[java与Mysql(准确来说是MariaDB)]] 

[[WEB项目结构]] 
















