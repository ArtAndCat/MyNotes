#C #编程 #新特性 

可以快速定义一个匿名函数
语法定义
```cpp
[变量](参数) ->返回类型 {函数体}
```

```cpp
[变量](参数) {函数体}
```
注意
- 全局变量和静态变量不能用
- this
- = 捕获lambda表达式定义域的全部变量的值，包括this
- & 捕获lambda表达式定义域的全部变量的引用，包括this
例
```cpp
int x = 5;
auto foo = [x](int y)->int { return x * y; };
atd::cout << foo(8) << std::endl;
```


配合STL很好
如
```cpp
*std::find_if(开始指针,结束指针,[](int i) {return (i % 3) == 0;})
```

#### 广义捕获
```cpp
int x = 5;
auto foo = [](r = x +1){ return r;};
```

#### C++14支持泛型编程[[C++黑马教程#1~18模板 C++STL库 （标准模板库）]]
```cpp
auto foo = [](auto a){ return a;};
```

C++20 泛型lambda表达式
```cpp
[]<typename T>(std::vector<T> v){...};
```
C++20 可以构造对象
```cpp
auto greater = [](auto a,auto b){ return a < b;};//无状态
std::map<std::string,int,decltype(greater)> mymap;
```

注意：
- `*this` 是拷贝 用于异步函数
- `=this` 是直接使用
