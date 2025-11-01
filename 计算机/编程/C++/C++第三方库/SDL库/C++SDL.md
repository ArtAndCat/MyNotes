#C #第三方库 #图形 #C库 #视频笔记 #SDL 
所需要的头文件。
```cpp
#include <SDL2/SDL.h>
```




[[SDL Wiki]]
演示代码仓库地址：https://github.com/jinfeihan57/learn_SDL2 SDL2 API手册：https://wiki.libsdl.org/SDL2/CategoryAPI SDL_Mixer API手册:https://wiki.libsdl.org/SDL2_mixer/
## 例子：
```cpp
#include <SDL2/SDL.h>

int main(int argc, char** argv){
	SDL_Window* window = nullptr;
	SDL_Renderer* render = nullptr;
	SDL_Event e;
	
	SDL_Init(SDL_INIT_EVERYTHING);//这里应该加个成功与失败的检测
	
	// 当SDL初始化完成后创建一个标题为"SDL Window"的窗口，因为在android上运行大小和位置不能指定所以给0即可
	//窗口标题  x y w h 显示方式
	window = SDL_CreateWindow("SDL Window", 0,0,0,0, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, 0);
	
	SDL_SetRenderDrawColor(render, 0, 255, 255, 255);
	SDL_RenderClear(render);
	SDL_RenderPresent(render);
	
	// 检测输入事件
	bool quit = false;
	while (!quit){
		
		while ( SDL_PollEvent(&e)){
			// 检测到用户需要退出
			if (e.type == SDL_QUIT){
				quit = true;
			}		
		}
	}
	//对称编程 这里应该加上销毁窗口
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

```

[[SDL_Init]]
[[SDL_CreateWindow创建窗口]]
[[SDL_Surface]]
[[SDL_Texture纹理操作]]
## 自己整的笔记：
[[SDL图片显示]]
[[SDL用颜色填充矩形]]
[[SDL手指事件]]
[[SDL-ttf文字]]
[[SDLrender混合模式]]
[[SDL音频音乐播放]]

[[SDL刷新率控制]]





在 SDL2 中，如果你想要获取一个纹理（texture）的尺寸，你可以使用 SDL_QueryTexture
```
int SDL_QueryTexture(SDL_Texture * texture,
                     Uint32 * format, int *access,
                     int *w, int *h);
```

| 类型        | 备注         |
| --------- | ---------- |
| texture * | 纹理         |
| Uint32 *  | 返回[[纹理格式]] |
| int *     | 返回[[访问权限]] |
| int *     | 宽          |
| int *     | 高          |
- 如果不需要可以填写 NULL








SDL3 作为 SDL 库的最新主要版本（首个稳定版为 3.2.0），在架构、功能和 API 设计上相比 SDL2 有显著革新。以下从核心功能增强、API 变更与迁移挑战、迁移策略三方面综合分析：

---

### 🚀 **一、SDL3 核心功能增强**
1. **图形渲染系统重构**  
   - **显式渲染驱动选择**：SDL3 允许创建渲染器时直接指定图形后端（如 `direct3d11`、`vulkan`、`opengl`），SDL2 仅支持“硬件加速”或“软件渲染”的模糊选项。  
   - **GPU API 强化**：新增底层 GPU 抽象层，支持现代渲染技术（如计算着色器），并优化 Vulkan/Metal 集成，为 HDR 和广色域铺路。  
   - **性能优化**：测试显示 D3D11 后端在简单渲染任务中帧率显著高于 OpenGL/Vulkan（例如 3.3万帧 vs 1.5千帧），但复杂场景差距缩小。

2. **多窗口与高分辨率支持**  
   - **多显示器管理**：新增 `SDL_DISPLAYEVENT_MOVED` 事件，动态处理显示器布局变化。  
   - **HiDPI 原生支持**：自动适配高分辨率屏幕，消除 SDL2 中常见的模糊问题。

3. **输入与设备扩展**  
   - **数字笔支持**：兼容 Apple Pencil、Wacom 等压感设备。  
   - **虚拟键盘定制**：在 Android/iOS 上可调整屏幕键盘布局和行为。

4. **音频系统升级**  
   - **逻辑音频设备**：将音频流分区分配给应用不同模块（如游戏音效与语音聊天独立处理）。  
   - **音频流 API**：简化重采样、音高调整和混音流程，支持硬件断开自动恢复。

5. **平台现代化**  
   - **Linux 优先 PipeWire**：默认用 PipeWire 替代 PulseAudio，优化 Wayland 兼容性。  
   - **旧平台移除**：停止支持 OpenGL ES 1.0、DirectFB、OS/2、WinRT 等过时技术。

---

### ⚠️ **二、API 变更与迁移挑战**  
1. **关键 API 重命名/替换**  
   | **SDL2 函数**         | **SDL3 替代方案**               | **用途**                     |  
   |------------------------|----------------------------------|------------------------------|  
   | `SDL_SetVideoMode()`   | `SDL_CreateWindow()`            | 创建窗口（支持多窗口） |  
   | `SDL_Surface` 渲染     | `SDL_Texture` + 渲染器 API      | 优先 GPU 加速而非 CPU 软渲染 |  
   | `SDL_BlitScaled()`     | `SDL_RenderTexture()`           | 纹理缩放渲染                 |  
   | `SDL_Main()` 强制入口  | 可选 `SDL_AppInit` 回调模型     | 更灵活的主循环设计 |  

2. **事件系统调整**  
   - 统一事件类型命名（如触摸/手势事件整合），需重写事件处理逻辑。  
   - 新增 `SDL_EVENT_DISPLAY_MOVED` 等多显示器事件。

3. **扩展库变更**  
   - SDL2 的 `SDL2_image`/`SDL2_ttf` 对应 SDL3 的 `sdl3_image-git`/`sdl3_ttf-git`（AUR 包），接口可能微调。

---

### 🛠️ **三、迁移策略与工具**  
1. **渐进迁移路径**  
   - **兼容层利用**：通过 **sdl2-compat-git** 库，在 SDL3 上直接运行未修改的 SDL2 二进制文件。  
   - **混合编译**：逐步替换模块，优先处理渲染/窗口创建等核心模块。

2. **必须更新的代码区域**  
   - **窗口创建**：替换 `SDL_SetVideoMode` 为 `SDL_CreateWindow`，并管理窗口对象生命周期。  
   - **渲染流程**：重写基于 `SDL_Surface` 的 Blit 操作，改用 `SDL_Renderer` + `SDL_Texture`。  
   - **音频初始化**：适配逻辑设备分配机制，检查流式 API 调用。

3. **工具与调试**  
   - **文档参考**：SDL3 Wiki 提供完整示例和浏览器即时运行代码。  
   - **CMake 配置**：安装时需包含 `share` 文件夹，否则构建系统无法定位依赖。

> **迁移步骤概览**  
> ```mermaid
> graph TD
>   A[评估项目依赖] --> B[集成 sdl2-compat 兼容层]
>   B --> C[逐步替换窗口/渲染模块]
>   C --> D[更新事件处理逻辑]
>   D --> E[测试音频与输入设备]
>   E --> F[移除兼容层， 原生 SDL3 编译]
> ```

---

### 💎 总结  
SDL3 通过**模块化 API 设计**（如分离渲染器与窗口）、**现代硬件支持**（Vulkan/PipeWire）和**开发体验优化**（交互式文档）显著提升了跨平台开发效率。迁移时需优先处理渲染管线与事件系统，利用 `sdl2-compat` 降低风险，并参考官方示例逐步重构。对于新项目，建议直接基于 SDL3 开发以充分利用其性能与扩展性。