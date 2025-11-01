这个的一本C++的书 但知识比黑马教程的多和不同（大纲不同）只好新建文件夹了

## 7.10 函数指针
### 7.10.3 深入探讨函数指针 p201

```cpp
#include <iostream>

const double * f1(const double ar[] ,int n);
const double * f2(const double [] ,int);
const double * f3(const double * ,int);

int main(){//程序开始的地方
	using namespace std;
	double av[3] = {1353.35, 35.135456, 453.11};
	// pointer to a function
	const double *(*p1) (const double * ,int ) = f1;
	
	auto p2 = f2;
	
	cout << "测试" << endl;
	cout << "Address value" << endl;
	cout << (*p1)(av,3) << " " << *(*p1)(av,3) << endl;
	cout << p2(av,3) << " " << *p2(av,3) << endl;
	
	// pa an array of pointers
	// auto doesn't work with list initialization
	
	const double *(*pa[3])(const double *, int ) = {f1, f2, f3 };
	
	// 但
	// pb a pointer to first element of pa
	auto pb = pa;
	
	// pre-c++11 can use the following code instead
	// const double *(**pb)(const double *, int ) = pa;
	// 未完工
	return 0;//返回0表示程序正常运行结束
}

  
  
  
  

const double * f1(const double ar[] ,int n){
	return ar;
}

const double * f2(const double ar[] ,int n){
	return ar + 1;
}

const double * f3(const double * ar ,int n){
	return ar + 2;
}


```

