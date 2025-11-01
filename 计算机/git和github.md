
【git 详解，10分钟学会】 https://www.bilibili.com/video/BV1Gv421i7wW



#  1.Git介绍
是个版本控制系统    负责代码管理等
你可以理解是一个云服务器  可以 上传/同步 和 下载/备份
ps: SVN ? git 的作者就是因为SVN太难使了开发了git
# 2. Git工作原理

# 3. 安装方法  
这里为什么是空的？因为我linux有  （我都不知道我什么时候安装的）
### 3.1 服务端   4:18
### 3.2 客户端  4:47

# 补充内容： ssh配置
来自：【【大学生扫盲课】1 Git、GitHub 和 Gitee 完整讲解：从基础到进阶功能】 https://www.bilibili.com/video/BV1G8CFYvEjt

ssh？用来本地和远程仓库的安全通信 也省去每次推送和拉取时写密码的麻烦
### 1. 设置署名（每次提交都会标明是谁的捐献）
设置名称和邮箱（算是联系方式）：
  ```bash
  git config --global user.name "Your Name"
  ```
  
  ```bash
  git config --global user.email "your.email@example.com"
  ```
### 2. 生成密钥
设置ssh加密：
```shell
ssh-keygen -t rsa -C "your.email@example.com"
```
- `-t rsa`  ：使用 RSA 算法加密。
- `-c` ：添加备注，通常是你的邮箱地址。
然后会让你设置路径   回车默认即可
再然后会让你设置密码（可选  视频和我都没设置）
如果你没设置密码 需要再回车一次      如果你设置了密码 需要再写一次密码


详情输出：
```shell
➜  ~ ssh-keygen -t rsa -C "your.email@example.com"
Generating public/private rsa key pair.
Enter file in which to save the key (/home/用户名/.ssh/id_rsa): 
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/用户名/.ssh/id_rsa
Your public key has been saved in /home/用户名/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX your.email@example.com
The key's randomart image is:
+---[RSA 3072]----+
| XXXXXXXXXXXXX   |
| XXXXXXXXXXXXX   |
| XXXXXXXXXXXXX   |
| XXXXXXXXXXXXX   |
|  XXXXXXXXXXXXX  |
|       . = o     |
|    XXXXXXXXXXXXX|
|       o * +     |
|      .E+*+.     |
+----[SHA256]-----+
```

此时你就会发现你的用户里你多了个 .ssh 的隐藏文件夹  里面有 `id_rsa`   和 `id_rsa.pub` 两个文件
- **`id_rsa`** - 私钥文件（保存在你的电脑上     保密！不要分享）
- **`id_rsa.pub`** - 公钥文件（可以分享，用于添加到 GitHub）

### 3. 添加共钥到您的远程服务器
==复制== `id_rsa.pub` 文件中的内容
### Github
> 对了 记得先注册一个账户喵。

打开 [Github](https://github.com/) 登录/注册
设置setting  -> SSH and GPG keys
点 SSH keys 后面的 New SSH
写个Title
把刚刚复制内容粘贴到下面  
接着跟着操作

**测试：**
```shell
ssh -T git@github.com
```
如果提示
```
➜  MyNotes git:(main) ssh -T git@github.com [回车]
Hi [你的名字]! You've successfully authenticated, but GitHub does not provide shell access.
```
说明成功
### Gitee




# 5. 常用操作
 
[[Git]]           [[常用Git命令清单]]



使用 Git 与 GitHub 进行代码仓库的下载（克隆）和上传（推送）是软件开发中常见的操作。下面是一些基本步骤来帮助你完成这些任务。



6. **执行克隆命令**：使用 `git clone` 命令加上刚才复制的链接来克隆仓库。
   ```bash
   git clone https://github.com/用户名/仓库.git
   ```
   这里的 `https://github.com/用户名/仓库.git` 是你需要替换为你实际想要克隆的仓库链接。

7. **进入克隆下来的项目文件夹**：
   ```bash
   cd 仓库
   ```

### 4.2 上传（推送）更改到 GitHub 仓库

1. **确保你在正确的分支**：通常默认为 `main` 或 `master` 分支。可以使用以下命令查看当前所在分支：
   ```bash
   git branch
   ```
   
2. **添加文件到暂存区**：当你对项目进行了修改后，你需要先将这些更改添加到 Git 的暂存区。
   ```bash
   git add .
   ```
   如果只添加特定文件，则指定文件名而不是点号。

3. **提交更改**：把暂存区的内容提交到本地仓库。
   ```bash
   git commit -m "Your commit message"
   ```
   提供有意义的提交信息是很重要的。

4. **推送到远程仓库**：最后一步是将本地的提交推送到 GitHub 上的远程仓库。
   ```bash
   git push origin main  # 或者可能是 master，取决于你的默认分支名称
   ```

以上就是从 GitHub 克隆仓库以及向 GitHub 推送更新的基本流程。请记得，在推送之前确保你拥有足够的权限来写入目标仓库。如果你遇到任何权限问题，可能需要联系仓库所有者以获取相应的访问权。

当然，这里有一些 Git 的常用指令，它们对于日常的版本控制工作非常有帮助。这些命令可以帮助你管理代码仓库、追踪更改、合并分支等。

### 基本设置
- 设置用户名：
  ```bash
  git config --global user.name "Your Name"
  ```
- 设置邮箱地址：
  ```bash
  git config --global user.email "your.email@example.com"
  ```

### 初始化和克隆仓库
- 在现有目录初始化一个新的 Git 仓库：
  ```bash
  git init
  ```
- 克隆一个远程仓库到本地：
  ```bash
  git clone <repository-url>
  ```

### 检查状态与信息
- 查看当前工作区的状态：
  ```bash
  git status
  ```
- 显示当前分支以及跟踪的远程分支信息：
  ```bash
  git branch -vv
  ```

### 添加文件至暂存区
- 添加所有更改过的文件到暂存区：
  ```bash
  git add .
  ```
- 添加特定文件到暂存区：
  ```bash
  git add <file>
  ```

### 提交更改
- 提交暂存区的更改，并添加提交信息：
  ```bash
  git commit -m "Commit message"
  ```
- 将未跟踪的文件也包含进此次提交（不推荐频繁使用）：
  ```bash
  git commit -a -m "Commit message"
  ```

### 查看历史记录
- 查看提交历史：
  ```bash
  git log
  ```
- 查看简略的历史记录：
  ```bash
  git log --oneline
  ```

### 分支操作
- 列出所有的分支：
  ```bash
  git branch
  ```
- 创建新的分支并切换到该分支：
  ```bash
  git checkout -b <new-branch-name>
  ```
- 切换分支：
  ```bash
  git checkout <branch-name>
  ```
- 删除本地分支：
  ```bash
  git branch -d <branch-name>
  ```

### 远程仓库操作
- 查看当前配置的远程仓库：
  ```bash
  git remote -v
  ```
- 添加新的远程仓库：
  ```bash
  git remote add <remote-name> <remote-url>
  ```
- 推送本地分支到远程仓库：
  ```bash
  git push <remote-name> <branch-name>
  ```
- 拉取远程仓库的更新到本地：
  ```bash
  git pull <remote-name> <branch-name>
  ```
- 获取远程仓库的信息但不自动合并：
  ```bash
  git fetch <remote-name>
  ```

### 合并与解决冲突
- 合并指定分支到当前分支：
  ```bash
  git merge <branch-name>
  ```
- 使用 `git mergetool` 来解决合并时发生的冲突。
  ```bash
  git mergetool
  ```

这些都是 Git 中一些非常基础且常用的命令。掌握这些命令后，你可以更有效地进行版本控制和协作开发。如果你遇到具体的问题或者需要更详细的解释，请随时提问！