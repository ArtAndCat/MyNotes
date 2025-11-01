依赖库什么的
```shell
pkg update && pkg upgrade -y
```
工具本体
```shell
pkg install ffmpeg -y
```
查看版本
```shell
ffmpeg -version
```




## 9月5  把多个.ts文件转换并且合并为MP4
创建一个列表
```shell
find . -name "*.ts" -exec echo "file '{}'" \; > filelist.txt
```
- \*.ts 是文件名
合并
```shell
ffmpeg -f concat -safe 0 -i filelist.txt -c copy output.mp4
```

