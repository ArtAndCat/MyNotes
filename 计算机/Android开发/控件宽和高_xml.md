#编程  #Android #XML 

```
android:layout_width = "参数_大小"
android:layout_height = "参数_大小"
```

参数_大小：
- match_parent  和父元素一样
- wrap_content   能刚好包含内容即可
- 0dp  字面意思

```
android:layout_weight="数字"
```
和其他控件平分大小（数字和占比有关）

具体计算方法就是..
控件1的数字为x
控件2的数字为x2
屏幕宽为w
控件1的w为$w/(x+x2)*x$
控件2的w为$w/(x+x2)*x2$



