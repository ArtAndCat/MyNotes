#C #第三方库 #图形 #C库 #视频笔记 #SDL #自制笔记 #事件 #手指


| 类型 | 标签 | 用处 |
|--|--|--|
| int32 | timestamp |  |
| SDL_TouchID | touchId | 设备ID |
| SDL_FingerID | fingerId | 手指ID |
| float | x | 按下的位置(0~1) |
| float | y | |
| float | dx | 偏移量(-1~1)|
| float | dy | |
| float | pressure | 按压力度(0~1) |
| int32 | windowID | 窗口id |


只通过finger事件的xy坐标不可以对应多个手指
但每次有手指动的时候都会记录，并且改变finger ID来表示是那个手指。


检测手指按下事件
```cpp
while (SDL_PollEvent(&事件)) { //如果有事件就循环
	if (事件.type == SDL_FINGERDOWN ){//如果是按下事件
		//根据手指id保存到
		
	}else if (事件.type == SDL_FINGERMOTION){//如果手指在移动
		//根据手指ID更改容器中对应的坐标
		
	}else if (事件.type == SDL_FINGERUP){//如果是抬起事件
		//删除容器中对应的手指数据
		
	}
}
```





https://wiki.libsdl.org/SDL2/SDL_EventType （sdl图形库，所有事件标签（手指按下/抬起/移动..）


