 #css #编程 #视频笔记
【flex弹性布局 动画详解系列 css科普教程-哔哩哔哩】 https://b23.tv/yJElqdB
展示方式（来源：盒子模型）（因为经常找，所以记在这里。）
```css
/* 块级（block） / 行内（inline）/... */
display: inline-block；
```



这个本来在后面，但我觉得这个比较重要...好吧，我没看懂。
```css
flex: 0 1 auto;  是-grow -shrink -basis的简写
```
排序方式
```css
flex-direction:rom(默认水平) column（垂直）-reverse（反向）  ;
```
box间的对齐方式（左右）
```css
justify-content:flex-start（默认主轴前对齐)flex-end(后对齐)center(居中)space-between(等距首尾)space-around(等距 两边)space-evenly(等距 容器)
```
（上下）
```css
align-items:flex-start(默认 交叉轴前对齐)flex-end(交叉轴后对齐)center(居中)baseline(文字首航对齐)stretch(拉伸）
```
抽出后是否换行？默认不换。有“反向”选择
```css
flex-wrap:nowrap;
```
多行项目在交叉轴的对齐方式。我觉得你能看懂。(1:25)
```css
align-content: flex-start flex-end center stretch space-between space-around;
```