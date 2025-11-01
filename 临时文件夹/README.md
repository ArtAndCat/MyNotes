## Object pool allocator

This is a C++11 implementation of an object pool allocator.

For more information on object pool allocators and their purpose see 
http://gameprogrammingpatterns.com/object-pool.html.

Both a fixed size pool (`FixedObjectPool`) and a dynamically growing pool
(`DynamicObjectPool`) implementation are included.

The main features of this implementation are:
* `new_object` method uses C++11 std::forward to pass construction arguments
  to the constructor of the new object being created in the pool
* `for_each` method will iterate over all live objects in the pool calling
  the given function on them
* `delete_all` method will free all pool objects at once, skipping the
  destructor call for trivial types
* maintains a freelist of next available pool entry for fast allocation

These object pool classes are not designed with exceptions in mind as most
game code avoids using exceptions.

## Example usage

```cpp
// some type to be pooled
struct Enemy {
/* some data */
Enemy(const char* name);
void update(double delta_time);
};

// created fixed size pool with space for 64 enemies
FixedObjectPool<Enemy> enemy_pool(64);

// allocate an enemy - construction parameters are forwarded
Enemy* baddie = enemy_pool.new_object("The Mekon");

// update all live enemies by executing the lambda on all allocated objects
enemy_pool.for_each([delta_time](Enemy* enemy)
    {
        enemy->update(delta_time);
    });

// delete a single enemy
enemy_pool.delete_object(baddie);

// delete all enemies at once (beware of dangling pointers)
enemy_pool.delete_all();
```

## Implementation details

Both `FixedObjectPool` and `DynamicObjectPool` are implemented using the
`ObjectPoolBlock` class.

`ObjectPoolBlock` is a single allocation containing the `ObjectPoolBlock`
instance, indices of used pool entries and the pool memory itself.

Occupancy is tracked using indexes into available entries in the block for
constant time allocation. The `ObjectPoolBlock` keeps the next free index head.
This index can be used to find the next available block entry when allocating
a new entry.

A separate list of indices is used to track occupancy versus reusing object
pool memory for this purpose to avoid polluting CPU caches with objects which
are deleted and thus no longer in use.

## Unit testing

Unit tests are written using the [Catch](https://github.com/philsquared/Catch)
unit testing framework. Unit tests are run through the `runtest` executable.

## Micro-benchmarking

This repository also includes `bench.hpp` which is a single header file
micro-benchmarking framework inspired by Catch and Rust's
[benchmarking tests](https://doc.rust-lang.org/book/benchmark-tests.html).

It's my intention to make this standalone at some point but at the
moment it's very much a work in progress.

Currently each micro-benchmark compares the performance of the following:
* Fixed pool
* Dynamic pool with 64, 128 and 256 entry blocks
* The default allocator

Benchmarks output nanoseconds per iteration (lower is better) and megabytes per
second throughput (higher is better).

## Prerequisites

The test and benchmarking applications require [CMake](http://www.cmake.org) to
generate build files.

## Compiling and running

To generate a build, compile and run follow these steps:

~~~
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./runtests
./runbench
~~~

## License

This software is licensed under the zlib license, see the LICENSE file for
details.


## 对象池分配器

这是一个基于C++11的对象池分配器实现。

有关对象池分配器及其用途的更多信息，请参见 http://gameprogrammingpatterns.com/object-pool.html。

该实现包含了固定大小的对象池（`FixedObjectPool`）和动态增长的对象池（`DynamicObjectPool`）两种。

此实现的主要特点：
- `new_object`方法使用C++11的std::forward将构造参数传递给池中新创建对象的构造函数
- `for_each`方法会遍历池中所有活跃对象，并对它们调用给定的函数
- `delete_all`方法会一次性释放池中所有对象，对于平凡类型会跳过析构函数调用
- 维护一个可用对象的链表，以便快速分配下一个可用的池项

这些对象池类的设计没有考虑异常处理，因为大多数游戏代码会避免使用异常。

## 示例用法

```cpp
// 要放入池中的某种类型
struct Enemy {
/* 一些数据 */
Enemy(const char* name);
void update(double delta_time);
};

// 创建一个固定大小的池，可容纳64个敌人
FixedObjectPool<Enemy> enemy_pool(64);

// 分配一个敌人——构造参数会被转发
Enemy* baddie = enemy_pool.new_object("The Mekon");

// 通过对所有已分配对象执行lambda来更新所有活跃的敌人
enemy_pool.for_each([delta_time](Enemy* enemy)
    {
        enemy->update(delta_time);
    });

// 删除单个敌人
enemy_pool.delete_object(baddie);

// 一次性删除所有敌人（注意悬垂指针）
enemy_pool.delete_all();
```

## 实现细节

`FixedObjectPool`和`DynamicObjectPool`都是通过`ObjectPoolBlock`类实现的。

`ObjectPoolBlock`是一个单独的分配块，包含`ObjectPoolBlock`实例、已使用池项的索引以及池内存本身。

通过可用池项的索引来跟踪占用情况，以实现常量时间分配。`ObjectPoolBlock`会记录下一个空闲索引的头部。在分配新项时，可使用该索引找到下一个可用的块项。

使用单独的索引列表来跟踪占用情况，而非为此目的重用对象池内存，以避免因已删除且不再使用的对象而污染CPU缓存。

## 单元测试

单元测试使用[Catch](https://github.com/philsquared/Catch)单元测试框架编写。可通过`runtest`可执行文件运行单元测试。

## 微基准测试

该仓库还包含`bench.hpp`，这是一个单头文件的微基准测试框架，灵感来自Catch和Rust的[基准测试](https://doc.rust-lang.org/book/benchmark-tests.html)。

我打算在某个时候将其独立出来，但目前它还处于开发中。

目前，每个微基准测试都会比较以下内容的性能：
- 固定大小的对象池
- 具有64、128和256个项的动态对象池
- 默认分配器

基准测试会输出每次迭代的纳秒数（数值越小越好）和每秒的兆字节吞吐量（数值越大越好）。

## 先决条件

测试和基准测试应用程序需要[CMake](http://www.cmake.org)来生成构建文件。

## 编译和运行

要生成构建、编译并运行，请按照以下步骤操作：

~~~
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./runtests
./runbench
~~~

## 许可证

本软件采用zlib许可证授权，详情参见LICENSE文件。

内容由 AI 生成
