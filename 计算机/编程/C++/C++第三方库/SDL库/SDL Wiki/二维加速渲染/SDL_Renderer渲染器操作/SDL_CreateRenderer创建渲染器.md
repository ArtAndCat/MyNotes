#C #SDL 

```cpp
SDL_Renderer * SDL_CreateRenderer(SDL_Window,-1,硬件加速)
```


| 名字    |                            |
| ----- | -------------------------- |
| SDL.. | 屏幕指针                       |
| -1    | 和GPU提供的渲染引擎有关，-1表示第一个，写就对了 |
| 硬件加速  | 看吧下面                       |

#### 注释
硬件加速？
- SDL_RENDERER_SOFTWARE      软件加速
- SDL_RENDERER_ACCELERATED 使用硬件加速（使用GPU）
- SDL_RENDERER_PRESENTVSYNC 和刷新率同步
- SDL_RENDERER_TARGETTEXTTURE  和纹理有关





#### 相关
SDL_GetRendererInfo  获取渲染器信息(info\:Information(信息))