3
【`SDL3` GPU 01：绘制彩色三角形】 https://www.bilibili.com/video/BV1ABAQeSEBJ

`Gethub`链接 https://github.com/VisualGMQ/SDL3_gpu_example/blob/main/examples
# 1 绘制彩色三角

`openGL` 渲染管线  固定流程
现在 可编程渲染管线  自己编程流程
### 什么渲染管线 流程？
- 顶点输入
- -> 告诉GPU我要连线还是画实心三角...
- ->顶点着色器（可编程）负责修改顶点位置->细分着色器（`SDL`不支持）负责新增加/减少一个顶点（已经没什么用了）
- -> 告诉GPU这个新顶点构成什么样的图形（`SDL`不支持）
- -> 光栅化 映射到屏上的像素格中 确定这个像素的颜色 
- -> 片段着色器（可编程）（纹理贴图有关）
- -> 混合因为`rgba`中的a 
- -> 帧缓冲 

### 渲染流程/渲染通道
不同渲染管线有不同的功能  ~~有的耗时但效果好 有的速度快但效果差~~ 你可能需要走多个不同的渲染管线

### 补充：
不可编程的地方还是有参数需要设置的参数

创建 `SHADER`（顶点着色器）编程语言：`glsl`  （以`.vert`结尾 表示顶点着色器   `.frag` 表示片段着色器 产物是`.spv` ）

`OpenGL` 是 `glsl`文件
`glsl`文件 -> `glslc`编译器 -> `SPIR-V`(GPU可执行文件)
`Directx hlsl`
`hlsl`文件 -> xxx -> `SPIR-V`(GPU可执行文件)

```shell
glslc shader.vert -o vert.spv       
```

```shell
glslc shader.frag -o frag.spv
```