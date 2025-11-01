#C库 #C #第三方库 #网络 #视频笔记 

作者: 苏丙榅
bilibili教程参考视频： https://b23.tv/wSO5jKq
个人网站链接: https://subingwen.cn/linux/socket/
来源: 爱编程的大丙

```cpp
#include <arpa/inet.h>//网络通讯  里面有socket.h

```
[[arpa_inet.h]]
## 基础知识
[[小贾的课#1 物理层 bit]]
![[计算机/网络基础/2.PNG]]

![[OSI_ISO 网络分层模型]]
tcp/ip
## ？？
socket 传输数据又好几种模式
套接字       对应   UDP 协议
stream流   对应   TCP 协议

```cpp
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
##### 大段与小段

Little-Endian -> 主机字节序 (小端)（机器常用，因为快）
个位 十位 百位 千位
Big-Endian -> 网络字节序 (大端) 
千位 百位 十位 个位





虽然IP地址本质是一个整形数
但是在使用的过程中都是通过一个字符串来描述

可以使用[[arpa_inet.h]]库的东西将一个字符串类型的IP地址进行大小端转换
## 流程

![[Tcp客户端与服务端.jpg|205]]
#### （Linux）
1. 创建用于监听的套接字，这个套接字是一个文件描述符。
```c
int ___ = socket(参数1，传输协议，0);
```
参数1：
- AF_UNIX，AF_LOCAL   本机通信
- AF_INET     IPv4（在window上用 PF_INET 也可以 是等价的）
- AF_INET6   IPv6
传输协议：
- SOCK_STREAM 流式传输协议（TCP）
- SOCK_DGRAM  报式传输协议（UDP）

2. 将得到的监听的文件描述符合本地的IP与端口进行绑定。
```c
bind(用于监听的套接字（int）,*存放ID与端口的结构体（struck，必须是大段）,结构体大小（直接sizeof）);
```
返回值：正确：0    错误：-1。


3. 设置监听  （成功后开始监听，监听的是客户端的连接）
```c
listen(用于监听的套接字，用于指定listen函数最多可以监视多少个连接请求（最大128）);
```
4.  等待并接受客户端的链接请求，建立新的连接，会得到一个新的文件描述符（通信的）（没有新连接请求就阻塞）
```c
int 通讯的文件描述符 = accept(用于监听的套接字，*结构体（下面有）（对应的客户端协议，ip和端口）可以null，*用于描述前一个结构体的大小  可以null);
```
5. 通信读写操作都是阻塞的 [[unistd.h]]  备注掉的是[[C++sys_socket.h]]
```cpp
// 接收数据 //0 断开链接  //-1接收数据失败
read(通讯文件描述符，*指向一块有效的内存地址，大小); //仅Linux
//recv(后面多一个flags 用于指定某些属性  写0就可以了);
// 发送数据
write(略，*只读指针，大小); //仅Linux
// send(你知道的);

//window UDP通信时使用
recvfrom();//接收
sendto();
```
6. 关闭链接   [[unistd.h]]
```cpp
close(文件描述符); //Linux
closesocket(通讯文件描述符);
```


弹幕：
端口可以复用，需要先设置属性，默认是不可复用的
端口可以复用，但是不能两个进程同时用一个端口。


客户端：
1. 和上面第一步一样。
2. 连接服务器（需要知道服务器的IP和端口）
```cpp
connect(套接字，*结构体（略），大小);
```
#### window
```c
#include <winsock2.h>
// 使用的套接字库：   ws2_32.dll
WSAData wsa;
// 成功返0  失败返SOCKET_ERROR。
WSAStartup(MAKEWORD(2,2),&wsa);

//.......

WSACleanup();
```



#### 构造体
sockadder 数据结构：
sockaddr：这个用起来不方便
```c
struct sockaddr {
	sa_family_t sa_family;   //ipv4协议
	char        sa_data[14]; //端口2，ip地址4，填充8
	//目前后面的填充8未被使用
}
```
sockaddr_in
```c
struct sockaddr {
	sa_family_t sa_family;   //ipv4协议
	
	//目前后面的填充8未被使用
}
```
7：38
```c
//   window中 in_addr ：
typedef struct in_addr {
	union {
		struct{unsigned char s_b1,s_b2,s_b3,s_b4;} s_un_b;
		struct{unsigned short s_w1,w_w1;}} S_un_w;
		unsigned long S_addr;    // 存储IP地址
	} S_un;
}IN_ADDR;
//   Linux中  in_addr   ：

```









## 监听与通讯描述符：

每个服务器的监听只有一个
通信的=客户数量

收发函数的原理和收发缓冲区有关
当内核检测到收发缓冲区有数据后就会进行对应的操作。

监听函数如果有连接请求就会执行反之堵塞
通信的也是，如果没有数据就会堵塞。
发送也是，如果发送区满了，写不进去就会堵塞


# 例：
### 服务端：(只能处理一个人，如果是多人的话需要使用多线程)
 https://b23.tv/J5yfHPx  17
```cpp
#include <stdlib.h>    //报错有关
#include <unistd.h>    //延迟
#include <string.h>
#include <arpa/inet.h> //网络通讯

int main(){
	
	// 1. 创建用于监听的套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);// IPv4  tcp协议
	if (fd == -1){
		perror("socket");
		return -1;
	}
	
	// 2. 绑定本地IP和端口
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET; //IPv4
	saddr.sin_port = htons(9999);//大小端转换端口
	saddr.sin_addr.s_addr = INADDR_ANY;//0 = 0.0.0.0
	//所以不用转换   0.0.0.0的话会让系统自动指定一个IP地址
	int ret = bind(fd, (struct sockaddr*)&saddr, sizeof(saddr));
	//这个类型转换是为啥?因为定义的参数类型与变量类型不相同(实际内存相同)，不强转无法通过编译
	if (ret == -1){
		perror("bind");
		return -1;
	}
	
	// 3. 设置监听
	ret = listen(fd, 128); // 套接字  一口能吃多少个
	if(ret == -1){
		perror("listen");
		return 0;
	}
	
	// 4. 阻塞等待客户端连接
	struct sockaddr_in caddr;
	socklen_t addrlen = sizeof(caddr);
	socklen_t cfd = accept(fd, (struct sockaddr*)&caddr, &addrlen);  // 用于通讯的文件描述符
	if (cfd == -1){
		perror("accept");
		return -1;
	}
	//链接建立成功，获取打印客户端的IP和端口信息。
	char ip[32];
	printf("客户端的IP：%s ，端口：%d\n",inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ip, sizeof(ip)),ntohs(caddr.sin_port));
	
	// 5. 通信
	while(1){
		//接收数据
		char buff[1024];
		int len = recv(cfd, buff, sizeof(buff), 0);
		if(len > 0){
			printf("client客户asay说", buff);
			send(cfd, buff, len, 0);
			
		}else if(len == 0){
			printf("客户端已断开链接...\n");
			break;
		}else{
			perror("recv");
			break;
		}
	}
	
	//释放文件标识符
	close(fd);
	close(cfd);
	return 0;
}

```
### 客户端：
```cpp
#include <stdlib.h>    //报错有关
#include <unistd.h>    //延迟
#include <string.h>
#include <arpa/inet.h> //网络通讯
#include <iostream>

int main(){
	
	// 1. 创建用于通讯的套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);// IPv4  tcp协议
	if (fd == -1){
		perror("socket");
		return -1;
	}
	
	// 2. 连接服务器
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET; //IPv4
	saddr.sin_port = htons(9999);//大小端转换端口
	
	//===================
	char aaip[16];
	printf("输入IP地址\n");
	std::cin >> aaip;
	inet_pton(AF_INET, aaip, &saddr.sin_addr.s_addr);
	
	int ret = connect(fd, (struct sockaddr*)&saddr, sizeof(saddr));
	//这个类型转换是为啥?因为定义的参数类型与变量类型不相同(实际内存相同)，不强转无法通过编译
	if (ret == -1){
		perror("connect");
		return -1;
	}
	// 打印自身
	char sip[32];
	printf("IP：%s ，端口：%d\n",inet_ntop(AF_INET, &saddr.sin_addr.s_addr, sip, sizeof(sip)),ntohs(saddr.sin_port));
	
	int number = 0;
	// 3. 通信
	while(1){
		//发送数据
		char buff[1024];
		sprintf(buff, "你好啊啊啊啊，%d...\n", number++);
		send(fd,buff,strlen(buff)+1,0);
		//接收
		memset(buff, 0, sizeof(buff));// 接收前先清空数据
		int len = recv(fd, buff, sizeof(buff), 0);
		if (len > 0){
			printf("server服务器say说", buff);
			
		}else if (len == 0){
			printf("服务器已断开链接...\n");
			break;
		}else{
			perror("recv");//失败了
			break;
		}
		sleep(2);
		
		std::cin << aa; 
	}
	//释放文件标识符
	close(fd);
	return 0;
}
```

# 多线程版   并且客户端与服务器一体化（自制）


```cpp

```














