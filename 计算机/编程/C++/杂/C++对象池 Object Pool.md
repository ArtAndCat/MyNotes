对象池是一种设计模式，用于管理一组预先初始化的可重用对象，而不是频繁地创建和销毁对象。
## 核心思想
- 预先创建一组对象并保存在池中
- 当需要对象时从池中获取
- 使用完毕后将对象归还池中而非销毁
- 避免频繁的内存分配和释放操作
## 为什么使用对象池
1. **性能优化**：减少 new/delete 或 malloc/free 的开销
2. **内存稳定**：避免内存碎片
3. **资源控制**：限制同时使用的对象数量
4. **初始化成本**：对于初始化代价高的对象特别有用
## C++ 简单实现示例

```cpp
#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class ObjectPool {
public:
    ObjectPool(size_t initialSize) {
        for (size_t i = 0; i < initialSize; ++i) {
            pool_.push_back(std::make_unique<T>());
        }
    }

    std::unique_ptr<T> acquire() {
        if (pool_.empty()) {
            // 池为空时创建新对象（或抛出异常/返回nullptr）
            return std::make_unique<T>();
        }
        
        std::unique_ptr<T> obj = std::move(pool_.back());
        pool_.pop_back();
        return obj;
    }

    void release(std::unique_ptr<T> obj) {
        // 可选：重置对象状态
        pool_.push_back(std::move(obj));
    }

    size_t size() const {
        return pool_.size();
    }

private:
    std::vector<std::unique_ptr<T>> pool_;
};

// 使用示例
class Connection {
public:
    void connect() { std::cout << "Connecting...\n"; }
    void disconnect() { std::cout << "Disconnecting...\n"; }
};

int main() {
    ObjectPool<Connection> pool(5);
    
    auto conn1 = pool.acquire();
    conn1->connect();
    // 使用连接...
    pool.release(std::move(conn1));
    
    std::cout << "Pool size: " << pool.size() << std::endl;
    
    return 0;
}
```

## 高级实现考虑

1. **线程安全**：添加互斥锁实现多线程安全
2. **对象状态重置**：在释放时重置对象内部状态
3. **池大小限制**：设置最大池大小
4. **对象验证**：检查归还的对象是否有效
5. **自定义分配器**：控制内存分配方式

## 实际应用场景

- 数据库连接池
- 网络套接字池
- 游戏开发中的子弹、敌人对象
- 任何创建/销毁成本高的对象

对象池模式特别适合性能敏感的场景，但要注意不要过早优化，只有在性能分析表明对象创建是瓶颈时才使用。


[[临时文件夹/README|README]]