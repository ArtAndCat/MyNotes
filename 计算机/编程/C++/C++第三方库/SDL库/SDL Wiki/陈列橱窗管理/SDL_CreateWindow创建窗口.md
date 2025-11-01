#C #SDL 
返回类型  \*  函数名（参数....）
```cpp
SDL_Window * SDL_CreateWindow(title,x,y,w,h,flags);
```

| 名称    | 作用        |
| ----- | --------- |
| title | 窗口标题（字符串） |
| x     | 坐标        |
| y     | y坐标       |
| w     | 宽         |
| h     | 高         |
| fiags | 下面有       |




#### 备注
flags可以是下列任一或一起：
- SDL_WINDOW_FULLSCREEN：全屏
- SDL_WINDOW_FULLSCREEN_DESKTOP：桌面分辨率的全屏窗口
下面的这个三暂时不管，涉及GPU：（bilibili-花不成57）
- SDL_WINDOW_OPENGL：可用于OpenGL上下文的窗口
- SDL_WINDOW_VULKAN：可用于Vulkan实例的窗口
- SDL_WINDOW_METAL：可用于金属实例的窗口
如果你使用了这三个中的任意一个或多个的话就必须调用下面的这个
[[SDL_DestroyWindow销毁窗口]]
- SDL_WINDOW_HIDDEN：窗口不可见
- SDL_WINDOW_BORDERLESS：无边框
- SDL_WINDOW_RESIZABLE：可以调整窗口大小
- SDL_WINDOW_MINIMIZED：窗口最小化
- SDL_WINDOW_MAXIMIZED：窗口最大化
- SDL_WINDOW_INPUT_GRABBED：窗口攫取了输入焦点
- SDL_WINDOW_ALLOW_HIGHDPI：窗口应该在high-DPI模式下创建（>=SDL 2. 0.1）（bilibili-花不成57）
#### 其他相关








[[SDL_DestroyWindow销毁窗口]]