#C #C库 #标准库 #网络 #编程 

作者: 苏丙榅
链接: https://subingwen.cn/linux/socket/
来源: 爱编程的大丙


头文件：
```cpp
#include <arpa/inet.h>//编译器自带！？？？啊？？？
```
## 字符与整的转换
#### 字符  转  整  
```cpp
// 主机字节序的IP地址转换为网络字节序
// 主机字节序的IP地址是字符串, 网络字节序IP地址是整形
int inet_pton(int af, const char *src, void *dst); 
```
###### 参数:
- af: 地址族(IP地址的家族包括ipv4和ipv6)协议
    - AF_INET: ipv4格式
    - AF_INET6: ipv6格式
- src: 传入参数, 对应要转换的点分十进制的ip地址: 192.168.1.100
- dst: 传出参数, 函数调用完成, 转换得到的大端整形IP被写入到这块内存中
###### 返回值：成功返回1，失败返回0（第二个参数有问题）或者-1（第一个参数有问题）
#### 整  转  字符 
```cpp
// 将大端的整形数, 转换为小端的点分十进制的IP地址        
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
```
###### 参数:
- af: 地址族协议
    - AF_INET: ipv4格式的ip地址
    - AF_INET6: ipv6格式的ip地址
- src: 传入参数, 这个指针指向的内存中存储了大端的整形IP地址
- dst: 传出参数, 存储转换得到的小端的点分十进制的IP地址
- size: 修饰dst参数的, 标记dst指向的内存中最多可以存储多少个字节
###### 返回值:
- 成功: 指针指向第三个参数对应的内存地址, 通过返回值也可以直接取出转换得到的IP字符串
- 失败: NULL
#### 更多但只支持IPv4  （弹幕：直接使用会出现警告提示）
还有一组函数也能进程IP地址大小端的转换，但是只能处理ipv4的ip地址：
```cpp
// 点分十进制IP -> 大端整形
in_addr_t     inet_addr(const char *cp);  //Linux
unsigned long inet_addr(const char FAR * cp);//window
// 大端整形 -> 点分十进制IP
char* inet_ntoa(struct in_addr in);//都可用
```
## 主机字节序与网络字节序
```c
#include <arpa/inet.h>
// u  : unsigned
// 16 : 16位, 32: 32位
// h  : host, 主机字节序
// n  : net, 网络字节序
// s  : short
// 1  : int

// 这套api主要用于 网络通信过程中 IP和 端口 的转换
// 将一个短整形从主机字节序->网络字节序
uint16_t htons(uint16_t hostshort);
// 将一个整形从主机字节序->网络字节序
uint32_t htonl(uint32_t hostlong);
// 将一个短整形从网络字节序->主机字节序
uint16_t ntohs(uint16_t netshort);
// 将一个整形从网络字节序->主机字节序
uint32_t ntohl(uint32_t netlong);
//window的话是把 uint16_t -> u_short   32 ->  u_long
```








