
CSS 引入方式
三种引入方式对比
1️⃣ 行内样式（内联样式）
html
<p style="color: red; font-size: 16px;">红色文字</p>
✅ 优先级最高

❌ 难以维护，不推荐

2️⃣ 内部样式表
html
<head>
    <style>
        p {
            color: blue;
            font-size: 14px;
        }
    </style>
</head>
✅ 适合单页面

❌ 多个页面无法复用

3️⃣ 外部样式表（推荐）
html
<head>
    <link rel="stylesheet" href="style.css">
</head>
css
/* style.css */
p {
    color: green;
    font-size: 16px;
}
✅ 多页面复用

✅ 便于维护

✅ 可利用浏览器缓存

🎯 优先级
行内样式 > 内部样式 > 外部样式 > 浏览器默认样式

🔗 知识连接
[[02_CSS/00_CSS基础/选择器大全|CSS选择器]]

[[04_实战案例/01_静态页面/个人简历页面/代码实现|实战案例]]
