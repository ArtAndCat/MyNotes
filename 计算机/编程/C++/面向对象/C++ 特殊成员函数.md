
建议先看[[C++黑马教程#构造函数（初始化）和分析函数（删除） 23]] 这一块的内容 要不然你看不懂这里的笔记 (补充 我笔记你看不懂的 建议看原视频)

**三/五法则总结**：
- **三法则**：如果需要自定义析构函数、拷贝构造函数、拷贝赋值运算符中的任何一个，通常需要全部三个
- **五法则**：三法则 + 移动构造函数(C++11) 和 移动赋值运算符(C++11)
# **1. 构造函数**
如果使用了 `new` 记得写配套的[析构函数](#**2. 析构函数**)和[拷贝控制函数]()
#### 1.1 默认构造
```cpp
类名(){  }
```
#### 1.2 参数化构造函数   
别忘了 `const` !! 尤其是你用`char*`时 
```cpp
类名(类型 名称){  }
```
#### 1.3 委托构造函数：委托给参数化构造函数
多个构造共享初始化逻辑时
```cpp
类名() : 类名(参数) {  }
```
**效果**：先调用`类名(参数)`初始化当前对象，再执行`{ }`内的代码
#### 1.4 初始化列表
const成员  引用成员  无默认构造的成员 只能通过这个赋值 具体见[[#初始化列表的约束条件]] 
```cpp
类名() : 数据1(值1), 数据2(值2) { }
```
**例子** : `Tank() : HP(180) {  }  `
#### 1.5 explicit构造函数：禁止隐式转换
```cpp
explicit 类名(类型 名称) {  }
```
**效果**：禁止 `类名 对象 = 参数;` 这种隐式转换
#### 补充内容
###### 初始化列表的约束条件
```cpp
class Example {
    const int id;      // const成员
    int& ref;          // 引用成员  
    OtherClass obj;    // 无默认构造的成员
    
public:
    Example(int x, int& r, OtherClass o) 
        : id(x), ref(r), obj(o)  // ✅ 这些必须在初始化列表
    {
        // id = x;    // ❌ 错误！const成员不能在函数体内赋值
        // ref = r;   // ❌ 错误！引用成员不能在函数体内绑定
    }
};
```
###### **explicit的实际影响**
```cpp
explicit MyString(const char* str) {}

void func(MyString s) {}

// 使用影响：
MyString s1("Hello");     // ✅ 直接调用，OK
MyString s2 = "World";    // ❌ 拷贝初始化，错误！
func("Hello");            // ❌ 隐式转换，错误！
func(MyString("Hello"));  // ✅ 显式构造，OK
```

### 例子:


# **2. 析构函数**  
如果使用了动态内存分配或资源管理，记得写析构函数来避免资源泄漏
#### 2.1 基本语法
```cpp
~类名() { /* 清理代码 */  }
```
**特点**：无参数，无返回值，不能重载，每个类只有一个析构函数
#### 2.2 默认析构函数
当类没有显式定义析构函数时，编译器会自动生成一个
**效果**：逐个销毁数据成员，对于类类型成员调用其析构函数
#### 2.3 需要自定义析构函数的情况
1. new的空间
2. 一些需要手动关闭/释放的 (成员有写析构函数的可不写)
#### 2.4 虚析构函数  virtual 
当类可能被继承时，应将析构函数声明为虚函数
子类:
```cpp
virtual ~类1() /* 虚析构函数 */ { /* 清理代码 */ }
```
父类:   (`class 类2 : public 类1 `)
```cpp
~类2() override /* 自动成为虚函数 */ { /* 派生类清理代码 */ }
```
**效果**：通过基类指针删除派生类对象时，能正确调用整个继承链的析构函数
#### 补充内容
###### **析构函数调用时机**
```cpp

{
    MyClass obj;           // 自动存储期对象
    MyClass* ptr = new MyClass();  // 动态存储期对象
    
} // 离开作用域：obj的析构函数自动调用
  // ptr指向的对象需要手动 delete
```

###### **RAII模式示例**
```cpp
class SmartArray {
    int* data;
    size_t size;
public:
    SmartArray(size_t n) : data(new int[n]), size(n) {}
    
    ~SmartArray() {
        delete[] data;  // 自动释放资源
        data = nullptr;
        size = 0;
    }
    
    // 其他成员函数...
};

// 使用：无需手动管理内存
void func() {
    SmartArray arr(100);  // 构造函数分配内存
    // 使用arr...
} // 离开作用域时析构函数自动释放内存

```
###### **三/五法则**

如果定义了以下任何一个，通常需要定义全部：
- 析构函数
- 拷贝构造函数
- 拷贝赋值运算符
- 移动构造函数（C++11）
- 移动赋值运算符（C++11）
```cpp
class RuleOfFive {
    char* data;
public:
    // 构造函数
    RuleOfFive(const char* str);
    
    // 析构函数
    ~RuleOfFive() { delete[] data; }
    
    // 拷贝控制
    RuleOfFive(const RuleOfFive& other);
    RuleOfFive& operator=(const RuleOfFive& other);
    
    // 移动控制（C++11）
    RuleOfFive(RuleOfFive&& other) noexcept;
    RuleOfFive& operator=(RuleOfFive&& other) noexcept;
};
```



2.1 析构函数调用时机  
2.2 虚析构函数的重要性  
2.3 析构函数与异常安全  
2.4 RAII 设计模式  
2.5 析构顺序与依赖管理

# **3. 拷贝语义**


#### 3.1 拷贝构造函数  
```cpp
类名(const 类名& 对象名 = __ ){  }
```
#### 3.2 拷贝赋值运算符实现 [[C++ 特殊成员函数#**5. 运算符重载**]]
```cpp
Strings& operator=(const String& other) {
```
- 必须处理自赋值情况
#### 3.3 深拷贝与浅拷贝区别  
深拷贝: 复制指针指向的数据 
浅拷贝: 复制指针 指向同一个地址
```cpp
String(const String& other) 
    : length(other.length) {
    // 深度拷贝
    data = new char[length + 1];
	std::strcpy(data, other.data);
}
```
#### 3.4 自赋值检查

```cpp
// 方法1：显式检查
if (this == &other) {
    return *this;
}  
// 方法2：拷贝并交换惯用法（更安全）
int* newData = new int(*other.data);  // 先分配
delete data;                          // 后释放
data = newData;
```
#### 3.5 拷贝控制的五法则

```cpp
class RuleOfFive {
    char* buffer;
    size_t size;
public:
    // 基本构造函数
    RuleOfFive(const char* str = "") : size(std::strlen(str)) {
        buffer = new char[size + 1];
        std::strcpy(buffer, str);
    }
    
    // 1. 析构函数
    ~RuleOfFive() { delete[] buffer; }
    
    // 2. 拷贝构造函数
    RuleOfFive(const RuleOfFive& other) : size(other.size) {
        buffer = new char[size + 1];
        std::strcpy(buffer, other.buffer);
    }
    
    // 3. 拷贝赋值运算符
    RuleOfFive& operator=(const RuleOfFive& other) {
        RuleOfFive temp(other);  // 拷贝构造
        swap(*this, temp);       // 交换
        return *this;            // temp析构清理旧资源
    }
    
    // 4. 移动构造函数（C++11）
    RuleOfFive(RuleOfFive&& other) noexcept 
        : buffer(other.buffer), size(other.size) {
        other.buffer = nullptr;  // 置空源对象
        other.size = 0;
    }
    
    // 5. 移动赋值运算符（C++11）
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            delete[] buffer;        // 释放当前资源
            buffer = other.buffer;  // 接管资源
            size = other.size;
            other.buffer = nullptr; // 置空源对象
            other.size = 0;
        }
        return *this;
    }
    
    // 交换函数
    friend void swap(RuleOfFive& a, RuleOfFive& b) noexcept {
        using std::swap;
        swap(a.buffer, b.buffer);
        swap(a.size, b.size);
    }
};
```
# **4. 移动语义**  (C++11)

#### 4.1 移动构造函数原理  
```cpp

类名(类名&& other) noexcept {
    other.data = nullptr;  // 关键：使源对象处于有效但空的状态
    other.size = 0;
}
```
1. **参数类型**：`类名&&`（右值引用）
2. 添加初始化列表  来 不分配新资源：直接接管已有资源   ==
3. 令 other 指向 nullptr 置空源对象：防止双重释放  ===
4. **noexcept声明**：确保容器操作的安全 提高运行速度
#### 4.2 移动赋值运算符

```cpp
类名& operator=(类名&& other) noexcept {  }
```

```cpp
// 提供交换函数以便实现拷贝并交换惯用法
void swap(MyString& other) noexcept {
    std::swap(data, other.data);
    ...
}
```
#### 4.3 右值引用详解  
- **左值引用**：`T&`，绑定到有名称的对象（左值）
- **右值引用**：`T&&`，绑定到临时对象（右值）
```cpp



```
###### 万能引用（Universal Reference）
```cpp
template<typename T>
void func(T&& param) {  // T&& 可能是左值引用或右值引用
    // 使用 std::forward 完美转发
    other_func(std::forward<T>(param));
}```
#### 4.4 std::move 内部机制  


#### 4.5 移动语义的性能优势  

# **5. 运算符重载**  

#### 5.1 算术运算符重载  
#### 5.2 关系运算符重载  
#### 5.3 下标运算符重载  


#### 5.4 函数调用运算符 (仿函数)

```cpp
返回值类型 operator()(参数列表) { /* 实现 */ }
```
**效果**：让对象能像函数一样被调用 `对象名(参数)`
- 本质：重载 `operator()` 的类对象被称为“仿函数”（Function Object）
- 用途：可保存状态的“智能函数”，常用于算法（如`std::sort`的自定义比较）
```cpp
// ✅ 标准示例：加法仿函数
class Adder {
    int base;  // 可保存状态
public:
    Adder(int n) : base(n) {}
    
    // 函数调用运算符重载
    int operator()(int x) const {
        return base + x;
    }
};

// 使用
Adder add5(5);
cout << add5(10);  // ✅ 输出 15，像函数一样调用
```
**补充：STL中的仿函数应用**
```cpp
#include <algorithm>
#include <vector>

// 自定义比较仿函数
class Compare {
public:
    bool operator()(int a, int b) const {
        return a > b;  // 降序排序
    }
};

vector<int> v{3, 1, 4, 1, 5};
sort(v.begin(), v.end(), Compare());  // ✅ 传入仿函数对象

// 等效Lambda表达式（C++11+）
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
```
**注意事项**
1. **可保存状态**：相比普通函数，仿函数可在构造时初始化内部状态
2. **效率优势**：编译器可内联优化，通常比函数指针效率更高
3. **模板兼容**：标准算法模板要求仿函数，不接受普通函数（除非包装为`std::function`）


```cpp
// 状态保持示例：计数器仿函数
class Counter {
    int count;
public:
    Counter() : count(0) {}
    
    void operator()(int x) {
        count += x;
        cout << "当前累计: " << count << endl;
    }
};

Counter cnt;
cnt(10);  // 输出"当前累计: 10"
cnt(5);   // 输出"当前累计: 15" ✅ 保持状态
```
#### 5.5 递增递减运算符  
#### 5.6 流运算符重载
# **6. 类型转换函数** 

#### 6.1 转换运算符定义  
#### 6.2 explicit 转换控制  
#### 6.3 类型转换序列  
#### 6.4 转换中的二义性避免

可搭配[[#1.5 explicit构造函数：禁止隐式转换]]使用  表示"返回时 禁止隐式转换"
# **7. 函数修饰符**  

#### 7.1 const 成员函数语义  
#### 7.2 noexcept 异常规范  
#### 7.3 引用限定符应用  
#### 7.4 constexpr 成员函数  
#### 7.5 override 和 final
# **8. 内存管理相关**

#### 8.1 自定义 new 和 delete  
#### 8.2 定位 new 表达式  
#### 8.3 内存池实现技巧  
#### 8.4 智能指针集成
# **9. 特殊成员函数的生成规则**

#### 9.1 默认生成条件  
#### 9.2 =default 显式默认  
#### 9.3 =delete 删除函数  
#### 9.4 生成规则优先级  
#### 9.5 C++11/14/17/20 规则变化
# **10. 设计模式与最佳实践**

#### 10.1 Rule of Three/Five/Zero  
#### 10.2 单例模式的构造控制  
#### 10.3 工厂模式的构造封装  
#### 10.4 Pimpl idiom 实现  
#### 10.5 异常安全保证级别  
#### 10.6 性能优化技巧

# 附录：实用工具函数

#### A.1 swap 函数优化  
#### A.2 比较运算符自动生成  
#### A.3 哈希函数特化  
#### A.4 序列化支持实现

# 未分类
表示禁止此类型的构造方式
```cpp
类名(类型) = delete; 
```