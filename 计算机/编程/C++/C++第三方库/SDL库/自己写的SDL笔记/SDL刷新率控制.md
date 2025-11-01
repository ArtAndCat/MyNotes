






等待指定毫秒数
```cpp
void SDL_Delay(Uint32 ms)  
```
返回sdl初始化后的当前毫秒数（溢出需要49天左右）
```cpp
Uint32 SDL_GetTicks(void)
```
建议使用这个，巧妙使用数学运算防止溢出
```cpp
Uint64 SDL_GetTicks64(void)  
```
60hz时 16毫秒

