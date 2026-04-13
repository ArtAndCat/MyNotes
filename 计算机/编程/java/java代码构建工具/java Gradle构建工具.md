



























### Gradle 项目结构

部分企业（尤其是 Android 或 Kotlin 项目）会用 **Gradle** 代替 Maven。

| Maven | Gradle          |                                                     |
| ----- | --------------- | --------------------------------------------------- |
| 配置文件  | `pom.xml` (XML) | `build.gradle` / `build.gradle.kts` (Groovy/Kotlin) |
| 目录结构  | **完全相同的标准布局**   | **完全相同的标准布局**                                       |
| 构建速度  | 较慢（线性执行）        | 更快（增量构建 + 缓存）                                       |

同一个项目的源码目录（`src/main/java`、`src/main/resources` 等）**完全不需改动**，换的只是构建配置文件。所以学透 Maven 的标准布局，两种工具都能无缝切换。

---
