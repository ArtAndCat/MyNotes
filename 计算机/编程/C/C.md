7
[[计算机/编程/C++/C++|C++]]

[ ! ]  vscode 密钥 坏的！！！！


这里只写和C++不一样的地方
```c
#include <stdio.h>
```
输出
```c
char str[4] = "C!";
printf("hello world!");
printf("hello %s", str);
```
输入
```c
char str[40];
scanf("%s", &str);
printf("%s", str);
scanf("打印 %s", &str);// 在运行到这里时格式需要完全一致 例如“打印 helo world“”
printf("%s", str);//这里会打印 helo world
```
[[C语言格式说明符完整表格]] %d %f %s
### 数据类型：
- 基本类型
	- 整形（int）
		- 基本型
		- 长整型
	- 字符型 （char）
	- 实型或浮点型
		- 基本型
		- 长整型
- 构造类型
	- 枚举类型
	- 数组类型
	- 结构体类型
	- 共用体类型
- 指针类型（xxx* name）
- 空类型（void name）
### ：











