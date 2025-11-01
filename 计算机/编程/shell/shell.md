#编程 #shell #脚本语言
【快速学习shell—15min快速掌握-哔哩哔哩】 https://b23.tv/CjRWKv5


一种命令行脚本工具
可以通过下面这个代码查看支持项
```Linux
cat /etc/shells
```
然后可以如果环境变量来查看默认选项
```Linux
echo $SHELL
```
如果想切换默认直接输入脚步路径即可

可以通过下面这个创建和打开
```Linux
touch test.sh
open test.sh
```

```sh
#!/bin/bash

number = 5 
echo $number
```
支持字符串"this is string"
支持数组(1 2 3 4 5 10)
可以通过 ${名字\[@\]} 来全部打印

支持环境变量

可以通过 名字 = $(ls) 来保存ls的运行结果

默认变量 名字:=参数 =会进行赋值   -不会进行赋值
```sh
echo ${aa:-5}
echo ${bb:=8}
echo $aa
echo $bb
```

特殊变量：
- $#  传入参数个数
- $0  文件名称
- $1  传入参数1
- ....
```sh
echo $0
echo $1
echo $2
echo "参数个数 $#"
```


```sh
if [  条件  ]; then
    代码
else
    
fi
```
中括号旁边要加空格！
if使用fi结束
- -gt   ＞
- 
```sh
for num in 1 2 3 8 5; do
    echo $num
done
```


```sh
num = 0
while (($num < 5)); do
    echo $num
    let "num++"
done
```

```sh
read aNum
case $aNum in
    1) echo ""
    ;;
    2) echo ""
    ;;
    3) echo ""
    ;;
    *) echo ""
    ;;
esac
```

```sh
function iff(){
    if [ $1 -gt $2 ]; then
        echo "大"
    else
        echo "小"
    fi
}

iff 15 46

```

将结果输入到一个文件
```sh
sh test.sh > test.txt
```
使用追加的方式是使用“>>”

输出错误信息
```
sh test.sh 2> error.log
```

两个一块？
```
sh test.sh > 文件名 2>&1
```




