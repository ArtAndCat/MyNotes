#菜单 #HTML #CSS #JavaScript #大 #编程





[[在HTML中展示XML]]

### [[计算机/编程/HTML/HTML]]
### [[计算机/编程/HTML/CSS]]
### [[JavaScript（小贾）]] [[计算机/编程/HTML/JavaScript]]  [[JavaScript教程]]   外部笔记 [[计算机/外部笔记/notes-master 1/Frontend/Javascript|Javascript]]

网站三件套啦~还有什么可说的~？
[[404什么的]]
### HTML格式：

```html
<!DOCTYPE html>

<html>
    <head>
        <meta charset="utf-8"><!--中文一定要用UTF-8-->
        <!-- 下面这行负责移动端适配 -->
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>文档标题</title>
        <!-- 在这里声明css文件位置 -->
        <link rel="stylesheet" type="text/css" href="mystyle.css" />
        <style>
            /* CSS的代码写这里 */
            p{
                color:blue;
            }
        </style>
		<script>
			/* JavaScript的代码写这里 */
			
		</script>
        
    </head>
    
    <body>
        <!-- 主布局（顺便怎么叫吧...）-->
        <p>hello wold</p>
    </body>
    
</html>
```
###  .CSS文件格式
css文件
```css
p
{
  color:red;
}

#aaa /* 这个是id 不要数字开头 部分浏览器会出问题 */
{
  color:blue;
  font-size:10px;
}

.class_name /* 这个是class  不要数字开头 部分浏览器会出问题*/
{
    color : rgba(0,255,255,0.4);
}

```

html文件
```html
<!DOCTYPE html>

<html>
 <head>
  <meta charset="utf-8">//中文一定要用UTF-8
  <title>文档标题</title>
  <!-- 在这里声明css文件位置 -->
  <link rel="stylesheet" type="text/css" href="mystyle.css" />
  <style src="js文件路径">
      /* CSS的代码写这里 */
      
  </style>
  <script>
	 /* JavaScript代码写这里 */
		
  </script>
 </head>
 
 <body>
    <!-- 主布局（顺便怎么叫吧...）-->
    <p id="aaa">hello&nbsp</p>
    <p >world</p>
 </body>
 
</html>
```


# 未分类的笔记
### 来源  疯狂刷题
HTML语言中`<input>`标记含有多种属性，其中type
属性用于规定input元素的类型，包含button、
checkbox、hidden、image、password、reset、
submit、text等几种，其中：
button用于定义可点击的按钮;
checkbox用于定义文档中的复选框;
hidden用于定义隐藏的输入字段;
image用于定义图像形式的提交按钮;
password用于定义密码字段，该字段中的字符将被
掩码;
reset用于定义重置按钮，重置按钮可以清除表单中的
所有数据;
submit用于定义提交按钮，该按钮可以将表单数据发
送至服务器;
text用于定义单行的输入字段，用户可在其中输入文
本，默认宽度为20个字符。
### 

```css
border-radius:115px;
box-shadow:2px 2px 25px rgba(0,0,0,.3);
```