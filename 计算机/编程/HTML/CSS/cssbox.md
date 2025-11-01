 #css #编程 #视频笔记 
【css盒子模型 保姆级动画详解 完全掌握box-sizing-哔哩哔哩】 https://b23.tv/RGZfyC7


大小
```css
width: px;
height: px;
```
边框
```css
border :_px solid #000000;
```
- solid  边框单实线
- 

内边距
```css
padding: _px;
```
外边距
```css
margin: _px;
```
margin-top: \_px;    还能这么玩？？

新增笔记：顺时针  宽度  样式  颜色
```css
border-style:none无（默认）solid单实线 dashed虚线 dotted点线 double 双实线
```

大小的计算方式有两种，可以使用box-sizing指定
```css
/* 默认 宽高=内容区 空间占用向外扩大。*/
box-sizing:content-box;
/* 宽高多少，实用占用就是多少 */
box-sizing:border-box;
```
展示方式
```css
/* 块级（block） / 行内（inline）/... */
display: inline-block；
```
1分19，看不懂了...
block  独立占据一行。
inline  占用内容区域的大小，不能设置宽高。
如果想调整大小可以使用  inline-block
如果两个盒子相邻，他们的间距将会是两个盒子间距最大的那个
给他们设置浮动或添加  display: inline-block；
如果父元素没有设置高度  子元素设置了浮动。
会导致父元素高度塌陷。
给副元素设置：
```css
overflow:hidden;
```
如果给盒子设置了背景色内边距区域会被上色边框不会
给盒子设置了鼠标状态内边距和边框会被影响。
鼠标状态：
```css
cursor:pointer;
```

