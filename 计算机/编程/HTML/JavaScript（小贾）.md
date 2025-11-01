


怎么声明函数？
```js
<script>
	/* JavaScript的代码写这里 */
	function 函数名(){
		/*
		 * 这是一个多行备注。
		 */
	}
</script>
```

=========================================
### “获取元素地址”与“元素.内容”：

```js
document.getElementById(" __ ");//获取元素地址  Id可以改成Class（类）...
```
可以通过”.“来点出来详情数据   如
```js
元素.innerHTML //元素.内容
.src //路径
.width //宽
.style //css代码
```

onclick = "函数名"
###### 例子  （点这一行的最左边儿可以折叠“例子”）
script部分的JavaScript代码（JavaScript简称JS）
```js
function f(){
	a = document.getElementById("aa");
	b = document.getElementById("bb");
	a.innerHTML = b.innerHTML //元素.内容
}
```
body部分的HTML代码
```HTML
<div id = "aa">人类<p></p></div>
<div id = "bb">僵尸</div>
<button onclick = "f()">帮助僵尸感染人类</button>
```
### 对变量进行加减与禁用按钮

这个代码可以用来创建用户输入的东西type默认为text
```html
<input type = "text" id = "aa" value = "0">
```
修改
```js
	a = document.getElementById("aa");         //获取
	v = a.value;
	v--;                                       // 给变量加1
	document.getElementById("aa").value = v;   // 传回去
```

”禁用“用true    ”解除禁用“用false
```js
document.getElementById("aa").disabled = true;
```

###### 上课时写的案例代码详情
```html
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta charset="utf-8"><!--中文一定要用UTF-8-->
        <title>文档标题</title>
		<script>
			/* JavaScript的代码写这里 */
			function sub(){// 减
				a = document.getElementById("aa");
				v = a.value;
				if (v == 1){
					// 禁用按钮
					document.getElementById("sub").disabled = true;
				} else if(v < 0){
					v = 0;
					document.getElementById("sub").disabled = true;
				}
				v--;
				document.getElementById("aa").value = v;
			}
			function add(){// 加
				a = document.getElementById("aa");         //获取
				v = a.value;
				if (v == 0){
					//取消禁用
					document.getElementById("sub").disabled = false;
				}
				v++;                                       // 给变量加1
				document.getElementById("aa").value = v;
			}
		</script>
    </head>
    <body>
        <!-- 主布局（顺便怎么叫吧...）-->
        <div>
        	<button  onclick = "add()"> + </button> 
            <input type = "text" id = "aa" value = "0"></input>
            <button  onclick = "sub()" id = "sub"> - </button> 
        </div>
    </body>
</html>
```
### 显示与隐藏
css
```css
visibility = "visible"//显示   hidden  //隐藏
```

# a