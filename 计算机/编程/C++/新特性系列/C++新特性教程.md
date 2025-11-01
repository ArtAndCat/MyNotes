#C #编程 #新特性

## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">1：</font></div>
long long类型
需要加“ll”后缀来告诉编译器这是个64位的数据
如果是无符号类型则需要加ull
char16（utf16）和char32（utf32）什么的  2:58

| first code point | last     | byte1    | 2        | 3        | 4        |
| ---------------- | -------- | -------- | -------- | -------- | -------- |
| U+0000           | U+007F   | 0xxxxxxx |          |          |          |
| U+0080           | U+07FF   | 110xxxxx | 10xxxxxx |          |          |
| U+0800           | U+FFFF   | 1110xxxx | 10xxxxxx | 10xxxxxx |          |
| U+10000          | U+10FFFF | 11110xxx | 10xxxxxx | 10xxxxxx | 10xxxxxx |
```cpp
char数字_t 名字 = U'好';//16小u 32大U
char数字_t 名字[] = U"啊啊啊啊";
// char默认就是uif8C++20需要用char8_t
char8_t 名字 = 
```
尽可能不要用wchar
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">2：inline内联与嵌套命名空间</font></div>

将命名空间的对象添加到父类命名空间 ^c62f60
```cpp
namespace a1{
	namespace a2{
		int test(){...}
	};
	inline namespace a3{ // 关键代码
		int test(){...}
	};
};
```
然后你就可以直接调用了
```cpp
a1::test();
```
用于无缝切换版本代码什么的（对于库的作者更加友好了）

```cpp
namespace a1::a2...  {
	int test(){...}
};
```

但下面这个直到C++20才得以支持
```cpp
namespace a1::inline a2...  {
	int test(){...}
};
```
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">3：auto自动推导类型</font></div>
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
## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">4：decltype（增强模板元编程）</font></div>


```cpp
int b = 3;
decltype(a) b = 5;
```
- typeof()  非标准
- typeid()  仅在程序运行时发挥作用

decltype(e)(其中e的类型为T）的推导规则有五条:
- 如果e是一个未加括号的标识符表达式（结构化绑定除外）或者未加括号的类成员访问，则decltype(e)推断出的类型是e的类型T。如果并不存在这样的类型，或者e是一组重载函数，则无法进行推导。
- 如果e是一个函数调用或者仿函数调用，那么decltype(e)推断出的类型是其返回值的类型。
- 如果e是一个类型为T的左值，则decltype(e)是T&。
- 如果e是一个类型为T的将亡值，则decltype(e)是T&&。
- 除去以上情况，则decltype(e)是T。

```
const int&& foo();
int i;
struct A {double x;};
const A* a=new A();

decltype(foo());   // 推导类型为const int&&
decltype(i);       // 推导类型为int
decltype(a->x);    // 推导类型为double
decltype((a->x));  // 推导类型为const double&
```




## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">5：函数返回类型后置</font></div>


```cpp
int aba(int x){
	return x;
}

int(*aaa())(int x){//这是嘛呀！？？
	return aba;
}

std::cout << aaa()(5)<<std::endl;
```
于是..
```cpp
auto aaa()->int(*)(int){//啊~这下看懂了
```




## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">6：左值引用  ♡♡♡</font></div>

左值：可以取到名称和内存地址的值 比如变量 int number  和  cher text
右值：不能...  比如“3”和“hello world”
```cpp
int &&a = ...
```

错误  看不懂啊啊啊啊




## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">7：lambda表达式</font></div>







## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">7：lambda表达式</font></div>











## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">7：lambda表达式</font></div>











## \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);"><font style="font-size:20px">7：lambda表达式</font></div>


























