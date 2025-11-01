#C #编程 #新特性 



```cpp
#include <memory>
```

```cpp
//unique_ptr<类名> 指针名(new 类名);
```

```cpp
auto 指针名 = make_unique<类名>();
```
指针消失时 内存自动释放
唯一的  不允许出现两个指针指向同一个对象

shared_ptr？？