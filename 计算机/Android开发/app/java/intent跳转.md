#Android #编程 #布局 #Java 


#### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">显式跳转</font></div>
```java
Intent intent = new Intent(java文件1.this,java文件2.class);
startActivity(intent);//这个是负责打开活动的代码
```

从java文件1跳转到java文件2
[[布局文件Java]]

弹幕：遇到点击 BUTTON 1闪退的问题, 可以看看activity_second这个文件, <LinearLayout 可能快捷多了

#### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">隐式跳转</font></div>

相比显式跳转，隐式跳跃更加含蓄，并没有明确指定要跳转到哪里，而是指定了一系列更为抽象的action和category的信息
而是交给系统自己去分析要启动哪一个活动，并帮我们找出合适的活动去启动
合适的活动？
简单说：可以响应intent的活动

在xml中的\<application\>中添加如下代码
```xml
<activity android:name=".secondActivity">
    <intent-filter>
        <action android:name="名字"/>
        <category android:name="android.intent.category.DEFAULT" />
    </intent-filter>
</activity>
```
名字：com.example.activitytest.ACTION_START  比较好认
com.示例.活动测试.操作_开始
android.intent.category.DEFAULT指默认...
```java
    Intent intent = new Intent("action中的名字");
    startActivity(intent);
```
可以调用这个来添加一个 category
```java
intent.addCategory("名字");
```
别忘了在对应的位置加上 category

#### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">intent 的更多用法</font></div>

程序和程序间共享，比如你想打开一个网页，只需要调用系统的浏览器即可，不需要自己手搓一个浏览器。

```java
Intent intent = new Intent(Intent.ACTION_VIEW);
intent.setData(Uri.parse("http:www.bilibili.com"));
```
系统拨号
```java
intent.setData(Uri.parse("tel:10086"));
```
别忘了在对应xml中....==(错误,忽略即可。)==
```xml
<data android:tel/>
```
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">9：intent传递数据</font></div>
intent暂存数据，打开另一个活动后再取出即可。

```java
Intent intent = new Intent(java文件1.this,java文件2.class);
intent.putExtra("extra_data",变量名);
startActivity(intent);//这个是负责打开活动的代码
```