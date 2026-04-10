
笔记来自:   
# 高级感啪(复制粘贴)的一下 就上来了!
# 文本阴影在下面喵  [点我跳转](#文字阴影) 

# 正常阴影 
#### 定义阴影:
```css
box-shadow:box-shadow: inset 0px 0px 10px 3px rgba(0, 0, 0, 0.5) ;
```
这几个px分别是
- 水平偏移  正值向右，负值向左。
- 垂直偏移  正值向下，负值向上。
- 模糊   可选参数   数值越大越模糊。c
- 扩散(放大)   可选参数
- 颜色  可选参数
- inset（内阴影）可选参数，设置为inset时表示阴影在元素内部。
#### 设置内部阴影:
```css
box-shadow: inset 0px 0px 10px 3px rgba(0, 0, 0, 0.5) ;
```

- 可以设置多个阴影  "," 分割: 
```css
box-shadow: -5px -5px 10px 3px rgba(120, 120, 250, 0.5),5px 5px 10px 3px rgba(0, 0, 0, 0.5) ;
```
- 或者内阴影
```css
box-shadow:  inset 5px 5px 10px 3px rgba(120, 120, 250, 0.5), inset -5px -5px 10px 3px rgba(0, 0, 0, 0.5) ;
```

还可以变成一个棋子:   (再改改可以变成一个"球")
```css
.test {
	width: 100px;
	height: 100px;
	border-radius: 50%;
	box-shadow: inset 8px 8px 8px rgba(0, 0, 0, 0.3),
	inset -8px -8px 8px rgba(255,255,255, 0.7),
	-10px -10px 10px rgba(0, 0, 0, 0.4);
}
```

黑色背景 可以是光源  调整一下  可以变成月牙
```css

```

```css

```
还有鼠标悬停的效果  
```css
.test:hover {
	transform: translateY(-8px) scale(1.01, 1.01);
	/* 其他需要改的 */
}
```


### 文字阴影

```css
text-shadow:box-shadow: inset 0px 0px 10px rgba(0, 0, 0, 0.5) ;
```
- 和box-shadow使用方法类似  不过少了个扩散参数


黑色字+黑色阴影+透明=文字模糊效果
白色字+等距偏移+依次降低颜色(变成黑色)=像素风格文字
像素风格文字+模糊=3D风格(减少层数更加明显)
又或者把阴影放入伪类 空间感觉 

1分45喵