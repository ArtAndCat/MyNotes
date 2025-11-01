




调用非静态函数
```cpp
#include <functional>
```

```cpp
// 在类中声明
std::function<返回类型()> 函数指针P;
```

```cpp
void 类A::函数() {
    函数指针P = std::bind(&类::非静态函数, this); // 绑定成员函数和对象实例
}
```

```cpp
if (函数指针P) 函数指针P(); // 调用绑定后的函数
```

```

```
智能指针


