

目前不确定通用型如何 建议先问一下deepseek是否适合当前项目 
```gitignore
# ==============================================
# Maven 构建产物和临时文件
# ==============================================
/target/
# Maven 默认输出目录，包含编译后的 .class 文件和最终 .jar 包
pom.xml.tag
# Maven release 插件生成的临时标记文件
pom.xml.releaseBackup
# release 插件备份的原 pom.xml
pom.xml.versionsBackup
# versions-maven-plugin 修改版本号前的备份
pom.xml.next
# release 插件使用的下一个开发版本临时文件
release.properties
# release 插件生成的发布配置
dependency-reduced-pom.xml
# maven-shade-plugin 生成精简依赖后的 pom
buildNumber.properties
# buildnumber-maven-plugin 生成的时间戳/构建号
.mvn/timing.properties
# Maven 构建耗时统计文件
.mvn/wrapper/maven-wrapper.jar
# Maven Wrapper 的 jar 包（如果团队不用 wrapper 就忽略）

# ==============================================
# IntelliJ IDEA 配置文件（如果不用 IDEA 可删除此块）
# ==============================================
.idea/
# IDEA 项目配置目录（包含运行配置、代码风格等）
*.iml
# IDEA 模块文件（记录模块依赖和编译路径）
*.iws
# IDEA 工作区文件（个人窗口布局等）
*.ipr
# IDEA 旧版项目文件
out/
# IDEA 默认编译输出目录（和 Maven 的 target 功能重叠）

# ==============================================
# VSCode / Eclipse 配置文件（根据你实际使用的 IDE 保留）
# ==============================================
.vscode/
# VSCode 工作区配置（launch.json, settings.json 等）
.classpath
# Eclipse 类路径文件
.project
# Eclipse 项目描述文件
.settings/
# Eclipse 项目设置目录
bin/
# Eclipse 默认编译输出目录

# ==============================================
# 日志文件
# ==============================================
*.log
# 任何 .log 后缀的日志文件，防止测试时生成的日志被提交

# ==============================================
# 操作系统生成的杂项文件
# ==============================================
.DS_Store
# macOS 访达生成的文件夹元数据
.DS_Store?
# macOS 某些变体
._*
# macOS 资源分叉文件
.Spotlight-V100
# macOS Spotlight 索引数据
.Trashes
# macOS 废纸篓信息
ehthumbs.db
# Windows 缩略图缓存
Thumbs.db
# Windows 图片文件夹缩略图缓存
```