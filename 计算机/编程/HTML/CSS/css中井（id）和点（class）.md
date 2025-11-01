 #css #编程
id（井）选择题只能对应一个元素
类（点）选择器可以对应多个元素。

井的用法
```css
#名称 { /* 不能数字开头部分浏览器会出问题 */
    color:red;
    
}
```

```html
<p id="名称">hello world</p>
```
点的用法
```css
.名称 { /* 不能数字开头部分浏览器会出问题 */
    color:blue;
}

.名称2 {
    font-size:20px;
}
```

```html
<p class="名称 名称2">hello world</p>
```

