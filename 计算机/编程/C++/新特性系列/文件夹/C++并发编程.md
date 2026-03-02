#C #编程 #新特性 

# 一  创建线程  (线程发起)
---
1. 普通函数
```cpp
std::thread 线程名(函数名, 参数);
```
     - 注意 函数名不带小括号
2. 仿函数 - 先创建对象再传入
```cpp
类名 对象1;
std::thread t(对象1, ...);
```
3. 仿函数 - 临时对象（花括号解决歧义）
```cpp
std::thread t{类名(), ...};
```
4. 仿函数 - 临时对象（多加括号解决报错）
```cpp
std::thread t((类名()), ...);
```
5. lambda表达式 [[C++lambda表达式]]    `[变量](参数) {函数体}`
```cpp
std::thread t5([](const std::string &msg)
				{ std::cout << "Lambda: " << msg << std::endl; }, "Hello from lambda");
```



# 二  线程等待
---
```cpp
if (线程名.joinable())线程名.join(); // 如果可以等待 就堵塞 等待线程结束
```





# 三  线程detach     分离      守护进程
---
线程允许采用分离的方式在后台独自运行，`C++ concurrent programing`书中称其为守护线程。
```cpp
线程名.detach();
```
注意 < ! > 如果有线程中有引用外界变量  要小心奔溃发生(在线程结束前引用被释放) 
解决方法:
- 通过智能指针传递参数，因为引用计数会随着赋值增加，可保证局部变量在使用期间不被释放，这也就是我们之前提到的伪闭包策略。
- 将局部变量的值作为参数传递，这么做需要局部变量有拷贝复制的功能，而且拷贝耗费空间和效率。
- 将线程运行的方式修改为join，这样能保证局部变量被释放前线程已经运行结束。但是这么做可能会影响运行逻辑。

存在隐患的例子:
```cpp
struct func {
	int& _i;
	func(int & i): _i(i){}
	void operator()() {
		for (int i = 0; i < 3; i++) {
			_i = i;
			std::cout << "_i is " << _i << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
};

void oops() {
	int some_local_state = 0;
	func myfunc(some_local_state);
	std::thread functhread(myfunc);
	//隐患，访问局部变量，局部变量可能会随着}结束而回收或随着主线程退出而回收`
	functhread.detach();
}

// detach 注意事项
oops();
//防止主线程退出过快，需要停顿一下，让子线程跑起来detach
std::this_thread::sleep_for(std::chrono::seconds(1));
```

# [[C++异常处理]]    使用多线程存储数据时!!!!
---
当我们启动一个线程后，如果主线程产生崩溃，会导致子线程也会异常退出，就是调用terminate，==如果子线程在进行一些重要的操作比如将充值信息入库等==，丢失这些信息是很危险的。所以常用的做法是捕获异常，并且在异常情况下保证子线程稳定运行结束后，主线程抛出异常结束运行。
如
```cpp
void catch_exception() {
    int some_local_state = 0;
    func myfunc(some_local_state);           // 创建函数对象
    std::thread functhread{ myfunc };        // 启动新线程执行 myfunc
    
    try {
        // 本线程（主线程）做一些可能引发异常的事情
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // 这里可能有其他可能抛出异常的操作
    }
    catch (std::exception& e) {
        // 如果 try 块中的代码抛出了异常，会执行这里
        functhread.join();  // 等待线程结束
        throw;              // 重新抛出异常，让上层处理
    }
    
    functhread.join();  // 如果没有异常，正常等待线程结束
}
```






# 旧笔记:

![[C++多线程]]

