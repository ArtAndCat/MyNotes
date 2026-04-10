
 obsidian Shiki Highlighter 插件

笔记想法来自 【`SDL3` GPU 01：绘制彩色三角形】 https://www.bilibili.com/video/BV1ABAQeSEBJ


创建 `SHADER`（顶点着色器）编程语言：`glsl`  
（`.vert` ==顶点着色器==   `.frag` ==片段着色器== 产物是`.spv` ）

```glsl
#version 450  // 着色器版本号 因为不同版本号有不同的特性 这里表示4.50  建议顶点和片段使用相同的版本

layout(location = 0) out vec3 fragColor;  //用于将属性传递给其他着色器  定点-->片段  out 表示传出去

vec2 positions[3] = vec2[](  // 声明一个二维向量 的数组
vec2(0.0, -0.5),
vec2(0.5, 0.5),
vec2(-0.5, 0.5)
);

vec3 colors[3] = vec3[](
vec3(1.0, 0.0, 0.0),
vec3(0.0, 1.0, 0.0),
vec3(0.0, 0.0, 1.0)
);

void main() {
	// 使用 gl_VertexID 代替 gl_VertexIndex
	gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
	// gl_Position 内部变量 只读  用于存放最后的值
	fragColor = colors[gl_VertexIndex];
}

```

```glsl
#version 450

  

layout(location = 0) in vec3 fragColor; // 这里表示接收 

  

layout(location = 0) out vec4 outColor;

  

void main() {

outColor = vec4(fragColor, 1.0);

}
```



