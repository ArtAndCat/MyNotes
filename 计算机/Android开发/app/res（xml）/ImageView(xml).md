

```xml
<ImageView 
	android:id="@+id/控件id"
	android:layout_width="参数"
	android:layout_height="参数"
	android:src="文件路径"/>
```
参数
- match_parent  和父元素一样
- wrap_content   能刚好包含内容即

文件路径：
比如文件在`...main/res/drawable/test/cat.png`
`android:src="@drawable/test/cat" `
然后他报错了...为啥不能创建文件夹啊？？
把文件移动到`...main/res/drawable/cat.png`
`android:src="@drawable/cat" `

然后在类内声明全局变量
```java
private ImageView imageView;
```


```java
imageView = (ImageView) findViewById(R.id.image_view);//这个代码的意思好像是绑定ID
```
更改图片样式
```java
imageView.setImageResource(R.drawable.图片);
```