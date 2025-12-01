

```cpp
#include <cstring>
```


```cpp
// 1. 字符串连接
char dest[20] = "Hello";
char src[] = " World";
std::strcat(dest, src); // dest = "Hello World"
```

```cpp
// 2. 字符串比较
char str1[] = "apple";
char str2[] = "banana";
int result = std::strcmp(str1, str2); // 负数：str1 < str2
```

```cpp
// 3. 字符串长度
size_t len = std::strlen("Hello"); // 5
```

```cpp
// 4. 字符串查找字符
char str[] = "Hello";
char* pos = std::strchr(str, 'e'); // 指向第一个 'e' 的位置
```

```cpp
// 5. 字符串查找子串
char text[] = "Hello World";
char* found = std::strstr(text, "World"); // 指向 "World" 开始位置
```




