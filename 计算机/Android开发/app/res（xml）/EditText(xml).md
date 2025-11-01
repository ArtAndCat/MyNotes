
```xml
<EditText 
	android:id="@+id/控件id"
	android:layout_width="参数"
	android:layout_height="参数"
	android:hint="点击输入文字"/>
```
参数
- match_parent  和父元素一样
- wrap_content   能刚好包含内容即可


#### java中
在最外面的函数里写
```Java
private EditText 名字;
```

```java
名字 = (EditText) findViewById(R.id.控件id);
```
怎么获取？
```java
String 名字1 = 名字.getText().toString();
```
















