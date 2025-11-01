 #css #编程 #视频笔记 
【css定位 保姆级动画详解 完全掌握position-哔哩哔哩】 https://b23.tv/K2WqAIc

static  **静态**     （默认  不需要定位。）
relative  相对  （相对于元素本事进行移动）
absolute  绝对（相对于已定位的父元素进行定位
--                          如果是**静态**，那就接着找上一级 
--               脱离文档流  不占用空间  可能影响其他元素和布局
--               如果没有设置宽度  会根据自身设置
--              z-index  Fixed定位同理
--              如果没有填写位置 会保持原来位置，不是默认0）
fixed  固定      （固定于浏览器窗口）
sticky  粘性    （到达指定位置时开始定位，受父级影响）

定位时使用 left  right  top  bottom  来定位，也可以多添加上面的定位于哪儿

例子：
```css
.box {
    position:fixed;
    left:50px;
    bottom:50px;
}
```