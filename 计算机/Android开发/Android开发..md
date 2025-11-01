#编程 #大 #Android #Java #XML 
你需要学会
[[计算机/编程/java/java]]
[[计算机/编程/xml/xml]]
其他涉及：
[[JNI]]





[[Android课程]]  入门
[[小部件]]

app   开发时主要修改的文件夹
    -- build
    -- libs  第三方架包
    -- src   
        androidText 用于编写测试用例 自动化测试
            a
                java 
                    ...
        main
            java 放置所有java的地方
                [[MainActivity.java]]
                [[布局文件Java]]
            res  资源目录 布局 图片 字符 字符串
                layout（xml布局文件）
                     [[布局文件xml]]
            [[Androidmanifest.xml]]  第一运行文件
        test  自动化测试
    .gitignore    排除版本控制之外
    build.gradle  app构建脚本什么的
    proguard-rules.pro  代码的混淆规则

.xml文件：
```xml
<?xml version="1.0" encoding="utf-8"?>
<!-- 这里写各种控件 记得先写布局 -->
```
控件类
[[button按钮(xml)]]  按钮
[[TextView(xml)]]  文字显示
[[EditText(xml)]]   文本输入
[[ImageView(xml)]]  显示图片
[[ProgressBar(xml)]]  加载
[[item(xml)]]    下拉菜单


布局类
[[LinearLayout线性布局(xml)]]  线性布局
[[RelativeLayout相对布局(xml)]]  相对布局
[[ConstraintLayout约束布局(xml)]] 约束布局

[[ListView无限滚动布局(xml)]]

参数：
[[控件宽和高_xml]]
[[屏幕方向_xml_]]
[[排序方式_xml_]]
[[布局对齐方式_xml]]
[[对齐方式_xml]]


java：
```Java
public class 文件名 extends AppCompatActivity {
	@Override //这个表示“重写代码”（应该）
	protected void onCreate(Bundle savedInstanceState) {
		@Override //这个表示“重写创建时”的代码（应该）
		
	}
	//位置b
}
```
[[log.__();]] 
[[toast(java)]] 
[[intent跳转]]
[[显示一个对话框]]

对象：




方法：










```
@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);

    // 请求没有标题的窗口
    requestWindowFeature(Window.FEATURE_NO_TITLE);

    // 设置窗口为全屏
    getWindow().setFlags(
        WindowManager.LayoutParams.FLAG_FULLSCREEN,
        WindowManager.LayoutParams.FLAG_FULLSCREEN
    );

    // 设置内容视图
    setContentView(R.layout.activity_main);
}
```