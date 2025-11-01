#编程 #C #第三方库 #图形 #C库 #视频笔记 #SDL #自制笔记 #ttf

【SDL_TTF_Latin字符显示-哔哩哔哩】 https://b23.tv/YbEibB3
#### 头文件：
```cpp
#include <SDL_ttf.h>
```

#### 初始化：
```cpp
TTF_Init();
```
返回值，运行正确返回0
#### 打开一个ttf文件
```cpp
TTF_Font*       font         = nullptr;
```
```cpp
font TTF_OpenFont("文件路径",字体大小);
```
打开失败时返回nullptr
#### 样式（可选）
```cpp
TTF_SetFontStyle(TTF_Font*,参数);
```
参数：（可以使用“|”）
- TTF_STYLE_BOLD  加粗
- TTF_STYLE_ITALIC 倾斜
- TTF_STYLE_UNDERLINE 下划线
- TTF_STYLE_STRIKETHROUGH 删除线
#### 创建纹理（仅支持英文）
方法1  质量差但渲染速度快
```cpp
SDL_Surface TTF_RenderText_Solid(TTF_Font*,字符串,SDL_Color,背景色=透明);
```
方法2  和上面的相反
```cpp
SDL_Surface TTF_RenderText_Blended(TTF_Font*,字符串,SDL_Color);
```
支持换行
```cpp
SDL_Surface TTF_RenderText_Blended_Wrapped(TTF_Font*,字符串,SDL_Color,int限制宽度);
```
#### 创建纹理（支持中文）（把上面的text改成UTF8即可）
UTF16格式：
```cpp
SDL_Surface TTF_RenderUNICODE_Blended_Wrapped...    字符串改Uint16
```
UTF8格式：
```cpp
TTF_RenderUTF8_Blended_Wrapped(....);
```
#### 销毁
```cpp
TTF_CloseFont(TTF_Font*);
```


#### 退出
```cpp
TTF_Quit();
```




```cpp
#include "cpp/iffRAndCircle.cpp" // 矩形和圆的碰撞检测
#include "cpp/iffRectAndRect.cpp" // 矩形和矩形的碰撞检测
#include "cpp/TtoTandR.cpp"  // 
#include "cpp/rectandRect.cpp"  //
```

```cpp
char ch[40];
snprintf(ch, sizeof(ch), "%d",数字类型变量);
font = TTF_OpenFont("resources/...ttf文件名.ttf",60);
什么TT = SDL_CreateTextureFromSurface(render,TTF_RenderUTF8_Solid(font,ch,{255,255,255,255})); 
rectWHForTexture(&什么RP,什么TT);
```






