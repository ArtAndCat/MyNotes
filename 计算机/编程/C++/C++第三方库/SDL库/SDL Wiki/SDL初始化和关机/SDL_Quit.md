# 清理所有初始化的子系统。
### 语法
```cpp
void SDL_Quit(void);
```
### 备注
即使已经用SDL_QuitSubSystem（）。即使在初始化出错的情况下调用这个函数也是安全的。

如果使用对子系统的init函数的调用来启动子系统（例如SDL_VideoInit（）而不是SDL_Init或SDL_InitSubSystem则必须使用子系统的退出函数SDL_VideoQuit呼叫前关机SDL_Quit（）。但通常，无论如何都不应该直接使用这些函数；使用SDL_Init相反。

您可以将此函数与atexit（）一起使用，以确保在应用程序关闭时运行它，但是从库或其他动态加载的代码中执行此操作是不明智的。
### 版本
这个函数从SDL 2. 0.0开始可用。
### 相关
[[SDL_Init]]
[[SDL_QuitSubSystem]]