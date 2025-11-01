#C #随机数 #C库  #编程 #标准库 



头文件：
```cpp
#include <cstdlib>
#include <ctime>
```
设置种子
```cpp
srand(time(NULL));//记录时间
```
根据种子生成随机数
```cpp
double x = (double) rand() / RAND_MAX;
int y = rand() % 10;                //生成0到9之间的整数
```

###### 例子：
```cpp
//这个代码将生成10个5~10的随机数字
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));//记录时间
    for(int i = 0;i<10;++i){//循环10次
        double x = (double) rand() / RAND_MAX;
        int y = (rand() % 6)+5;   //生成5到10之间的整数-
        
        std::cout << y << "\n";//输出这个数字
    }
    std::cout << "程序下班了（结束了）";
    return 0;
}
```
###### 函数版本：
```cpp
#include <cstdlib>
#include <ctime>

int randomNnm(int max = 2,int d = 0){
	double x = (double) rand() / RAND_MAX;
    int y = (rand() % max) + d;   //生成5到10之间的整数
}
// 记得在主函数中添加 srand(time(NULL));//记录时间
```


###### 不重复版本


