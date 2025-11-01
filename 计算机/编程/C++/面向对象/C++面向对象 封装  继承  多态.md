#黑马教程 #C #封装 #继承 #多态 #菜鸟教程


# 封装

[[C++黑马教程#^f8c848]]

```cpp
class className{       // 这是个类
public:
    int number = 0;    //类 属性
    void helloWorld(){ // 行为
        std::cout << "你觉得我会输出helloWorld？" << number << std::endl;
    }    
};

int main(){
    className targetName;    //实例化（通过类创建对象的）
    
    targetName.number++;     //调用对象的变量
    targetName.helloWorld(); //调用对象的函数
    //剩下的懒得写了
}
```

# 继承

^baddb0

[菜鸟教程](https://www.runoob.com/cplusplus/cpp-inheritance.html)

```cpp
class 类名 :virtual（可选） 继承方式 类名 , ..... {
	//上面的可选项可以防止菱形继承问题。
}
```
###### 继承方式？黑马-46

^d643b9

- public  （不改变）
- protect（除了私有其他全保护）
- private （全私有）

注意：父级的私有在继承后不可见（不可见  不可用  会被继承并且占用空间）弹幕：可以用指针进行修改   我：？？？  47  
标记：#vs开发人员命令提示符
^397f1d

```cpp
// 基类
class 动物 {
	 void eat(){};
	 void sleep(){};
};
//...
class 女 {
	void 你干嘛~
	void 哎你看~
	//略...
}
//派生类
class 狗 : virtual public 动物{
	 void bark();//狗叫
};
class 人 : virtual public 动物{
	void 思考();
};
class 贾书奇 : public 狗, private 女{
	void 内卷();
	void eat(){
		
	}
}
```

# 多态

类别：
- 静态多态：函数重载 和 运算符重载 属于 静态多态，复用函数名。
- 动态多态：派生类 和 虚函数 实现 运行时 多态
区别：
- 静态多态：编译  阶段确定函数地址。
- 动态多态：运行  阶段确定函数地址。
#### 基本语法
还是上面的代码但加上这个
```cpp
void eat(动物 对象名){
	对象名.eat();
}
```
然后使用下面的代码你会发现编译器没有报错
```cpp
贾书奇（类） 贾书奇 （对象名）;
eat(贾书奇);
```
但运行这个的话调用的是动物的eat  不是贾书奇的eat  这就叫早绑定静态多态（编译阶段就确认了函数的地址）
怎么办？答：“动态多态”
在动物的eat函数前面加一个  ==virtual==  变为虚函数
```cpp
class 动物{
	virtual void eat(){}; 
};
```

#### 原理(黑马：必须掌握的内容)
加了 virtual 关键字后函数从1个字节变成了4个字节
多出来的是什么呢？答：指针
写完 virtual 代码后里面会出现一个指针，指针名字叫
vfptr   Virtual Function Pointer  虚拟 函数 指针
他会指向  vftable  虚 函数 表  中。
这个表中记录着   &动物::eat();   （类型：地址）

然后我们写一个猫并且继承这个类
```cpp
class cat : public 动物{
	
}
```
这时cat中的虚函数表\=\=动物的虚函数表
如果再加上这个代码：
```cpp
virtual void eat(){}; //这是个虚函数，因为前面有virtual
```
这时上面的  虚函数地址  就会覆盖原理的  虚函数地址
黑马：当子类重写父类的虚函数，子类中的虚函数表内部会替换成子类的虚函数地址  10：15
```cpp
void giveMeEat (动物 对象名){
	对象名.eat();
}
```
标记：#vs开发人员命令提示符  54- 14：00


[[C++黑马教程#纯虚函数和抽象类 56]]

