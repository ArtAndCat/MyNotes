#编程  #Android #xml #布局 #UI


```xml
<ConstraintLayout 
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:orientation="horizontal"
    android:layout_width="match_parent"
    android:layout_height="match_parent"    >
    
</ConstraintLayout>
```


怎么AIDE Pro里没有？

上下位置（范围：0~1）
```
app:layout_constraintVerticaL_bias="0"
```
左右位置（范围：0~1）
```
app:layout_constraintHorizontal_bias="0"
```




在ConstraintLayout中，你可以使用`app:layout_constraint`属性来定义一个视图相对于其他视图或者其父容器边缘的位置关系。下面是与你提供的相对布局示例相对应的ConstraintLayout约束：

左
```xml
app:layout_constraintLeft_toLeftOf="@+id/另一个控件ID"
```
如果想要让一个视图紧贴其父容器的左边，则可以使用：
```xml
app:layout_constraintStart_toStartOf="parent"
```

上
```xml
app:layout_constraintTop_toTopOf="@+id/另一个控件ID"
```
如果想要让一个视图紧贴其父容器的上边，则可以使用：
```xml
app:layout_constraintTop_toTopOf="parent"
```

下
```xml
app:layout_constraintBottom_toBottomOf="@+id/someViewId"
```
如果想要让一个视图紧贴其父容器的下边，则可以使用：
```xml
app:layout_constraintBottom_toBottomOf="parent"
```

右
```xml
app:layout_constraintRight_toRightOf="@+id/另一个控件ID"
```
如果想要让一个视图紧贴其父容器的右边，则可以使用：
```xml
app:layout_constraintEnd_toEndOf="parent"
```

需要注意的是，在使用这些约束时，你可能需要在你的XML文件顶部添加对ConstraintLayout命名空间的支持，如下所示：
```xml
xmlns:app="http://schemas.android.com/apk/res-auto"
```

此外，`Start`和`End`通常用于从左到右或从右到左的语言布局（如阿拉伯语），它们是基于当前布局方向的。在大多数情况下，`Left`和`Right`仍然有效，但`Start`和`End`提供了更广泛的适用性。


### 备注：如果同时写了左和右，控件会居两个中间   “不超过” ..  不是特别懂，但好像又知道是啥





