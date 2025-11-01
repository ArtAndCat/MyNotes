# C语言格式说明符完整表格

## 基本数据类型格式说明符

| 数据类型                 | 格式说明符                          | 说明       |
| -------------------- | ------------------------------ | -------- |
| `double`             | `%lf` (scanf)<br>`%f` (printf) | 双精度浮点数   |
| `float`              | `%f`                           | 单精度浮点数   |
| `int`                | `%d`                           | 有符号十进制整数 |
| `unsigned int`       | `%u`                           | 无符号十进制整数 |
| `short`              | `%hd`                          | 短整数      |
| `unsigned short`     | `%hu`                          | 无符号短整数   |
| `long`               | `%ld`                          | 长整数      |
| `unsigned long`      | `%lu`                          | 无符号长整数   |
| `long long`          | `%lld`                         | 长长整数     |
| `unsigned long long` | `%llu`                         | 无符号长长整数  |
| `char`               | `%c`                           | 单个字符     |
| `char[]` (字符串)       | `%s`                           | 字符串      |

## 浮点数格式修饰符

| 格式说明符    | 示例                           | 输出示例             | 说明            |
| -------- | ---------------------------- | ---------------- | ------------- |
| `%f`     | `printf("%f", 3.14159);`     | `3.141590`       | 默认精度(6位小数)    |
| `%.2f`   | `printf("%.2f", 3.14159);`   | `3.14`           | 保留2位小数        |
| `%8.2f`  | `printf("%8.2f", 3.14159);`  | `    3.14`       | 总宽度8，保留2位小数   |
| `%-8.2f` | `printf("%-8.2f", 3.14159);` | `3.14    `       | 左对齐，总宽度8，2位小数 |
| `%e`     | `printf("%e", 1234.56);`     | `1.234560e+03`   | 科学计数法         |
| `%g`     | `printf("%g", 1234.56);`     | `1234.56`        | 自动选择`%f`或`%e` |
| `%a`     | `printf("%a", 1234.56);`     | `0x1.34a3d7p+10` | 十六进制浮点数       |

## 特殊格式说明符

| 格式说明符 | 用途 | 示例 |
|-----------|------|------|
| `%p` | 指针地址 | `printf("%p", &var);` |
| `%x` / `%X` | 十六进制整数 | `printf("%x", 255);` → `ff` |
| `%o` | 八进制整数 | `printf("%o", 64);` → `100` |
| `%%` | 输出%字符 | `printf("折扣: 20%%");` |

## 重要注意事项

```c
#include <stdio.h>

int main() {
    double d;
    float f;
    int i;
    
    // ✅ 正确的用法
    scanf("%lf", &d);   // double 输入用 %lf
    printf("%f", d);    // double 输出用 %f
    
    scanf("%f", &f);    // float 输入用 %f
    printf("%f", f);    // float 输出用 %f
    
    scanf("%d", &i);    // int 输入用 %d
    printf("%d", i);    // int 输出用 %d
    
    return 0;
}
```

## 常用组合示例

```c
#include <stdio.h>

int main() {
    double price = 19.99;
    int quantity = 5;
    char product[] = "Apple";
    
    printf("产品: %s\n", product);
    printf("单价: $%.2f\n", price);
    printf("数量: %d\n", quantity);
    printf("总价: $%.2f\n", price * quantity);
    
    return 0;
}
```

**输出:**
```
产品: Apple
单价: $19.99
数量: 5
总价: $99.95
```

记住：`double`在`scanf`中用`%lf`，在`printf`中用`%f`！