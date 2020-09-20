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

### inet_pton 和 inet_ntop

p:presentation 地址表达式 ACSII 串
n:numeric 二进制值

```
int inet_pton(int family, const char* strptr, void* addrptr);
1:成功
0：无效输入表达式
-1：出错

const char* inet_ntop(int family, const void*addrptr, char* strptr, size_t len);
指向结果指针：成功
NULL：出错
```
### execve
**execve**才是内核中的的系统调用，其他五个函数都是调用execve的库函数

<img src="https://github.com/ShireHong/Doraemon/blob/master/UNP/source/execve.png"  
    alt="图片加载失败时，显示这段字"/>
### 处理被中断的系统调用
处理被中断的accept
慢系统调用
```
for(;;)
{
   clilen = sizeof(cliaddr);
   if((connfd = accept(listenfd,(SA *)&cliaddr,&clilen))<0)
   {
     if(errno == EINTR)
        continue;
     else
        err_sys("accept error");
   }
}
```
处理accept、read、write、select和open这样的函数可以使用**重启**被中断的系统调用，**connect**被信号中断不能使用这样的重启，必须调用select等待连接完成。

### TIME_WAIT持续两个MSL的作用
- 1.可靠的关闭tcp的连接。比如网络拥塞，如果主动关闭方最后一个ACK没有被接收方收到的话，在此时因为持续了两个MSL而尚未关闭的TIME_WAIT就会把这些尾巴问题给处理掉，比如说，重新启动TIME_WAIT,然后重新发送给一次ACK。
- 2.防止由于没有持续TIME_WAIT的时间导致新的TCP连接建立起来，延迟的FIN重传包会干扰新的连接

### I/O复用

<img src="https://github.com/ShireHong/Doraemon/blob/master/UNP/source/五个IO模型比较.png"  
    alt="图片加载失败时，显示这段字"/>
 
 - select 函数
 ```
 int select(int maxfdp, fd_set *rdset,fd_set *writeset, fd_set *exceptset, const struct timeval *timeout);
 
struct timeval
{
  long tv_sec;
  long tv_usec;
}
 ```
 



