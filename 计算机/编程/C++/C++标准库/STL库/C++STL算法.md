#C库   #编程 #标准库 #C #stl库 #算法 

算法分为“质变算法”和“非质变算法”。
  - 质变算法：   运算过程中  ==会==  更改元素的内容 
  -                     如：拷贝，替换，删除....
  - 非制表算法：运算过程中==不会==更改元素的内容
  -                     如：查找，计数，遍历，寻找极值....


最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
```cpp
#include <algorithm>
```
体积很小，只包括几个在序列上面进行简单数学运算的模板函数
```cpp
#include <functional>
```
定义了一些模板类,用以声明函数对象。
```cpp
#include <numeric>
```



#### 常用遍历

遍历  有点类似70亿人里的寻视
```cpp
for_each(起始迭代器指针, iterator end, 函数地址);  
```

如果是函数直接给函数名即可（不用加括号）
但如果是个仿函数就需要加


```cpp
transform(iterator beg1, iterator end1, iterator beg2, _func);
```

上面的分别是  1开始  1结束  2开始  函数地址
别忘了提前开辟空间！使用这个
```cpp
目标容器.resize(容器.size());
```


#### 常用查找

```cpp
find(iterator beg, iterator end, value要查找的元素);
```
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// 找到后就会返回对应的值，然后直接结束

条件查找：
```cpp
find_if(iterator beg, iterator end, _Pred); 
```
// 返回布尔型的函数/仿函数 遍历传入？

```cpp
adjacent_find(iterator beg, iterator end);  
```
// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器

```cpp
bool binary_search(iterator beg, iterator end, value); 
```
二分查找，查找是否存在指定元素  无序列表不可用

```cpp
count(iterator beg, iterator end, value);  
```
统计元素个数

```cpp
count_if(iterator beg, iterator end, _Pred);  
```
按照条件统计元素个数



#### 常用排序

```cpp
sort(iterator beg, iterator end, _Pred);  
```
默认从小到大    代码里填写了`greater<int>()`然后就从大到小了

```cpp
random_shuffle(iterator beg, iterator end);  
```
打乱顺序

```cpp
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
```
  // 容器元素合并，并存储到另一容器中（有顺序的合并）
  // 注意: 两个容器必须是**有序的**   别忘了开辟空间
  // dest    目标容器开始迭代器

```cpp
reverse(iterator beg, iterator end);  
```
容器反转

#### 常用拷贝和替换算法

```cpp
copy(iterator beg, iterator end, iterator dest目标起始位置);  
```
记得开辟空间

```cpp
replace(iterator beg, iterator end, oldvalue, newvalue);  
```
将容器内指定范围的oldvalue修改为newvalue

```cpp
replace_if(iterator beg, iterator end, _pred, newvalue);  
```
将区间内满足条件的元素，替换成newvalue

```cpp
swap(container c1, container c2);  
```
交换两个容器  注意数据类型，记得开辟空间。

#### 算术生成算法

```cpp
#include <numeric>
```

```cpp
accumulate(iterator beg, iterator end, value);  
```
// 计算容器元素累计总和   注意：value是起始值

```cpp
fill(iterator beg, iterator end, value);  
```
填充 


#### 常用集合算法

```cpp
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  
```
 交集  注意：需要是有序序列 最后一个是 目标容器的开始迭代器

```cpp
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
```
并集  注意点和上面一样

```cpp
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  
```
差集  注意点和上面一样




#### 哦..天...终于结束了...（花费2天左右）

