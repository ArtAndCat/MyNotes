#编程 #大 #Android #Java #XML 
你需要会的：
[[计算机/编程/xml/xml]]  不会？HTML晓得不？和HTML差不多
[[计算机/编程/java/java]]

【（学完必会）Android studio基础，从入门到精通，学完小白也能会-哔哩哔哩】 https://b23.tv/a04pD9o


## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">1：第一个应用，helloWorld</font></div>
创建文件，创建模拟器，
2：30一一讲解项目文件
[[Android开发.]]
## 2：log的使用===============
[[log.__();]]
## 3：自己创建activity===========

1：26 <[Button](button按钮(xml).md)>按钮的创建
## 4：Toast==================
Android提供的一个非常好的一个提醒方式
[[toast(java)]]
```Java
Toast.makeText(MainActivity.this, "要提示的内容", Toast.LENGTH_LONG).show();
```
## 5：下拉菜单================
新建menu文件夹并且在里面新建一个main.xml文件

![[item(xml)]]
[[按钮的触发]]  Java代码

## 6：显式intent跳转
先在main\/Java.....中创建一个活动

![[intent跳转#_ _ _ _<div style="width 100%;height 30px;background-color rgb(40,40,70);text-align center;"><font style="font-size 20px">显式跳转</font></div>]]

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">7：隐式Intent跳转</font></div>
相比显式跳转，隐式跳跃更加含蓄，并没有明确指定要跳转到哪里，而是指定了一系列更为抽象的action和category的信息
而是交给系统自己去分析要启动哪一个活动，并帮我们找出合适的活动去启动
合适的活动？
简单说：可以响应intent的活动
![[intent跳转#_ _ _ _<div style="width 100%;height 30px;background-color rgb(40,40,70);text-align center;"><font style="font-size 20px">隐式跳转</font></div>]]

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">8：intent更多用法</font></div>

程序和程序间共享，比如你想打开一个网页，只需要调用系统的浏览器即可，不需要自己手搓一个浏览器。
![[intent跳转#_ _ _ _<div style="width 100%;height 30px;background-color rgb(40,40,70);text-align center;"><font style="font-size 20px">intent 的更多用法</font></div>]]

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">9：intent传递数据</font></div>
intent暂存数据，打开另一个活动后再取出即可。

![[intent跳转#_ _ _ _<div style="width 100%;height 30px;background-color rgb(40,40,70);"><font style="font-size 20px">9：intent传递数据</font></div>]]




## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">10：TextView</font></div>

用于在界面中显示文本信息

[[TextView(xml)]]


## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">11：Button</font></div>
[[button按钮(xml)]]



## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">12：EditText 文本输入</font></div>

[[EditText(xml)]]



## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">13：image图片显示</font></div>

[[ImageView(xml)]]




## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">14：圆圈加载</font></div>

[[ProgressBar(xml)]]


```java
if(imageView.getVisibility()!=View.GONE){
    Toast.makeText(MainActivity.this, "已隐藏图片", Toast.LENGTH_LONG).show();
    imageView.setVisibility(View.GONE);  // 隐藏
}else{
    Toast.makeText(MainActivity.this, "已显示图片", Toast.LENGTH_LONG).show();
    imageView.setVisibility(View.VISIBLE);
}
```
获取当前进度（）
```java
int getProgress(NULL);
```

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">15：在原来的界面上再显示一个对话框</font></div>
比如“删除确认”

```java
AlertDialog.Builder dialog = new AlertDialog.Builder(MainActivity.this);
dialog.setTitle("这是个弹窗");
dialog.setMessage("字面意思");
dialog.setCancelable(false);// 表示“不能通过返回取消”
dialog.setPositiveButton("OK",new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog,int which){
         
        
    }
});
dialog.show();
```




## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">16：和上面一样，但多一个进度条</font></div>

弹幕：ProgressDialog 好像被弃用了，使用Dialog代替

```java
Dialog.Builder dialog = new Dialog.Builder(MainActivity.this);
dialog.setTitle("这是个弹窗");
dialog.setMessage("字面意思");
dialog.setCancelable(true);// 表示“可以通过返回取消”
dialog.setPositiveButton("OK",new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog,int which){
         
        
    }
});
dialog.setNeutralButton("啊？",new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog,int which){
        
    }
})
dialog.show();
```
记得调用dismess方法，否则对话框将一直存在
```java
final EditText input = new EditText(context);
dialog2.setView(input);

dialog2.setTitle("输入标题");
dialog2.setMessage("请输入一些文字");

dialog2.setPositiveButton("确定", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which) {
        String userInput = input.getText().toString();
        // 在这里处理用户输入的文字
    }
});

dialog2.setNegativeButton("取消", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which) {
        dialog.cancel();
    }
});

dialog2.show();
```
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">17：线性布局</font></div>
[[LinearLayout线性布局(xml)]]
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">18：相对布局</font></div>
[[RelativeLayout相对布局(xml)]]
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">19：线性布局</font></div>
[[ConstraintLayout约束布局(xml)]]
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">20：自定义布局（增强代码复用性）</font></div>
改一下布局的宽高（把与父级一样改成能包括即可）
然后还得改values中的themes.xml文件(错误+看不懂，暂时不改了)
```xml
<include layout="@src文件下的xml文件:不带后缀"/>
```
隐藏系统标题栏：
在Java文件的对应位置加上这个代码
```Java
ActionBar ac = getActionBar();
        if(ac != null){
            ac.hide();
            
        }
```
更多用法：==啊啊啊怎么又是个坑啊啊==

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">21：ListView无限滚动布局</font></div>
[[ListView无限滚动布局(xml)]]





## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">22：定制ListView</font></div>

###### 创建一个Java类文件
```java
package com.artwork.xmltest;


/**
 * @Author 艺术.artwork
 * @Date 2024/07/19 16:18
 */
public class F {//类名
    private String name;
    private int imageId;
    public        F(String name,int imageId){//构造函数
        this.name    = name;
        this.imageId = imageId;
    }
    public String getName()    {
        return name;
        
    }
    public int    getImageId() {
        return imageId;
    }
}
```
###### 创建xml文件
```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent">
    <ImageView 
        android:id="@+id/F_image"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:src="@drawable/loding"
        />
    <TextView
        android:id="@+id/F_TextView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:gravity="center_vertical"
        android:layout_marginLeft="10dp"/>  
</LinearLayout>
```
##### 自定义适配器
```Java
package com.artwork.xmltest;
import android.widget.ArrayAdapter;
import android.content.Context;
import java.util.List;
import android.view.ViewGroup;
import android.view.View;
import android.view.LayoutInflater;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * @Author 艺术.artwork
 * @Date 2024/07/19 16:51
 */
public class FAdapter extends ArrayAdapter<F>{
    private int resourceId;
    public FAdapter(Context context,
                    int textViewResourceId,
                    List<F> object
                   ){
        super(context,textViewResourceId,object);
        resourceId = textViewResourceId;
    }
    public View getView(int position,View coverView, ViewGroup parent){
        F f = getItem(position);
        View view = LayoutInflater.from(getContext()).inflate(resourceId,parent,false);
        ImageView fI = (ImageView) view.findViewById(R.id.F_image);
        TextView fN = (TextView) view.findViewById(R.id.F_TextView);
        fI.setImageResource(f.getImageId());
        fN.setText(f.getName());
        return view;
    }
    
}
```
###### java文件的修改
```Java
private List<F> fL = new ArrayList<F>();
```

```Java
initFruits();// 初始化水果数据
FAdapter adapter = new FAdapter(MainActivity.this,R.layout.fruit_item,fL);
ListView listView = (ListView) findViewById(R.id.list_view_testListView);
listView.setAdapter(adapter);
```

```Java
private void initFruits() {
    for (int i=0;i<3;i++){
        F a1 = new F("律师函.txt",R.drawable.a01);
        fL.add(a1);
        F a2 = new F("焊脸上的笑脸",R.drawable.a02);
        fL.add(a2);
        F a3 = new F("电车",R.drawable.a03);
        fL.add(a3);
        F a4 = new F("万物之源",R.drawable.a04);
        fL.add(a4);
        F a5 = new F("结果",R.drawable.a5);
        fL.add(a5);
        F a6 = new F("工作必备",R.drawable.a06);
        fL.add(a6);
        F a7 = new F("棒槌",R.drawable.a07);
        fL.add(a7);
        F a8 = new F("送给所有有对象的人",R.drawable.a08);
        fL.add(a8);
        F a9 = new F("eatable",R.drawable.a09);
        fL.add(a9);
    }
}
```

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">23：响应</font></div>

```Java
listView.setOnItemClickListener(new AdapterView.OnItemClickListener(){
    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        F f = fL.get(position); Toast.makeText(MainActivity.this,f.getName(),Toast.LENGTH_SHORT).show();
    }
});
```






## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">24和25：广播接收器</font></div>
<font style="color:rgb(50,200,230)">两种注册方法：</font>
- 动态注册   代码中  程序
- 静态注册   AndroidManifest.xml中

### 动态注册   代码中
新建一个类，然后继承Board test为例。，并且重写父类中的bbb
```Java
private IntentFilter intentFilter ;//声明实例
private NetworkChangeReceiver networkChangeReceiver;//声明实例
```
MainActivity
```Java
intentFilter = new IntentFilter();//创建实例
intentFilter.addAction("android.net.conn.CONNECTIVITY_CHANGE");//添加一个值，当网络发生变化时，系统就会发送这个值

networkChangeReceiver = new NetworkChangeReceiver();//创建实例
registerReceiver(networkChangeReceiver,intentFilter);//进行注册
```
主函数下面
```Java
// 动态注册的广播接收器都需要取消注册才行，所以就有了这个函数
protected void onDestroy() {
    super.onDestroy();
    unregisterReceiver(networkChangeReceiver);//销毁
}
// 像一开始说的“创建，继承，重写。”
class NetworkChangeReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        Toast.makeText(context,"网络断开",Toast.LENGTH_SHORT).show();
    }
}
```



### 静态注册   AndroidManifest.xml中
开机的广播来调用？？？还能这么玩！？?
```xml
<uses-permission
        android:name="android.permission.RECEIVE_BOOT_COMPLETED" />
```
xml中的application中
```xml
<receiver
    android:name=".BootCompleteReceicer"
    android:enabled="true"
    android:exported="true">
    <intent-filter>
        <action android:name="android.intent.action.BOOT_COMPLETED"/>
    </intent-filter>
</receiver>
```
在Java文件夹里创建个新的文件  BootCompleteReceiver.java
```java
package com.artwork.application;

import android.content.Intent;
import android.content.Context;
import android.content.BroadcastReceiver;
public class BootCompleteReceiver extends BroadcastReceiver{
    @Override
    public void onReceive(Context context, Intent intent){
        
    }
}
```
### 补充：
<font style="color:rgb(250,100,100)">记得申请权限，否则程序直接崩溃！</font>
[[android_权限申请_xml]]
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">17：线性布局</font></div>













