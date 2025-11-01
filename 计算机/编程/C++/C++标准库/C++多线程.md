#C #多线程 #C库   #编程 #标准库 

【【C++教程】国外大佬C++技术教程，油管百万级收藏，学C++看这个就够了！（中文字幕）-哔哩哔哩】 https://b23.tv/e5yhK6O
62集

所需头文件：
```cpp
#include <thread>     // 多线程
#include <mutex>      //互斥锁
```



lock guard


创建线程
```cpp
std::thread 线程名(函数名,参数...)；//函数名后面不要加小括号。
```
创建数组个线程
```cpp
std::thread 线程名[线程数];
线程名[线程数量] = std::thread(函数名,参数,参数....);
```
等待线程加入
```cpp
线程名.join();  //等待此线程完成，堵塞
```
线程加入是一个复杂的东西，这值得更详细地讨论
但在C#等更现代的编程语言中，它被叫做wait或wait for exit。这样其实更加合理。
他所做的就是说“嘿，你能在当前线程上面等待这个线程完成他的的工作吗？”

互斥锁，C++标准库网....
https://en.cppreference.com/w/cpp/thread/mutex/lock

```cpp
std::mutex 互斥锁名;
```
下面的分别是上锁，解锁。
```cpp
互斥锁名.lock();
互斥锁名.unlock();
```
尝试上锁
```cpp
if (互斥锁名.try_lock){
	成功上锁(返回0)
}else{
	上锁失败(返回1)
}
```





















尝试进行加锁，如已被其他线程持有，返 false，否返 true。
```cpp
try_lock()
```

```cpp
#include <iostream>
// 必须的头文件
#include <pthread.h>
 
using namespace std;
 

 
// 线程的运行函数
void* say_hello(void* args)
{
    cout << "Hello Runoob！" << endl;
    return 0;
}
 
int main()
{
    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[5];
    for(int i = 0; i < 5; ++i)
    {
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
           std::cout << "pthread_create error: error_code=" << ret << std::endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}
```



try_lock_for(const std::chrono::duration<Rep, Period>& rel_time)

尝试对互斥量进行加锁操作，如果当前互斥量已经被其他线程持有，则当前线程会被阻塞，直到互斥量被成功加锁，或者超过了指定的时间。

try_lock_until(const std::chrono::time_point<Clock, Duration>& abs_time)：尝试对互斥量进行加锁操作，如果当前互斥量已经被其他线程持有，则当前线程会被阻塞，直到互斥量被成功加锁，或者超过了指定的时间点。

————

unique_lock() noexcept = default：默认构造函数，创建一个未关联任何互斥量的 std::unique_lock 对象。

explicit unique_lock(mutex_type& m)：构造函数，使用给定的互斥量 m 进行初始化，并对该互斥量进行加锁操作。

unique_lock(mutex_type& m, defer_lock_t) noexcept：构造函数，使用给定的互斥量 m 进行初始化，但不对该互斥量进行加锁操作。

unique_lock(mutex_type& m, try_to_lock_t) noexcept：构造函数，使用给定的互斥量 m 进行初始化，并尝试对该互斥量进行加锁操作。如果加锁失败，则创建的 std::unique_lock 对象不与任何互斥量关联。

unique_lock(mutex_type& m, adopt_lock_t) noexcept：构造函数，使用给定的互斥量 m 进行初始化，并假设该互斥量已经被当前线程成功加锁。
