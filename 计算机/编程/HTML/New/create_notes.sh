
# 颜色输出
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${BLUE}开始创建完整的笔记结构...${NC}"

# 1. 创建文件夹结构
echo -e "${GREEN}创建文件夹结构...${NC}"
mkdir -p 00_元笔记/模板中心 \
         01_HTML/{00_HTML入门,01_基础标签,02_表格与表单,03_语义化HTML,04_元数据与头信息} \
         02_CSS/{00_CSS基础,01_布局系统,02_样式设计,03_高级技巧,04_CSS框架} \
         03_JavaScript/{00_JS基础,01_核心概念,02_DOM操作,03_异步编程,04_ES6+新特性,05_浏览器API} \
         04_实战案例/{00_案例索引,01_静态页面,02_交互组件,03_完整项目} \
         05_代码片段库/{HTML片段,CSS片段,JS片段} \
         06_问题解决 \
         07_学习资源

# 2. 创建元笔记文件
echo -e "${GREEN}创建元笔记文件...${NC}"
touch 00_元笔记/{笔记使用指南.md,标签系统.md,知识图谱.md}
touch 00_元笔记/模板中心/{概念笔记模板.md,API参考模板.md,问题解决模板.md,代码片段模板.md}

# ============================================
# 3. 写入文件内容
# ============================================

# 3.1 概念笔记模板
echo -e "${GREEN}写入概念笔记模板...${NC}"
cat > 00_元笔记/模板中心/概念笔记模板.md << 'TEMPLATE'
---
创建时间: {{date}}
标签: 
难度: ⭐
状态: #待学习
---

# {{title}}

## 📖 一句话概括
[用一句话说明这个知识点是什么]

## 🎯 为什么重要
- **解决了什么问题**：
- **应用场景**：
- **核心价值**：

## 📝 语法/写法
```代码示例
🔗 知识连接
前置知识
[[链接]]

相关概念
[[链接]]

后续学习
[[链接]]

⚠️ 注意事项
易错点：

最佳实践：

💡 实战应用
参考 [[04_实战案例/案例名称]]

✅ 自我检测
能用自己的话解释

能写出基础示例
TEMPLATE

3.2 API参考模板
echo -e "${GREEN}写入API参考模板...${NC}"
cat > 00_元笔记/模板中心/API参考模板.md << 'TEMPLATE'

API名称:
所属:
版本:

{{title}}
📚 语法
```javascript
// 语法格式
```

🔧 参数说明
参数	类型	必填	说明
🎯 返回值
[说明返回值类型和含义]

💡 示例
```javascript
// 使用示例
```

⚠️ 注意事项
🔗 相关API
[[链接]]
TEMPLATE

3.3 HTML入门
echo -e "${GREEN}写入HTML入门...${NC}"
cat > 01_HTML/00_HTML入门.md << 'HTML'

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
HTML

3.4 文本标签
echo -e "${GREEN}写入文本标签...${NC}"
cat > 01_HTML/01_基础标签/文本标签.md << 'HTML'

文本标签详解
📝 标题标签 h1~h6
html
<h1>一级标题（最重要）</h1>
<h2>二级标题</h2>
<h3>三级标题</h3>
<h4>四级标题</h4>
<h5>五级标题</h5>
<h6>六级标题</h6>
📄 段落和换行
html
<p>这是一个段落，会自动换行，段落间有间距。</p>
<p>这是另一个段落。</p>
这是第一行<br>
这是第二行（br是换行标签）
✨ 文本格式化
html
<strong>重要文本（粗体）</strong>
<em>强调文本（斜体）</em>
<mark>标记文本（高亮）</mark>
<del>删除文本（中划线）</del>
<ins>插入文本（下划线）</ins>
<small>小号文本</small>
🔗 知识连接
[[./链接与图像|链接与图像标签]]

[[02_CSS/02_样式设计/文字排版|CSS文字排版]]

💡 最佳实践
h1 每页只用一个

不要用标题标签实现加粗，用 CSS

段落用 p，不要用 br 换行
HTML

3.5 CSS引入方式
echo -e "${GREEN}写入CSS引入方式...${NC}"
cat > 02_CSS/00_CSS基础/CSS引入方式.md << 'CSS'

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
CSS

3.6 JavaScript变量
echo -e "${GREEN}写入JavaScript变量...${NC}"
cat > 03_JavaScript/00_JS基础/变量与数据类型.md << 'JS'

JavaScript 变量与数据类型
📦 变量声明
var（旧方式）
javascript
var name = "张三";
var age = 18;
var old; // undefined
函数作用域

可重复声明

会提升（hoisting）

let（现代方式）
javascript
let name = "李四";
name = "王五"; // 可以重新赋值
// let name = "赵六"; // ❌ 错误：不能重复声明
块级作用域 {}

不可重复声明

推荐使用

const（常量）
javascript
const PI = 3.14;
// PI = 3.1415; // ❌ 错误：不能重新赋值

const person = {
    name: "小明"
};
person.name = "小红"; // ✅ 对象属性可以修改
声明时必须赋值

不可重新赋值

引用类型可修改属性

📊 数据类型
基本类型（7种）
javascript
// 1. 数字 number
let num = 100;
let price = 19.99;
let infinity = Infinity;

// 2. 字符串 string
let str1 = "双引号";
let str2 = '单引号';
let str3 = `模板字符串 ${str1}`;

// 3. 布尔 boolean
let isTrue = true;
let isFalse = false;

// 4. 未定义 undefined
let notDefined;

// 5. 空 null
let empty = null;

// 6. 符号 symbol (ES6新增)
let sym = Symbol('描述');

// 7. 大整数 bigint
let big = 9007199254740991n;
引用类型
javascript
// 对象 object
let person = {
    name: "张三",
    age: 18
};

// 数组 array
let fruits = ["苹果", "香蕉", "橙子"];

// 函数 function
function sayHello() {
    console.log("你好");
}
🔍 类型检测
javascript
typeof "hello";      // "string"
typeof 123;          // "number"
typeof true;         // "boolean"
typeof undefined;    // "undefined"
typeof null;         // "object" (历史遗留问题)
typeof {};           // "object"
typeof [];           // "object"
typeof function(){}; // "function"

// 更好的数组检测
Array.isArray([]);   // true
💡 最佳实践
优先用 const，需要改变时用 let

避免用 var

变量名用驼峰命名（camelCase）

常量用全大写（UPPER_SNAKE_CASE）

🔗 知识连接
[[../01_核心概念/函数进阶|函数和作用域]]

[[../04_ES6+新特性/解构与展开|解构赋值]]
JS

3.7 问题解决模板
echo -e "${GREEN}写入问题解决模板...${NC}"
cat > 00_元笔记/模板中心/问题解决模板.md << 'TEMPLATE'

问题:
日期: {{date}}
状态: #待解决

[问题描述]
🐛 现象
[描述遇到的问题表现]

🔍 排查过程
第一步尝试...

结果：

第二步尝试...

结果：

💡 解决方案
代码
// 解决代码
📚 原因分析
[为什么会出现这个问题]

⚠️ 预防措施
[以后如何避免]

🔗 相关链接
[[06_问题解决/常见错误|相关错误]]

外部链接

TEMPLATE

3.8 README
echo -e "${GREEN}写入README...${NC}"
cat > README.md << 'README'

📚 Web开发三件套笔记
🎯 笔记体系说明
文件夹结构
text
📁 00_元笔记/     # 笔记使用方法和模板
   ├── 模板中心/   # 各种笔记模板
   ├── 标签系统.md # 统一的标签规范
   └── 知识图谱.md # 整体知识结构

📁 01_HTML/       # HTML学习笔记
📁 02_CSS/        # CSS学习笔记
📁 03_JavaScript/ # JavaScript学习笔记
📁 04_实战案例/    # 完整项目案例
📁 05_代码片段库/  # 可复用的代码片段
📁 06_问题解决/    # 遇到的问题和解决方案
📁 07_学习资源/    # 推荐的学习资料
🚀 使用指南
1. 记笔记流程
text
遇到新概念 → 用[概念笔记模板]记录
学习新API  → 用[API参考模板]记录
遇到问题   → 用[问题解决模板]记录
积累代码   → 放入[代码片段库]
完成项目   → 写入[实战案例]
2. 连接笔记的原则
向上连接：具体 → 抽象

markdown
[[00_元笔记/标签系统]]  # 具体笔记连接元笔记
横向连接：相关概念互连

markdown
HTML连接CSS：[[02_CSS/00_CSS基础/选择器大全]]
向下连接：抽象 → 具体

markdown
参考 [[04_实战案例/具体案例]]
3. 标签系统
text
#技术分类
#HTML #CSS #JavaScript

#难度
#入门 #进阶 #精通

#状态
#学习中 #待复习 #已掌握

#类型
#概念 #API #技巧 #踩坑
📝 快速开始
先看 [[00_元笔记/笔记使用指南]]

熟悉 [[00_元笔记/标签系统]]

从 [[01_HTML/00_HTML入门]] 开始学习

🔄 定期维护
每周复习：使用随机漫游功能

每月整理：更新 [[00_元笔记/知识图谱]]

遇到问题：记录到 [[06_问题解决]]

保持连接，让知识生长
README

3.9 标签系统
echo -e "${GREEN}写入标签系统...${NC}"
cat > 00_元笔记/标签系统.md << 'TAGS'

标签系统
🏷️ 标签分类
1. 技术分类（必选其一）
#HTML - HTML相关

#CSS - CSS相关

#JavaScript - JS相关

#工具 - 开发工具

2. 难度等级（可选）
#入门 - 基础知识

#进阶 - 深入概念

#精通 - 高级技巧

3. 学习状态（可选）
#学习中 - 正在学习

#待复习 - 需要复习

#已掌握 - 已经掌握

4. 内容类型（可选）
#概念 - 核心概念

#API - API参考

#技巧 - 使用技巧

#踩坑 - 错误记录

📋 使用示例
markdown
# Flexbox布局
#CSS #进阶 #已掌握 #概念

## 核心概念
...
🔗 标签组合查询
#HTML #入门 - HTML基础知识

#CSS #技巧 - CSS技巧

#JavaScript #踩坑 - JS错误记录
TAGS

最后统计
echo -e "${BLUE}================================${NC}"
echo -e "${GREEN}✅ 创建完成！${NC}"
echo -e "${YELLOW}📊 统计信息：${NC}"
echo "文件夹数量：$(find . -type d | wc -l)"
echo "文件数量：$(find . -type f -name "*.md" | wc -l)"
echo -e "${BLUE}================================${NC}"
echo -e "使用以下命令查看结构："
echo " tree . -L 2"
echo " ls -R"
