#C #第三方库 #图形 #C库 #视频笔记 #SDL #自制笔记




材质=材质导入函数（图片路径）

加载纹理
```cpp
SDL_Surface* i = IMG_Load("aaa.png");
SDL_Texture* 纹理 = SDL_CreateTextureFromSurface(渲染器, i);
```
记得销毁
```cpp
SDL_Destroy类型(指针)
```
加载到屏幕
```cpp
SDL_RenderCopy(渲染器, 纹理, NULL（&裁剪矩形）, NULL（&位置矩形）);
```
加载到屏幕（增强版）
```cpp
SDL_RenderCopyEx(渲染器, 图片texture, &裁剪大小, &位置大小, 旋转角度（角度制）,旋转的中心点（NULL表示中心点）,关于反转);
```

关于反转：
- SDL_FLIP_HORIZONTAL
- SDL_FLIP_VERTICAL
- SDL_FLIP_NONE    不反转