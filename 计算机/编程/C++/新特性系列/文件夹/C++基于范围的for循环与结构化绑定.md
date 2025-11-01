#C #编程 #新特性 



基于范围的for循环
```cpp
for (容器类型 名字 : STL容器){  }
```
如
```cpp
#include <vector>
#include <iostream>

int main() {
	int ii = 4;
    std::vector<int> vec = {1, 2, 3};
    for (int i = 0; i<10;i++){
    	// 看这里！看这里！
    	for (int x : vec) {
    	    std::cout << x << " ";
    	}
    	std::cout << "\n \n";
    	vec.push_back(ii);
    	++ii;
    }
    
    return 0;
}
```



结构化绑定
```cpp
for (auto [test1，test2] ： map容器){   }
```