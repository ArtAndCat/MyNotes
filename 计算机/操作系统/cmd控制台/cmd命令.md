

网络修改
ping   多个可选项   要ping的远程计算机
可选项：
- -t    一直发（直到用户按下Ctrl+C）
- -a    解析计算机NetBIOS名
- -n num    发送“num”个数据包
- -l size     发送size大小的数据包（0~65500）
- -f      再次不要分发
- -i  TTL      指定生存时间
- -r  count    记录路由器通常限制在9个以内  更多可以使用tracert
- -s  count    指定count跃点数的时间戳
- -w  时间     超出多久后关闭（单位毫秒）

ipconfig___    命令查看网络配置
- /all  显示本机TCPIIP配置的详细信息。
- /renew  DHCP客户端手工向服务器刷新请求。
- /release  DHCP客户端手工释放I地址。
- /flushdns  清除本地DNS缓存内容。
- /displaydns  显示本地DNS内容。
- /registerdns  DNS客户端手工向服务器进行注册。
- /showclassid  显示网络适配器的DHCP类别信息。
- /setclassid设  置网络适配器的DHCP类别。

nbtstat   __
- -n    查看本机NetBIOS名称表信息
- -a peng  查看远程计算机的名称表
- -RR     通过WINS（Windows Internet Naming Server，Window Internet 名称服务）服务器注册的NetBIOS 名称进行重新注册
- -R       名称缓存信息......
- -s     显示并将目标IP地址转换为名称。
- -S     显示IP地址
- 数字          每“数字”秒刷新一次（单位：秒）
