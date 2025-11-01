#编程  #Android #XML 



```xml
<item
	android:id="@+id/名字"
	android:title="用于展示的名字" />	
//.....
```



```Java
public boolean onCreateOptionsMenu(Menu menu) {
	getMenuInflater().inflate(R.文件位置(无后缀),menu);
	// 上面这个代码就是给当前活动创建菜单的
	// 第一个参数用于指定我们通过哪个资源目录文件创建菜单
	// 第二个用于指定菜单项
	return true;//return true 表示显示
}

public boolean onOptionsItemSelected(MenuItem item) {
	// 重写菜单响应事件
	switch (item.getItemId()){
		case R.id.名字:
			// 操作
			break;
		case R.id.名字2:
			// 操作
			break;
		default:
	}
	return true ;
}
```