#C #第三方库 #图形 #C库 #视频笔记 #SDL #编程

```cpp
SDL_SetRenderDrawBlendMode(渲染器指针,混合模式);
```

混合模式：
- SDL_BLENDMODE_NONE  无
- SDL_BLENDMODE_BLEND  透明效果
- SDL_BLENDMODE_ADD  添加剂混合
- SDL_BLENDMODE_MOD  
- SDL_BLENDMODE_MUL
- SDL_BLENDMODE_INVALID
```c
typedef enum SDL_BlendMode
{
    SDL_BLENDMODE_NONE = 0x00000000, 
    /**< no blending 
     dstRGBA = srcRGBA 
     */
    SDL_BLENDMODE_BLEND = 0x00000001,    
    /**< alpha blending
     dstRGB = (srcRGB * srcA) + (dstRGB * (1-srcA))
    dstA = srcA + (dstA * (1-srcA)) 
    */
    SDL_BLENDMODE_ADD = 0x00000002,      
    /**< additive blending
     dstRGB = (srcRGB * srcA) + dstRGB
     dstA = dstA */
    SDL_BLENDMODE_MOD = 0x00000004,      
    /**< color modulate
     dstRGB = srcRGB * dstRGB
     dstA = dstA */
    SDL_BLENDMODE_MUL = 0x00000008,      
    /**< color multiply
     dstRGB = (srcRGB * dstRGB) + (dstRGB * (1-srcA))
     dstA = dstA */
    SDL_BLENDMODE_INVALID = 0x7FFFFFFF
    
    /* Additional custom blend modes can be returned by SDL_ComposeCustomBlendMode() */

} SDL_BlendMode;
```

```cpp
SDL_SetTextureAlphaMod(texture, 128);//0~255
```



在SDL2中，要让一个图片（Texture）以半透明的方式显示，关键在于设置纹理的混合模式（blend mode）。以下是实现图片半透明显示的关键代码段：

```cpp
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // 初始化SDL
    SDL_Init(SDL_INIT_VIDEO);

    // 创建窗口
    SDL_Window* window = SDL_CreateWindow(
        "调节texture透明度",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, // 设置窗口宽度和高度
        SDL_WINDOW_SHOWN
    );

    // 创建渲染上下文
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // 加载图片为纹理
    SDL_Texture* texture = IMG_LoadTexture(renderer, "path_to_your_image.png"); // 替换为你的图片路径

    // 设置渲染器的绘制混合模式以允许半透明
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // 渲染循环
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // 清除渲染器
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 设置纹理的alpha值（这里以50%透明度为例）
        SDL_SetTextureAlphaMod(texture, 128); // 参数范围0（完全透明）到255（完全不透明）

        // 将纹理渲染到屏幕上
        SDL_Rect dstRect = { x, y, width, height }; // 设置纹理的显示位置和大小
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);

        // 更新屏幕
        SDL_RenderPresent(renderer);
    }

    // 清理资源
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
```

这段代码首先初始化SDL并创建一个窗口和渲染器，然后加载一个图片文件为`SDL_Texture`对象。通过调用`SDL_SetTextureAlphaMod()`函数设置纹理的alpha值来控制其透明度，参数是一个0到255之间的整数，其中0表示完全透明，255表示完全不透明。在渲染循环中，使用`SDL_RenderCopy()`函数将设置了透明度的纹理绘制到屏幕上，从而实现了图片的半透明显示。