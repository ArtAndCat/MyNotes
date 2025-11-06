



```cpp
#include <utility>    // C++11 之后
```

```cpp
std::swap(a, b);
```

自定义
```cpp
class MyClass {
private:
    std::vector<int> data;
    
public:
    // 自定义 swap 函数
    friend void swap(MyClass& first, MyClass& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
    }
    
    // 移动语义支持
    MyClass(MyClass&& other) noexcept : data(std::move(other.data)) {}
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }
};

// 使用
MyClass obj1, obj2;
swap(obj1, obj2);  // 高效交换
```