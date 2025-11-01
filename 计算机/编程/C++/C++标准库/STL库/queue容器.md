# C++ STL 中的先进先出(FIFO)容器

在C++标准模板库(STL)中，`std::queue` 是实现先进先出(FIFO)操作的容器适配器。它提供了一种受限的序列接口，专门设计用于FIFO操作。

## std::queue 基本用法

### 头文件
```cpp
#include <queue>
```

### 创建队列
```cpp
std::queue<int> myQueue;
```

### 基本操作
```cpp
// 向队尾添加元素
myQueue.push(10);
myQueue.push(20);
myQueue.push(30);

// 访问队首元素
std::cout << "Front element: " << myQueue.front() << std::endl;  // 输出 10

// 访问队尾元素
std::cout << "Back element: " << myQueue.back() << std::endl;    // 输出 30

// 移除队首元素
myQueue.pop();  // 移除10

// 检查队列是否为空
if (!myQueue.empty()) {
    std::cout << "Queue is not empty" << std::endl;
}

// 获取队列大小
std::cout << "Queue size: " << myQueue.size() << std::endl;  // 输出 2
```

## 底层容器

`std::queue` 是一个容器适配器，默认使用 `std::deque` 作为底层容器，但也可以指定其他容器：

```cpp
// 使用list作为底层容器
std::queue<int, std::list<int>> listQueue;

// 使用deque作为底层容器（默认）
std::queue<int, std::deque<int>> dequeQueue;
```

## 实际应用示例

```cpp
#include <iostream>
#include <queue>
#include <string>

void processOrders() {
    std::queue<std::string> orderQueue;
    
    // 添加订单
    orderQueue.push("Order #1001");
    orderQueue.push("Order #1002");
    orderQueue.push("Order #1003");
    
    // 处理订单
    while (!orderQueue.empty()) {
        std::cout << "Processing: " << orderQueue.front() << std::endl;
        orderQueue.pop();
    }
    
    std::cout << "All orders processed!" << std::endl;
}

int main() {
    processOrders();
    return 0;
}
```

## 注意事项

1. `std::queue` 不提供迭代器，因为它限制了访问方式以保持FIFO顺序
2. 直接访问元素只能通过 `front()` 和 `back()` 方法
3. 删除元素只能从队首使用 `pop()`
4. 添加元素只能在队尾使用 `push()`

## 其他FIFO相关容器

虽然 `std::queue` 是主要的FIFO容器，但 `std::deque` (双端队列)也可以用于FIFO操作，并提供更多灵活性：

```cpp
#include <deque>

std::deque<int> fifoDeque;

// FIFO操作
fifoDeque.push_back(1);  // 入队
fifoDeque.push_back(2);
fifoDeque.pop_front();   // 出队
```

但通常建议使用 `std::queue` 当明确需要FIFO语义时，因为它提供了更清晰的接口意图。