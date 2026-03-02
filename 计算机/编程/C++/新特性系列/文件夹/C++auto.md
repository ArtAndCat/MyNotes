#C #编程 #新特性 

自动推导数据的类型
```cpp
auto number = 114514; // 被推倒为int类型
```
返回类型后置（auto充当占位）   函数返回类型C++14
```cpp
auto F1()->int {...}
```
注意！
- 多参数时参数的类型需要保持一致  如`auto a1=0.3, a2 =5;`
- 使用`auto a = true ? 1 : 4.3;`时a会=1（double类型）
- 不能用于类中的非静态成员
- C++20前在函数参数中使用auto会报错
推倒规则：
- auto a = b（const int）时a为不带const的int类型
- auto a = b（& int）时a为int类型  不是引用
- 万能引用
- auto a = b（数组/函数）   a是一个指针
- -
更多
- 函数返回类型也可以使用（C++14）
- lambda 表达式 也可以使用（C++14）
- 模板里也可以使用