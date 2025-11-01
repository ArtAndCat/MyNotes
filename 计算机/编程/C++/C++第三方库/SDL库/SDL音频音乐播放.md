#SDL #编程 #音频 #C 


### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">头文件</font></div>
```cpp
#include <SDL/SDL_mixer.h>
```
### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">初始化</font></div>
```cpp
Mix_Init(参数);
```
可选参数（提示：可以使用|）
- MIX_INIT_FLAC
- MIX_INIT_MOD
- MIX_INIT_MP3
- MIX_INIT_OGG
- MIX_INIT_MID
- MIX_INIT_OPUS
- MIX_INIT_WAVPACK

### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">准备一个音频播放装置 准备播放音频 </font></div>
#### 打开默认音频设备进行播放：
```cpp
int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);
```
参数列表：
- frequency  频率（赫兹48000）
- format   音频格式（上面有）
- channels  通道数量  1单声道  2立体声
- chunksize  大小（字节 建议2048=2kb）
#### 对应的销毁（不用参数）
```cpp
Mix_CloseDevice();
```

### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">加载一个音乐</font></div>
时间较长：
```cpp
Mix_Music *_ = Mix_LoadMUS("路径");
```
时间较短：
```cpp
Mix_Chunk *_ = Mix_LoadWAV("路径");
```
对应的释放函数：
```cpp
Mix_FreeChunk(名字);
```
对应的释放函数：
```cpp
Mix_FreeMusic(名字);
```
### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">开始播放！！（激动）</font></div>

播放音乐
```cpp
Mix_PlayMusic(名字,次数);  //播放音乐！！负1代表65535左右次
```
缓入音乐
```cpp
Mix_FadeInMusic(名字,次数,和缓入有关2000);
```
缓出(单位：毫秒)
```cpp
Mix_FadeOutMusic(500);
```

播放音效
```cpp
Mix_PlayChannel(-1,名字,次数);  //负1代表65535左右次  返回int类型  是用来存储音效通道的
```
-1指播放位置，填-1就对了

#### 一些有用的判断和控制函数
判断是否播放
```cpp
Mix_PlayingMusic()  //判断是否播放 是1  否0
```
判断是否暂停
```cpp
Mix_PausedMusic()  //判断是否暂停 是1  否0
```

继续播放
```cpp
Mix_ResumeMusic();
```
暂停播放（和判断是否暂停一样）
```cpp
Mix_PauseMusic();
```
停止播放
```cpp
Mix_HaltMusic();
```

更改音量
```cpp
Mix_VolumeMusic(数);  //up这里用的最大128
```

这里的是和音效相关的
暂停该通道
```cpp
Mix_Pause(int channel);// -1表示全部
```
恢复
```cpp
Mix_Resume(int channel); // 恢复特定通道
```
停止指定通道的音效
```cpp
Mix_HaltChannel(int channel);// -1表示全部
```

### \_\_\_\_<div style="width:100%;height:30px;background-color:rgb(40,40,70);text-align:center;"><font style="font-size:20px">退出</font></div>
```
Mix_Quit();
```


