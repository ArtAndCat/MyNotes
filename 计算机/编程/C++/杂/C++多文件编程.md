#C #多文件编程 #编程

http://t.csdnimg.cn/9znmT  CNMCSDN!!!我的TM的教程呢？？你TM怎么给我吃了！TMD！






## C++多文件编程初步

一个完整的c++项目常常是多个代码文件组成，根据后缀名不同，大致分为两类:
1. .h文件: 头文件，用于存放常量，函数的声明部分，类的声明部分
2. .cpp文件: 源文件，用于存放变量，函数的定义部分，类的实现部分
#### 代码：
```cpp
// student.h
class Student{
public:
	const char *name;
	int age;
	float score;
	void say();
};
```

```cpp
// student.cpp
#include <iostream>
#include "student.h"
void Student::say(){
	std::cout << name << " " << age;
}
```

```cpp
// main.cpp
#include "student.h"
int main(){
	Student *pStu = new Student;
	pStu -> name = "wuzhongqiang";
	pStu -> age = 25;
	pStu -> score = 92.5f;
	pStu -> say();
	delete pStu;
}
```

## C++如何防止头文件被重复引入
##### 方法一
```cpp
#ifndef 宏名称
#define 宏名称
// 头文件内容
#endif
```
##### 方法二
`#prama once` 效率很高。 但值得一提的是，并不是每个版本编译器都能识别#pragma one指令，所以兼容性可能不是很好。 另外， `#pragma once` 只能作用于某个具体文件， 无法像#ifndef那样仅作用于指定的一段代码。
##### 方法三
C99标准中新增加了一个和#pragma指令类似的_Pragma操作符，可以看做是#pragma的plus版，不仅实现了#prama所有功能，更重要的， `_Pragma`还能和宏搭配使用，也是可移植性差
代码：
```cpp
_Pragma("once")
```
## C++命名空间如何应用在多文件编程中


```cpp
// student_li.h
#ifndef _STUDENT_LI_H
#define _STUDENT_LI_H
namespace Li{
	class Student{
		public:
			void display();
	};
}
#endif
```

```cpp
// student_li.cpp
#include "student_li.h"
#include<iostream>
void Li::Student::display(){
	std::cout << "Li::display" << std::endl;
}
```

```cpp
// student_han.h
#ifndef _STUDENT_HAN_H
#define _STUDENT_HAN_H
namespace Han{
	class Student{
		public:
			void display();
	};
}
#endif
```

```cpp
// student_han.cpp
#include "student_han.h"
#include<iostream>
void Han::Student::display(){
	std::cout << "Han::display" << std::endl;
}
```

```cpp
// main.cpp
#include <iostream>
#include "student_li.h"
#include "student_han.h"
int main(){
	Li::Student stu1;
	stu1.display();
	Han::Student stu2;
	stu2.display();
}
```

## C++ const常量如何在多文件编程中用

## C++多文件项目如何用g++命令执行
## C++多文件编程更深层原理
## g++, MakeFile和CMake小补
## 小总