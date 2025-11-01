#stl库 #C #C库 #标准库 #编程 

字符串  本质是一个类


#### 头文件：
```cpp
#include<string>
```


#### 创建
```cpp
string 名字;
```
- 更多用法：
```cpp
string 名字(名字1);
string 名字(数字,char)//用数字个char初始化string
//  太多了！！看原视频吧
```
- 名字1可以是char类型也可以是string类型
#### 拼接（+=什么的就不写了，这里只写个特殊的）
```cpp
名字.append(string &s,int pos,int n);//字符串s中从pos开始的n个字符链接到字符串结尾
```
#### 查找
查找“名字”第一次出现的位置，从pos开始找
```cpp
名字.find(名字1,int pos = 0);
```
- 返回类型为 int
- 名字1可以是char类型也可以是string类型

查找“名字”最后一次出现的位置，从pos开始找
```cpp
名字.rfind(名字1,int pos = 0);
```
- 返回类型为 int
- 名字1可以是char类型也可以是string类型
#### 替换
替换从pos开始的n字符为字符串“名字”
```cpp
名字.replace(int pos, int n,名字1);
```
- 名字1可以是char类型也可以是string类型

#### 对比 （按照ASCII码进行比较）
```cpp
名字.compare(名字1);
```
返回值：
-  = 返回  0
-  < 返回  -1
-  > 返回  1
备注：
- 名字1可以是char类型也可以是string类型

#### 获取
```cpp
名字[n]
```
或者
```cpp
名字.at(int n);
```
返回字符串中的第n个字符

#### 插入
```cpp
名字.insert(int pos,int n,名字1);
```



#### 删除
```cpp
名字.insert(int pos,int n);
```
从pos开始删除n个字符



#### 从字符串中截取一段字符串

```cpp
名字.substr(int pos = 0,int n = 整个)
```

