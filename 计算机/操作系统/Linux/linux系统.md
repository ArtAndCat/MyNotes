#编程 #操作系统 #Linux #大 


修理
```shell
chkdsk E: /f /r /x
```
[[计算机/编程/shell/shell|shell]]

[[termux 和 ffmpeg]]
# 安装
https://www.runoob.com/linux/linux-install.html
# 启动过程
1. 内核的引导。
2. 运行 init。
3. 系统初始化。
4. 建立终端 。
5. 用户登录系统。
init程序的类型：
- **SysV**: init, CentOS 5之前, 配置文件： /etc/inittab。
- **Upstart**: init,CentOS 6, 配置文件： /etc/inittab, /etc/init/*.conf。
- **Systemd**： systemd, CentOS 7,配置文件： /usr/lib/systemd/system、 /etc/systemd/system。

# 修改源

```shell
sudo vim /etc/pacman.d/mirrorlist
```
然后自己找吧


# 特殊命令



# 一些命令
### 工具
### 娱乐(需要下载)

```shell
cmatrix   
```

```shell
cbonsai -l -i -t 0.5 -L 32 -k 213,94,218,94 -w 10
```
# 基础命令

命令手册页 (`man command`) 在线文档来了解更多关于特定命令的信息。
### 1. 安装和登录命令
- `login`: 用户登录系统。
- `logout` 或 `exit`: 用户从系统注销。
- `shutdown`: 关闭系统。
- `halt`: 停止系统。
- `reboot`: 重启系统。
- `mount`: 将文件系统挂载到目录。
- `umount`: 卸载已挂载的文件系统。

### 2. 文件处理命令
- `file`: 显示文件类型。
- `mkdir`: 创建目录。
- `grep`: 在文件中搜索字符串。
- `dd`: 复制或转换文件。
- `find`: 查找文件。
- `mv`: 移动或重命名文件。
- `ls`: 列出目录内容。
- `diff`: 显示两个文件之间的差异。
- `cat`: 显示文件内容。
- `ln`: 创建硬链接或符号链接。

### 3. 系统管理相关命令
- `df`: 显示文件系统磁盘空间使用情况。
- `top`: 显示系统资源使用情况。
- `free`: 显示系统内存使用情况。
- `quota`: 显示磁盘配额。
- `at`: 定时执行任务。
- `lp`: 打印文件。
- `adduser`: 添加新用户。
- `groupadd`: 添加新用户组。
- `kill`: 发送信号给进程。
- `crontab`: 编辑定时任务表。

### 4. 网络操作命令
- `ifconfig`: 配置网络接口。
- `ip`: 显示和操纵路由、网络设备、接口统计等。
- `ping`: 测试网络连接。
- `netstat`: 显示网络连接、路由表、接口统计等。
- `telnet`: 远程登录服务。
- `ftp`: 文件传输协议。
- `route`: 显示和操纵路由表。
- `rlogin`: 远程登录服务（较少使用）。
- `rcp`: 远程文件复制（较少使用）。
- `finger`: 查询用户信息。
- `mail`: 发送电子邮件。
- `nslookup`: 查询DNS信息。

### 5. 系统安全相关命令
- `passwd`: 更改用户密码。
- `su`: 切换用户。
- `umask`: 设置文件权限掩码。
- `chgrp`: 改变文件或目录的组所有权。
- `chmod`: 改变文件或目录的权限。
- `chown`: 改变文件或目录的所有权。
- `chattr`: 改变文件的扩展属性。
- `sudo`: 以其他用户身份执行命令。
- `ps`: 显示进程状态。
- `who`: 显示当前登录用户。

### 6. 其他命令
- `tar`: 归档文件。
- `unzip`: 解压ZIP文件。
- `gunzip`: 解压GZIP压缩文件。
- `unarj`: 解压ARJ文件。
- `mtools`: 操作MS-DOS文件系统。
- `man`: 显示命令的手册页。
- `unendcode`: 解码UUEncode编码文件。
- `uudecode`: 解码UUEncode编码文件。

补充：
rm 删除  -f 强制   -r 批量 -rf    

### 磁盘操作

```shell
fdisk -l 
```

```shell
cfdisk /dev/sda
```






### 列出已安装的软件包

最核心的命令是 `pacman`（Arch Linux 的包管理器）和 `expac`（一个专门为 pacman 设计的查询工具）。

##### 方法一：使用 `pacman` 命令（最常用）

`pacman` 是 Arch Linux 自带的包管理器，以下命令都可以直接使用。

###### 1. 列出**明确**由你安装的软件（不包括依赖）
这个命令列出所有你手动安装的、而非作为依赖被安装的软件包。这是最常用来看“我到底装了些什么”的命令。
```bash
pacman -Qe
```
- `-Q`：查询（Query）本地软件包数据库。
- `-e`：列出明确安装的（explicitly installed）软件包。

**类似命令：**
- `pacman -Qne`：列出从官方仓库明确安装的软件包（排除 AUR 包）。
- `pacman -Qme`：列出从 AUR 等非官方仓库明确安装的软件包。

###### 2. 列出**所有**已安装的软件包（包括依赖）
这个命令会列出系统上安装的每一个软件包，数量会非常多。
```bash
pacman -Q
```
或者使用更详细的格式：
```bash
pacman -Q | less
```

###### 3. 按条件搜索已安装的包
如果你记得包名的一部分，可以用 `grep` 进行过滤。
```bash
pacman -Q | grep 关键字
```
例如，查找所有包含 `python` 的已安装包：
```bash
pacman -Q | grep python
```

###### 4. 显示一个已安装包的详细信息
```bash
pacman -Qi 包名
```
- `-i`：显示信息（info）。
例如：
```bash
pacman -Qi firefox
```

###### 5. 列出某个包安装的文件
```bash
pacman -Ql 包名
```
- `-l`：列出文件列表（list）。
例如：
```bash
pacman -Ql firefox
```

##### 方法二：使用 `expac` 工具（输出格式更强大）

`expac` 是一个专门为 pacman 设计的强大查询工具，可以高度自定义输出格式，但它需要额外安装。

###### 1. 安装 `expac`
```bash
sudo pacman -S expac
```

###### 2. 使用 `expac` 列出包
基本用法类似于 `pacman -Q`，但格式更整洁：
```bash
expac "%n" -Q
```

**强大的自定义输出示例：**

- **列出包名、版本和简介：**（这是最实用的格式之一）
  ```bash
  expac "%-20n %v %d" -l '\n' -Q
  ```

- **按安装时间排序，列出最新的 10 个包：**
  ```bash
  expac --timefmt='%Y-%m-%d %T' '%l\t%n' -Q | sort | tail -n 10
  ```

- **显示每个包占用的磁盘空间（从大到小排序）：**
  ```bash
  expac -H M "%011m\t%-20n\t%10d" | sort -n
  ```

### 方法三：浏览包数据库文件

pacman 的本地数据库是一个纯文本文件，你也可以直接查看它。
```bash
less /var/lib/pacman/local/
```
这个目录下每个子目录都是一个已安装的软件包。但通常不推荐用这种方法来查询，除非你想了解底层机制。

---

### 总结与推荐

| 你的需求 | 推荐命令 |
| :--- | :--- |
| **“我都手动安装了哪些软件？”** | `pacman -Qe` |
| **“系统里总共装了多少东西？（包括依赖）”** | `pacman -Q \| wc -l` |
| **“我是不是装了某个包？”** | `pacman -Q \| grep 关键字` 或 `pacman -Q 包名` |
| **“这个包是干嘛的？占多大空间？”** | `pacman -Qi 包名` |
| **“这个包都包含了哪些文件？”** | `pacman -Ql 包名` |
| **“生成一个带版本和描述的漂亮列表”** | `expac "%-20n %v %d" -l '\n' -Q` |
| **“哪个包最占地方？”** | `expac -H M "%011m\t%-20n\t%10d" \| sort -n` |

对于绝大多数日常使用场景，**`pacman -Qe`** 和 **`pacman -Qi`** 是最常用和最有用的命令。如果你需要更复杂的查询和格式化，那么安装并使用 `expac` 是绝佳的选择。








根据你的设备配置（i7-6500U 处理器和 AMD Radeon R5 M330 显卡），**是可以安装和使用 Vulkan 的**。这主要得益于你的AMD显卡和开源驱动支持。

下面是一个表格，帮你快速了解关键信息：

| 事项         | 支持情况                                                                                              | 备注                                           |
| :----------- | :---------------------------------------------------------------------------------------------------- | :--------------------------------------------- |
| **显卡硬件**   | ✅ 支持                                                                         | AMD Radeon R5 M330 基于 GCN 架构                 |
| **开源驱动**   | ✅ **RADV (Mesa)**                                                                            | 推荐使用，已通过 Vulkan 1.3 认证                 |
| **开源驱动**   | ✅ **AMDVLK**                                                                                 | AMD 官方开源驱动，可选                           |
| **闭源驱动**   | ⚠️ 可能支持（需验证）                                                                                      | 在Linux上通常不推荐，开源驱动往往更好                |
| **CPU核显**   | ⚠️ **i7-6500U 的 HD Graphics 520** (需单独确认和配置)                                                      | 需安装 Intel Vulkan 驱动                       |

🧐 **驱动选择建议**
对于你的 Arch Linux，建议优先选择 **RADV (Mesa)** 驱动。它通常能提供更好的兼容性和性能 。

🔧 **在 Arch Linux 上安装 Vulkan**

1.  **确保系统更新**：
    首先更新系统，确保所有软件包最新。
    ```bash
    sudo pacman -Syu
    ```

2.  **安装必要的驱动和 Vulkan 组件**：
    根据你的显卡架构（GCN）和推荐，需要安装 `vulkan-radeon`（即 RADV 驱动）以及 Vulkan 加载器和工具。
    ```bash
    sudo pacman -S vulkan-radeon vulkan-icd-loader lib32-vulkan-icd-loader vulkan-tools
    ```
    *   `vulkan-radeon`: 提供 RADV 驱动 。
    *   `vulkan-icd-loader` 和 `lib32-vulkan-icd-loader`: Vulkan 安装运行时和32位库（运行32位应用或游戏需要）。
    *   `vulkan-tools`: 包含 `vulkaninfo` 等验证工具 。

3.  **验证安装**：
    安装后，重启或在终端输入：
    ```bash
    vulkaninfo
    ```
    如果输出大量 Vulkan 相关信息，且没有报错，则说明 Vulkan 驱动安装成功。

🤝 **双显卡注意**
你的笔记本是**双显卡**（Intel HD Graphics 520 和 AMD Radeon R5 M330）。在Linux中，**图形应用默认可能运行在集显上**。

要让应用使用独显运行，可：
*   使用 `DRI_PRIME=1` 前缀。例如：
    ```bash
    DRI_PRIME=1 vulkaninfo
    ```
    ```bash
    DRI_PRIME=1 ./你的游戏
    ```
*   更复杂的管理可借助 **optimus-manager** 等工具。

⚡ **性能提示**
AMD Radeon R5 M330 是款入门级独显，**不要指望它能流畅运行大型3A游戏或进行高负荷渲染**。它更适合日常办公、高清视频、轻量级游戏及老游戏。

💎 **总结**
你的设备支持 Vulkan。在Arch Linux上，安装 `vulkan-radeon` 等包即可。记得用 `DRI_PRIME=1` 让应用调用独显。

希望这些信息能帮到你！


