# 初始化SDL库
### 语法：
```cpp
int SDL_Init(Uint32 flags);
```
### 返回值：
成功时返回0，失败时返回负错误代码；调用SDL_GetError欲了解更多信息。
### 参数：
flags:（一个或者多个，用“ | ”分割）
- `SDL_INIT_TIMER`：计时器子系统
- `SDL_INIT_AUDIO`：音频子系统
- `SDL_INIT_VIDEO`：视频子系统；自动初始化事件子系统
- `SDL_INIT_JOYSTICK`：操纵杆子系统；自动初始化==event==子系统
- `SDL_INIT_HAPTIC`：触觉（力反馈）子系统
- `SDL_INIT_GAMECONTROLLER`：控制器子系统；自动初始化操纵杆子系统
- `SDL_INIT_EVENTS`：活动子系统
- `SDL_INIT_EVERYTHING`：上述所有子系统
- `SDL_INIT_NOPARACHUTE`：不初始化子系统
### 备注
SDL_Init简单地转发SDL_InitSubSystem()。因此，两者可以互换使用。但是为了代码的可读性SDL_InitSubSystem()可能是首选。

文件I/O(例如：SDL_RWFromFile)和穿线(SDL_CreateThread)默认情况下初始化子系统。留言框SDL_ShowSimpleMessageBox还尝试在不初始化视频子系统的情况下工作，希望在显示错误对话框时有用SDL_Init失败了。如果在应用程序中使用其他子系统，则必须专门初始化它们。

伐木如SDL_Log）也可以在没有初始化的情况下工作。
### 版本
这个函数从SDL 2. 0.0开始可用。
### 相关
[[SDL_InitSubSystem]]   可以和SDL_Init互换使用应该没有讲翻译的必要
[[SDL_Quit]]        退出
[[SDL_SetMainReady]]  看不懂，但感觉用不到，懒得翻译了。
[[SDL_WasInit]]    获取当前初始化的指定子系统的掩码？不懂，不翻。

