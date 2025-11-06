	#C #菜单 #编程
其他涉及
[[JNI]]  C++与Android Java互通什么的
[[计算机/编程/C/C|C]]

[[C++黑马教程]]      [[C++ Primer Plus]]
[[C++面向对象 封装  继承  多态]]

[[数据结构与算法]]        [[C++STL库 （标准模板库）]] ==<---==

[[C++多文件编程]]

[[C++如何安装第三方库]]


```cpp
#include <iostream>
using namespace std;

int main(){//程序开始的地方
    cout << "hello world!!!" << endl;//这行代码会输出一串文字
    return 0;//返回0表示程序正常运行结束
}

```
## [[C++关键字]]

外部笔记：[[计算机/外部笔记/notes-master 1/Linux/C++|C++]]
### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">C++异常处理</font></div>

关键字：
`__PRETTY_FUNCTION__`  返回函数名（C++的，C的只有FUN...）
`__LINE__` 返回行数   (继承于C)
比如
```cpp
cout << __PRETTY_FUNCTION__ << ':' << __LINE__;
return -1;
```
### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">C++新特性</font></div>

[[C++新特性教程]]
![[C++新特性]]


### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">C++标准库</font></div>

[[C++iostream标准输入输出流]]
[[C++随机数]]
[[C++文件读写]]
[[C++数学]]
[[C++多线程]]
[[C++延迟]]
[[C++STL库 （标准模板库）]]  ==<---==
[[C++网络]]
[[C++functional库]]  调用非静态函数  C++11
[[C++数据交换]]

### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">C++三方库</font></div>

图形库：


[[C++SDL]]    [[C++SDL3]]
网络库：
[[C++sys_socket.h]]




### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">未分类的函数</font></div>


```cpp
typeid(变量名).name()  // 获取数据类型
```


数字转char类型字符串  
```cpp
snprintf(strNumber, sizeof(strNumber), "%d", number);
```

```cpp
const std::string stringA = .....;
snprintf(buffer, sizeof(buffer), stringA.c_str(), i);
```

【C++基础补充  C++标准库速览-哔哩哔哩】 https://b23.tv/zDFHB4K
三路比较   C++20添加    然后把原来的<,\=\=,> 移除了  用 \[数据丢失] 来代替



写变量一定要初始化！要不然你会碰到 UB  


```
  
// 点科技蜡烛,烧电子纸钱,敲智能木鱼
//
// 拜代码佛祖,取前端真经,得享永无 BUG 之福
//
// ................ 阿耨多罗三藐三菩提 .................
//
//                        _oo0oo_
//                       o8888888o
//                       88" . "88
//                       (| -_- |)
//                       0\\ = //0
//                     ___/‘---’\\___
//                  .' \\|        |/ '.
//                 / \\\\|||  :   |||// \\             
//                / _|||||   -卍- |||||_ \\              
//               |   | \\\\\\  -  /// |   |
//               | \\_|  ''\\---/''   |_/ |
//               \\  .-\\__  '-'  ___/-. /
//             ___'. .'   /--.--\\  '. .'___
//          ."" ‘<   ‘.___\\_<|>_/___.’>’  "".
//         ​| | :  ‘- \\‘.;‘\\ _ /’;.’/ - ’ : | |
//         \\  \\ ‘_. \\_ __\\ /__ _/   .-’ /  /
//    =====‘-.____‘.___ \\_____/___.-’___.-’=====
//                       ‘=---=’
//
// ................. 佛祖保佑 永无 BUG ................
```

```
//                    ::
//                   :;J7, :,                        ::;7:
//                   ,ivYi, ,                       ;LLLFS:
//                   :iv7Yi                       :7ri;j5PL
//                  ,:ivYLvr                    ,ivrrirrY2X,
//                  :;r@Wwz.7r:                :ivu@kexianli.
//                 :iL7::,:::iiirii:ii;::::,,irvF7rvvLujL7ur
//                ri::,:,::i:iiiiiii:i:irrv177JX7rYXqZEkvv17
//             ;i:, , ::::iirrririi:i:::iiir2XXvii;L8OGJr71i
//           :,, ,,:   ,::ir@mingyi.irii:i:::j1jri7ZBOS7ivv,
//              ,::,    ::rv77iiiriii:iii:i::,rvLq@huhao.Li
//          ,,      ,, ,:ir7ir::,:::i;ir:::i:i::rSGGYri712:
//        :::  ,v7r:: ::rrv77:, ,, ,:i7rrii:::::, ir7ri7Lri
//       ,     2OBBOi,iiir;r::        ,irriiii::,, ,iv7Luur:
//     ,,     i78MBBi,:,:::,:,  :7FSL: ,iriii:::i::,,:rLqXv::
//     :      iuMMP: :,:::,:ii;2GY7OBB0viiii:i:iii:i:::iJqL;::
//    ,     ::::i   ,,,,, ::LuBBu BBBBBErii:i:i:i:i:i:i:r77ii
//   ,       :       , ,,:::rruBZ1MBBqi, :,,,:::,::::::iiriri:
//  ,               ,,,,::::i:  @arqiao.       ,:,, ,:::ii;i7:
// :,       rjujLYLi   ,,:::::,:::::::::,,   ,:i,:,,,,,::i:iii
// ::      BBBBBBBBB0,    ,,::: , ,:::::: ,      ,,,, ,,:::::::
// i,  ,  ,8BMMBBBBBBi     ,,:,,     ,,, , ,   , , , :,::ii::i::
// :      iZMOMOMBBM2::::::::::,,,,     ,,,,,,:,,,::::i:irr:i:::,
// i   ,,:;u0MBMOG1L:::i::::::  ,,,::,   ,,, ::::::i:i:iirii:i:i:
// :    ,iuUuuXUkFu7i:iii:i:::, :,:,: ::::::::i:i:::::iirr7iiri::
// :     :rk@Yizero.i:::::, ,:ii:::::::i:::::i::,::::iirrriiiri::,
//  :      5BMBBBBBBSr:,::rv2kuii:::iii::,:i:,, , ,,:,:i@petermu.,
//       , :r50EZ8MBBBBGOBBBZP7::::i::,:::::,: :,:,::i;rrririiii::
//           :jujYY7LS0ujJL7r::,::i::,::::::::::::::iirirrrrrrr:ii:
//        ,:  :@kevensun.:,:,,,::::i:i:::::,,::::::iir;ii;7v77;ii;i,
//        ,,,     ,,:,::::::i:iiiii:i::::,, ::::iiiir@xingjief.r;7:i,
//     , , ,,,:,,::::::::iiiiiiiiii:,:,:::::::::iiir;ri7vL77rrirri::
//      :,, , ::::::::i:::i:::i:i::,,,,,:,::i:i:::iir;@Secbone.ii:::
```

```
//            .::::..         .::::..
//           ::::rrr7QQJi::i:iirijQBBBQB.
//           BBQBBBQBP. ......:::..1BBBB
//           .BuPBBBX  .........r.  vBQL  :Y.
//            rd:iQQ  ..........7L   MB    rr
//            7biLX .::.:....:.:q.  ri    .
//            JX1: .r:.r....i.r::...:.   gi5
//           ..vr  .7: 7:. :ii:  v.:iv  :BQg
//           : r:  7r:i7i::ri:DBr..2S
//           i.:r:. .i:XBBK...  :BP ::jr   .7.
//           r  i....ir r7.         r.J:   u.
//          :..X: .. .v:           .:.Ji
//         i. ..i .. .u:.     .   77: si   1Q
//         ::.. .r .. :P7.r7r..:iLQQJ: rv   ..
//       7  iK::r  . ii7r LJLrL1r7DPi iJ     r
//         .  ::.:   .  ri 5DZDBg7JR7.:r:   i.
//    .Pi r..r7:     i.:XBRJBY:uU.ii:.  .
//    QB rJ.:rvDE: .. ri uv . iir.7j r7.
//   iBg ::.7251QZ. . :.      irr:Iu: r.
//    QB  .:5.71Si..........  .sr7ivi:U
//    7BJ .7: i2. ........:..  sJ7Lvr7s
//         jBBdD. :. ........:r... YB  Bi
//            :7j1.                 :  :
```

