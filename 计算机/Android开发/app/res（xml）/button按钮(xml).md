#编程 #Android  #XML 
写到xml中
````xml
<Button
	android:id = "@+id/按钮id"
    android:layout_width = "参数_大小"
    android:layout_height = "参数_大小"
    android:text="用于显示的文字"/>

````
参数_大小：
- match_parent  和父元素一样
- wrap_content   能刚好包含内容即可
更多：

- [[控件宽和高_xml]]
- [[对齐方式_xml]]
- 
#### java文件中
创建一个监听器
```java
Button button = (Button) findViewById(R.id.按钮id);
button.setOnClickListener({
	@Override
	public void onClick(View v){
		代码
	}
});
```
如果你不想这么写的话你可以使用接口来实现
在最外面的函数头的对应位置加上
```java
implements View.OnClickListener 
```
里面改成
```java
Button button = (Button) findViewById(R.id.按钮id);
button.setOnClickListener(this);
```
然后
```java
public void onClick(View v){
	switch (v.getId()){
		case R.id.按钮id:
			//这里写逻辑
			
		break;
	}
}
```
#### 更多

```

```










