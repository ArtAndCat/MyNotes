
HTML 入门
🌐 什么是 HTML？
HTML（HyperText Markup Language）是超文本标记语言，用来描述网页的结构。

🏗️ 基础结构
html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>页面标题</title>
</head>
<body>
    <h1>我的第一个标题</h1>
    <p>我的第一个段落</p>
</body>
</html>
📦 核心概念
1. 元素（Element）
html
<开始标签 属性="值">内容</结束标签>
2. 块级元素 vs 内联元素
块级元素	内联元素
div, p, h1~h6	span, a, strong
独占一行	不换行
可设宽高	宽高由内容决定
🔗 知识连接
[[01_基础标签/文本标签|文本标签详解]]

[[02_CSS/00_CSS基础/CSS引入方式|如何给HTML添加样式]]

[[03_JavaScript/02_DOM操作/DOM选择器|用JS操作HTML]]

💡 小贴士
始终声明 DOCTYPE

指定 lang 属性有助于 SEO

使用语义化标签
