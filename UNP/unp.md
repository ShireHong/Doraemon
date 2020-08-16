### TCP和UDP

常见应用程序对协议的使用表：

|应用程序|IP|ICMP|UDP|TCP|
|-|-|-|-|-|
|ping||●|||
|traceroute||●|●||
|OSPF(路由协议)|●||||
|RIP(路由协议)|||●||
|BGP(路由协议)||||●|
|BOOTP(引导协议)|||●||
|DHCP(引导协议)|||●||
|NTP(时间协议)|||●||
|TTP(低级FTP)|||●||
|SNMP(网络管理)|||●||
|SMTP(电子邮件)||||●|
|Telnet(远程登陆)||||●|
|FTP(文件传输)||||●|
|HTTP(web)||||●|
|NNTP(网络新闻)||||●|
|DNS(域名系统)|||●|●|
|NFS(网络文件系统)|||●|●|


### sockaddr 和 sockaddr_in
socket编程中在定义一个服务器或者客户端的地址，端口和协议信息的时候，使用的是**sockaddr_in**，在使用bind，accept和connect函数时，就需要强转为**sockaddr**，这里需要去了解这两个的区别和为什么要这么做？

- [ ] sockaddr_in 结构
```
struct sockaddr_in
{
  uint8_t         sin_len;
  sa_family_t     sin_family;
  in_port_t       sin_port;
  struct in_addr  sin_addr;
  char            sin_zero[8];
}
struct in_addr{
  in_addr_t   s_addr;  //32位ipv4地址
}
```
- [ ] sockaddr 结构
```
struct sockaddr{
  uint8_t     sa_len;
  sa_family_t sa_family;
  char        sa_data[14];
}
```
作为参数传递給任一个套接口函数时，套接口的地址结构总是通过指针来传递，但通过指针来取得此参数的套接口函数必须处理来自所支持的任何协议簇的套接口地址结构。

这要求对bind，accept和connect函数的任何调用都必须将指向特定于协议的套接口地址结构的指针类型转换成指向通用套接口地址结构的指针。

从应用程序开发人员的观点看，这些通用的套接口地址结构的唯一用途是给指向特定于协议的地址结构的指针转类型

<img src="https://github.com/ShireHong/Doraemon/blob/master/UNP/source/%E5%9C%B0%E5%9D%80%E7%BB%93%E6%9E%84.png"  
    alt="图片加载失败时，显示这段字"/>



