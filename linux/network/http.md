> 1989年，蒂姆·伯纳斯 - 李（Tim Berners-Lee）在论文中提出可以在互联网上构建超链接文档，并提出了三点.

**URI**：统一资源标识符。互联网的唯一ID

**HTML**：超文本文档

**HTTP**:传输超文本的文本传输协议

## 目录
- [HTTP应用场景](#HTTP应用场景)
- [什么是HTTP](#什么是HTTP)
- [不同版本的HTTP](#不同版本的HTTP)
- [HTTP报文详解](#HTTP报文详解)
- [HTTPS](#HTTPS)
- [HTTP特点小结](#HTTP特点小结)
- [HTTP识别](#HTTP识别)
- [HTTPS识别](#HTTPS识别)
- [HTTP面试题](#HTTP面试题)

---

### HTTP应用场景

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/http_application_sence.png"  
    alt="图片加载失败时，显示这段字"/>

### 什么是HTTP
HTTP(hypertext transport protocol)翻译过来为**"超文本传输协议"**，文本可以理解为简单的字符文字组合，也可以理解为更为复杂的音频或者图像等。那么将这个词语拆分为三个部分。

- [ ] "超文本"和"文本"相比多了一个字"超"，这样看来比文本丰富，因为它可以将多种文本/图像等进行**混合**，更重要的是可以从一个文本**跳转**到另一个文本(文本连接)。

- [ ] "传输"，传输的过程中需要沟通，沟通即可能一对一沟通也可能一对多沟通(进行内容协商)，无论怎么样，参加沟通的人数>1，想尽一切一切办法更快更好的完成相应的任务。

- [ ] "协议"，无规矩不成方圆，做机密项目之前需要签署保密协议，找工作要签"三方协议"，三方协议是学校，公司，和个人组成的协议，都是为了让大家受一定的约束，违反了即有相应的惩罚。

### 不同版本的HTTP

 - [ ] ***HTTP/0.9***

当时网络资源匮乏，0.9版本相对简单，采用纯文本格式，且设置为**只读**，所以当时只能使用"Get"的方式从服务器获得HTML文档，响应以后则关闭。如下所示
```
GET /Mysite.html
```
响应中只包含了文档本身。响应内容无响应头，无错误码，无状态码，可以说是"裸奔"。
```
<HTML>
	Hello world
</HTML>
HTTP/1.0
```
此时HTTP/0.9请求过程如下

- 1.应用层的HTTP建立在传输层的TCP之上并运用TCP可靠性等特性，先三次握手建立连接

- 2.客户端请求建立连接(此时只有GET)

- 3.服务端响应请求，数据以 ASCII 字符流返回给客戶端

- 4.传输完成，断开连接。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/HTTP_0_9.png"  
    alt="图片加载失败时，显示这段字"/>

- [ ]  ***HTTP1.0***

随着时代的进步，仅仅文本的传输无法满足需求，更多情况需要采用图文的方式才能生动的表达出自己的观点。随着1995年开发出Apache，同时其他的多媒体等技术发展迅速，从而进一步的促使HTTP新功能的出现。HTTP1.0在1996年诞生，增加了一下几个方面：

- 之前只有Get方法，现在增加Post(加参数)，Head方法

- 加入协议版本号，同时添加文件处理类型

- 加入HTTP Header，让HTTP处理请求更加灵活

- 增加响应状态码，标记出错的原因

- 提供国际化(不同语言)支持

==典型的请求过程==

```
GET /image.html HTTP/1.0
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64)

200 OK
Date: Tue, 17 Nov 2020 09:15:31 GMT
Content-Type: text/html
<HTML> 
一个包含图片的页面
  <IMG SRC="/image.gif">
</HTML>
```

**HTTP1.0通信过程**

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/HTTP_1_0.png"  
    alt="图片加载失败时，显示这段字"/>

- [ ] ***HTTP1.1***

1995年是不平凡的一年，网景公司和微软开启浏览器大战，谁都想当老大。1999年HTTP/1.1发布并成为标准，写入RFC，以为以后不管是网关还是APP等，只要你要使用HTTP，就得遵守这个标准。

- 继续增加了PUT等方法

- 允许持久连接

随着文件越来越大，图片等信息越来越复杂，如果每一次上传下载文件都需要建立连接断开连接的过程将增加大量的开销。为此，提出了**持久连接**，也就是一次TCP连接可以具有多个HTTP请求。当然持久连接是可选择的，如果考虑关闭，只需要使用Connecttion:close关闭即可。长连接如下图所示

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/HTTP_1_1.png"  
    alt="图片加载失败时，显示这段字"/>

- 强制要求Host头

我们知道，在电商系统中，经常会因为促销活动导致流量飙升，为了缓解流量，其中有种方法即**加缓存或者加服务器**。如果是单台服务器负载过大，数据库可能分库分表。数据结构算法中分而治之方法亦是如此。那么HTTP中，同样的道理，如果文件太大，就大文件切分为小文件块发送。

- [ ] ***HTTP 2***

HTTP/1.1的出现，几年间出来大量牛掰的互联网公司，发展实在是太快，但是HTTP1.1中这几点成为诟病

- 原因1 TCP自带慢启动
顾名思义，"慢启动"从0到1循循渐进。轿车启动不会按下按钮就直接起飞，而是缓慢调节到适合的速度。这不是挺好的？为什么会带来性能问题呢。我们知道一个页面有静态数据，动态页面，很多小文件在加载的过程中就会直接发起请求，这样导致太多的请求都会经历慢启动过程，花费时间太多。

- 原因2 多条TCP连接带宽竞争
带宽固定，多条TCP连接同时发起竞争带宽资源，由于各个TCP连接之间没有通信机制，也无法得知哪些资源优先级更高，从而导致想快速下载的资源反而延迟下载。

- 原因3 头部阻塞
阻塞，在网络编程中，我们采用异步，多路复用(epoll)方式尽量让cpu少等待多干事。在HTTP1.1中，虽然大家共用了一条TCP通道，但是第一个请求没有结束，第二请求就可能阻塞等待，也就是说**不能同时发送接收数据**。那么一个网页很多数据文件，如果能够同时发出请求，让部分数据文件能够得到响应并预处理，这样就大大的利用了带宽和cpu的资源。基于这些因素，在HTTP2中出现了新的方案

- [ ] 如何解决头部阻塞呢？

HTTP是**一问一答**的模式，大家都在这个队列排队导致堵塞，那就多个队列并发进行，也就是"对同一个域名发起多个长连接"。举个例子，在火车站排队买票的时候，如果只有一个窗口可用，大家只能苦等，多开几个窗口就可缓解这个问题。

这个时候用户数 x 并发数(上限6-8)已经不错得效果，但是互联网速度太快，火车站就这么大，窗口也就这么多，怎么办，建新的火车站进行**分流**(大部分城市都有什么东站 西站)。在这里叫做"域名分片"，使用多个域名，这些域名指向同一服务器。

- [ ] ***HTTP 3***

HTTP/2看似很完美了吧，但是Google轮子哥可不服，其他人在研究HTTP/2的时候，它们就在琢磨QUIC。那QUIC有啥牛掰的地方呢

> QUIC是Google开发的一个基于UDP且能像TCP一样具有可靠性特点的协议。具备像HTTP/2一样的应用数据二进制分帧传输。其主要解决的问题有两个。

- 进一步解决线头阻塞问题。通过独立不同流，让各个流之间实现相互独立传输，互不干扰

- 切换网络时的连接保持。wifi和3G/4G经常需要来回切换。基于TCP的协议，会因为网络的切换导致IP地址的改变。而基于UDP的QUIC协议，及时切换也可以恢复之前与服务器的连接。(这里推荐大家可以去看看MPTCP)


### HTTP报文详解
> 客户端与服务端进行交互的信息为报文。客户端为请求报文，服务端为响应报文。我们先用wireshark抓一个博客看看

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/message.png"  
    alt="图片加载失败时，显示这段字"/>
```
GET /article/12 HTTP/1.1
Host: www.xxx.cn
Connection: keep-alive
Cache-Control: max-age=0
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.106 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
Accept-Encoding: gzip, deflate
Accept-Language: zh-CN,zh;q=0.9
Cookie: SESSION=so9nlsvenminor5abs65sh9dsa
HTTP/1.1 200 OK
Server: nginx
Date: Sun, 17 May 2020 17:04:29 GMT
Content-Type: text/html; charset=UTF-8
Transfer-Encoding: chunked
Connection: keep-alive
Vary: Accept-Encoding
X-Powered-By: blade-2.0.6-BETA
Content-Encoding: gzip
```

请求报文

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/ask_msg.png"  
    alt="图片加载失败时，显示这段字"/>


请求报文通常由三部分组成：

- 起始行：描述请求或者响应的基本信息

- 头部字段集合：key-value形式说明报文

- 消息正文：实际传输诸如图片等信息。

**1.请求方法**
||请求方法|方法描述|
|-|-|-|
|1|GET|请求服务器某一资源|
|2|POST|向指定资源提交数据进行处理请求，数据包含在请求体中|
|3|HEAD|用于确认URI的有效性及资源更新的日期时间，不返回报文主体，只返回报文文首部|
|4|PUT|用于传输文件，将文件内容放进报文主体中，保存到URI指定位置上|
|5|DELETE|与PUT相反，请求URI删除指定资源|
|6|OPTIONS|查询针对请求URI指定的资源支持的方法|
|7|TRACE|用于追踪路径。发送请求时，发送请求时，首部字段MAX-FORWARDS会指定一个数值，每经过一个服务器后，该数值减1.当该数值位0时，停止传输，最后接收到的服务器响应|
|8|CONNECT|用于在与代理服务器通信时建立隧道，实现隧道协议进行TCP通信|

**2.URI**
> 统一资源标识符(Uniform Resource Identifier),严格来说不等于网址，它包含URL和URN，可是URL太出名了以致于URL="网址"。无论开发，测试运维配置都离不开URI,所以好好掌握。

网络层的IP主要目的是解决**路由和寻址**。现在的IP地址按照"."分割，总共2的32次方大约42亿。对于计算机来说比较方便，但是对于人类来说还是不容易记忆，此时出现DNS了，他把IP地址**映射**为我们平时常见的"redis.org"，按照"."分割域名，从左到右级别越高，最右边为"顶级域名"。如下图所示

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/dns_class.png"  
    alt="图片加载失败时，显示这段字"/>

好了，现在TCP提供可靠(数据不丢失)且字节流(数据完整性)，而且也有方便我们记忆的域名，但是互联网资源千万种，也不知道访问什么(图片，文字，视频一大堆)，这个时候URI(统一资源标识符)出现了，那长啥样？

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/URI_format.png"  
    alt="图片加载失败时，显示这段字"/>

- 协议名:HTTP协议，另外还有ftp等协议。告知访问资源时使用什么协议。

紧接着是分隔符:"://"

- 主机名：标记互联网主机，可以是IP也可以是域名，如果不写端口则使用默认端口，例如HTTP为80，HTTPS为443.

- 登录认证信息：登录主机时的用户名密码(不建议，直接告诉了别人你的隐私信息)

- 资源所在位置：资源在主机上的位置，使用“/”分隔多级目录，在这里是“/en/download.html”。注意，必须"/"开头

- 参数：用"?"开始，表示额外的请求要求。通常使用"key=value"的方式存在，如果多个"key=value"则使用"&"相连。

看几个例子
```
http://nginx.org/en/download.html

file:///E:/Demo/index/
```
> 这里注意是三个"///"，因为前面"://"作为分隔符，资源路径按照"/"开头。

既然规则这么多，对于接收方而言需要完成的解析也需要遵守规则，全球用户很多使用HTTP，每个国家地区所使用语言不同，HTTP为了能对其进行统一处理，引入了URI编码，方法比较简单，将非ASCII或者特殊字符全部转换为十六进制字节值，同时在前面加入"%"。比如空格被转换为"%20","中国"就编码为"%E4%B8%AD%E5%9B%BD%0A"。

**3.请求体**

响应报文

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/response_msg.png"  
    alt="图片加载失败时，显示这段字"/>

- 状态行----服务器响应的状态

- 版本号：使用的HTTP什么版本

- 状态码：不同数字代表不同的结果，就如我们在编码时，通过返回不同的值代表不同的语义。

HTTP状态码通常分为5种类型，分别以1～5五个数字开头，由3位整数组成

|分类|分类描述|
|-|-|
|1xx|信息，服务器收到请求，需要请求者继续执行操作|
|2xx|成功，操作被成功接收并处理|
|3xx|重定向，需要进一步的操作以完成请求|
|4xx|客户端错误，请求包含语法错误或无法完成请求|
|5xx|服务器错误，服务器在处理请求的过程中发生了错误|

`HTTP状态码列表`

|状态码|状态码英文名称|中文描述|
|-|-|-|
|100|Continue|继续。客户端应继续其请求|
|101|Switching Protocols|切换协议。服务器根据客户端的请求切换协议。只能切换到更高级的协议，例如，切换到HTTP的新版本协议|
|200|OK|请求成功。一般用于GET与POST请求|
|201|Created|已创建。成功请求并创建了新的资源|
|202|Accepted|已接受。已经接受请求，但未处理完成|
|203|Non-Authoritative Information|非授权信息。请求成功。但返回的meta信息不在原始的服务器，而是一个副本|
|204|No Content|无内容。服务器成功处理，但未返回内容。在未更新网页的情况下，可确保浏览器继续显示当前文档|
|205|Reset Content|重置内容。服务器处理成功，用户终端（例如：浏览器）应重置文档视图。可通过此返回码清除浏览器的表单域|
|206|Partial Content|部分内容。服务器成功处理了部分GET请求|
|300|Multiple Choices|多种选择。请求的资源可包括多个位置，相应可返回一个资源特征与地址的列表用于用户终端（例如：浏览器）选择|
|301|Moved Permanently|永久移动。请求的资源已被永久的移动到新URI，返回信息会包括新的URI，浏览器会自动定向到新URI。今后任何新的请求都应使用新的URI代替|
|302|Found|临时移动。与301类似。但资源只是临时被移动。客户端应继续使用原有URI|
|303|See Other|查看其它地址。与301类似。使用GET和POST请求查看|
|304|Not Modified|未修改。所请求的资源未修改，服务器返回此状态码时，不会返回任何资源。客户端通常会缓存访问过的资源，通过提供一个头信息指出客户端希望只返回在指定日期之后修改的资源|
|305|Use Proxy|使用代理。所请求的资源必须通过代理访问|
|306|Unused|已经被废弃的HTTP状态码|
|307|Temporary Redirect|临时重定向。与302类似。使用GET请求重定向|
|400|Bad Request|客户端请求的语法错误，服务器无法理解|
|401|Unauthorized|请求要求用户的身份认证|
|402|Payment Required|保留，将来使用|
|403|Forbidden|服务器理解请求客户端的请求，但是拒绝执行此请求|
|404|Not Found|服务器无法根据客户端的请求找到资源（网页）。通过此代码，网站设计人员可设置“您所请求的资源无法找到”的个性页面|
|405|Method Not Allowed|客户端请求中的方法被禁止|
|406|Not Acceptable|服务器无法根据客户端请求的内容特性完成请求|
|407|Proxy Authentication Required|请求要求代理的身份认证，与401类似，但请求者应当使用代理进行授权|
|408|Request Time-out|服务器等待客户端发送的请求时间过长，超时|
|409|Conflict|服务器完成客户端的PUT请求是可能返回此代码，服务器处理请求时发生了冲突|
|410|Gone|客户端请求的资源已经不存在。410不同于404，如果资源以前有现在被永久删除了可使用410代码，网站设计人员可通过301代码指定资源的新位置|
|411|Length Required|服务器无法处理客户端发送的不带Content-Length的请求信息|
|412|Precondition Failed|客户端请求信息的先决条件错误|
|413|Request Entity Too Large|由于请求的实体过大，服务器无法处理，因此拒绝请求。为防止客户端的连续请求，服务器可能会关闭连接。如果只是服务器暂时无法处理，则会包含一个Retry-After的响应信息|
|414|Request-URI Too Large|请求的URI过长（URI通常为网址），服务器无法处理|
|415|Unsupported Media Type|服务器无法处理请求附带的媒体格式|
|416|Requested range not satisfiable|客户端请求的范围无效|
|417|Expectation Failed|服务器无法满足Expect的请求头信息|
|500|Internal Server Error|服务器内部错误，无法完成请求|
|501|Not Implemented|服务器不支持请求的功能，无法完成请求|
|502|Bad Gateway|充当网关或代理的服务器，从远端服务器接收到了一个无效的请求|
|503|Service Unavailable|由于超载或系统维护，服务器暂时的无法处理客户端的请求。延时的长度可包含在服务器的Retry-After头信息中|
|504|Gateway Time-out|充当网关或代理的服务器，未及时从远端服务器获取请求|
|505|HTTP Version not supported|服务器不支持请求的HTTP协议的版本，无法完成处理|


**4.消息体**

> 上面大部分都是涉及到header部分，还有非常重要的body，everybody

头字段注意事项:

1.字段名`不区分大小写`，例如“Host”也可以写成“host”，但首字母大写的可读性更好；

2.字段名里`不允许出现空格`，可以使用连字符“-”，但不能使用下划线`_`。例如，“test-name”是合法的字段名，而“test name”“test_name”是不正确的字段名;

3.字段名后面必须紧接着“:”，不能有空格，而":"后的字段值前可以有多个空格；

4.字段的顺序是没有意义的，可以任意排列不影响语义；

5.字段原则上不能重复，除非这个字段本身的语义允许，例如 Set-Cookie。

HTTP的body常常被分为这几种的类别:

1.text:超文本text/html,纯文本text/plain

2.audio/video:音视频数据

3.application: 可能是文本，也可能是二进制，交给上层应用处理

4.image: 图像文件。image/png等

但是带宽一定，数据大了通常考虑使用压缩算法进行压缩，在HTTP中使用Encoding type表示，常用的压缩方式有下面几种:

1.gzip
> 一种数据格式，默认且目前仅使用deflate算法压缩data部分

2.deflate
> deflate是一种压缩算法，是huffman编码的一种加强

3.br
> br通过变种的LZ77算法、Huffman编码以及二阶文本建模等方式进行数据压缩，其他压缩算法相比，它有着更高的压塑压缩效率

使用相应的压缩方法在带宽一定的情况下确实有不错的效果，但是gzip等主要针对文件压缩效果不错，但是对视频就不行了。这个时候是不是可以使用数据结构中常用的分而治之，大化小再合并的方式呢

ok，在报文中使用"Transer-Encoding:chunked"表示，代表body部分数据是分块传输的。另外在body中存在一个content-length字段表示body的长度，两者不能共存，另外很多时候是流式数据，body中没有指明content-length，这个时候一般就是chunked传输了。

现在可以通过采用分块的方式增强带宽的利用率，那他的编码规则如何呢

1.每一个分块包含长度和数据块

2.长度头按照CRLF结束

3.数据块在长度快后，且最后CRLF结尾

3.使用长度0表示结束，"0\r\n\r\n"

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/chunked_fragment.png"  
    alt="图片加载失败时，显示这段字"/>

分块解决了咋们一部分问题，但是有的时候我们想截断发送怎么办呢。在HTTP中提供了使用字段“Accept - Ranges: bytes”，明确告知客户端：“我是支持范围请求的”。那么Range范围是怎样的呢，Range从0开始计算，比如Range:0-5则读取前6个字节，服务器收到了这个请求，将如何回应呢?

1.合法性检查。比如一共只有20字节，但是请求range：100-200。此时会返回416----"范围请求有误"

2.范围正常，则返回216，表示请求数据知识一部分

3.服务器端在相应响应头增加Content-Range,格式"bytes x-y/length"。

***断点续传怎么操作？***
- 1.查看服务器是否支持范围请求并记录文件大小

- 2.多个线程分别负责不同的range

- 3.下载同时记录进度，即使因为网络等原因中断也没事，Range请求剩余即可

现在我们通过MIME-TYPE和Encoding-type可以知道body部分的类型，下一步将是对内容进行协商。HTTP中，请求体中使用Accept告诉服务端需要什么类型数据(我能处理哪些类型数据)，响应头中使用Content表明发送了什么类型数据，具体如下图所示

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/content.png"  
    alt="图片加载失败时，显示这段字"/>

好了，为了各个国家民族顺利友好的沟通和明确的区分。HTTP请求头中使用"type-subtype"，注意此时分隔符是"-"。比如en-GB表示英式英语，zh-CN表示常用的汉语，那对于客户端而言，它通过Accept-Language来标记自己可以理解的自然语言，对应的服务端使用Content-Language表明实体数据使用的语言类型，如下图所示。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/charset_code.png"  
    alt="图片加载失败时，显示这段字"/>



**5.Cookie机制**

> HTTP是无状态、无记忆的，Cookie机制的出现让其有记忆功能，是怎么个实现呢

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/cookie.png"  
    alt="图片加载失败时，显示这段字"/>

从上图我们可以知道Cookie是由***浏览器负责存储***，并不是操作系统负责，我们换个浏览器打开同样的网页，服务就认不出来了。

Cookie常见的应用一个是**身份识别**，一个是**广告追踪**，比如我们在访问网页视频或者图片的时候，广告商会悄悄给我们Cookie打上标记，方便做关联分析和行为分析，从而给我推荐一些相关内容。


**6.HTTP代理**

> 之前介绍的都是一问一答的情景，但是在大部分的情况下都会存在多台服务器进行通信服务。其中比较常见的就是在请求方与应答方中间增加一个中间代理。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/agent.png"  
    alt="图片加载失败时，显示这段字"/>

代理作为中间位置，相对请求方为服务端，相当于后端服务端为请求方。代理常见的功能为***负载均衡***。在负载均衡中需要区分正向代理与反向代理，其中也就会涉及***调度算法***，比如轮询，一致性哈希等。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/forward_and_reverse_agent.png"  
    alt="图片加载失败时，显示这段字"/>


### HTTPS

> 好人占多数，坏人也不少。总有些要搞坏事，因为HTTP是明文，所以需要想办法保护明文，从而出现了https。

安全四要素

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/sercurity_elements.png"  
    alt="图片加载失败时，显示这段字"/>

#### 机密性

> 对信息进行保密，只能可信的人可以访问(让我想起时间管理者)。

#### 完整性

> 数据在传输过程中内容不被"篡改"。虽然机密性对数据进行保密了，但是有上策也有下策(hack)

#### 身份认证

> 证明自己的身份是本人，保证其消息发给可信的人

#### 不可否认

> 君子一言驷马难追，说话算数，说过的话做过的事要有所保证

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/http_and_https.png"  
    alt="图片加载失败时，显示这段字"/>

从上图我们知道HTTPS无非是在传输层和应用层中间加了一层TLS，正是TLS紧跟当代密码学的步伐，尽全力的保障用户的安全。老规矩，我们用wireshark看看长什么样子。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/TLS.png"  
    alt="图片加载失败时，显示这段字"/>

可以看出在交互的过程中多了不少新东西，了解TLS,TLS由SSL握手协议，SSL修改密码规范协议，SSL警报协议，SSL记录协议组成。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/TLS_components.png"  
    alt="图片加载失败时，显示这段字"/>

#### SSL握手协议

> 相对于三次握手

#### 记录协议

> 记录为TLS发送接收数据的基本单位。它的自协议需要通过记录协议发出。如果多个纪录数据则可以一个TCP包一次性发出。

#### 警报协议

> 类似HTTP状态码，通过反馈不同的消息进行不同的策略。

#### 变更密码规范协议

> 告诉对方，从此刻开始，后续的数据将使用加密算法进行加密再传输。

- [ ] 对称加密与非对称加密

- 对称加密

> 对称加密，顾名思义，加密方与解密方使用同一钥匙(秘钥)。具体一些就是，发送方通过使用相应的加密算法和秘钥，对将要发送的信息进行加密；对于接收方而言，使用解密算法和相同的秘钥解锁信息，从而有能力阅读信息。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/symmetric_encryption.png"  
    alt="图片加载失败时，显示这段字"/>

- 非对称加密

> 在对称加密中，发送方与接收方使用相同的秘钥。那么在非对称加密中则是发送方与接收方使用的不同的秘钥。其主要解决的问题是防止在秘钥协商的过程中发生泄漏。比如在对称加密中，小蓝将需要发送的消息加密，然后告诉你密码是123balala,ok,对于其他人而言，很容易就能劫持到密码是123balala。那么在非对称的情况下，小蓝告诉所有人密码是123balala,对于中间人而言，拿到也没用，因为没有私钥。所以，非对称密钥其实主要解决了密钥分发的难题。如下图

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/asymmetric_encryption.png"  
    alt="图片加载失败时，显示这段字"/>

- 混合加密

> 非对称加密算法，大多数是从数学问题演变而来，运算速度较慢。混合加密所谓取长补短。通信过程中使用RSA等解决密钥交换问题，然后使用随机数产生的在对称算法中的会话密钥，最后使用加密。对方使用私钥解密得到的密文取出会话秘钥，这样就实现了密钥交换。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/mixed_encryption.png"  
    alt="图片加载失败时，显示这段字"/>

通过混淆加密等方式完成了机密性任务，作为Hack只需要伪造发布公钥或者作为之间人窃听密文。但是我们知道安全是四要素，还需要保证数据的完整性，身份认证等。

- 摘要

> 摘要算法可以理解为一种特殊的"单向"加密算法，无密钥，不可逆。在平时项目中，应该大家都是用过MD5，SHA-1。但是在TLS中使用SHA-2。

假设小A转账5000给小C，小A加上SHA-2摘要。网站计算摘要并对比，如果一致则完整可信。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/abstract.png"  
    alt="图片加载失败时，显示这段字"/>

此时小B想修改小A给的money，这个时候网站计算摘要就会发现不一样，不可信

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/abstract_no.png"  
    alt="图片加载失败时，显示这段字"/>

HTTPS请求建立连接过程

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/HTTPS_hand_shake.png"  
    alt="图片加载失败时，显示这段字"/>

`注意：`

1.首先通过非对称加密建立通信过程
2.在握手阶段，为什么使用3个随机数，一方面防止「随机数 C」被猜出，另一方增加Session key随机性
3.Client发出支持的「对称/非对称加密」算法
4.server返回选用的「对称/非对称加密」算法
5.Client对算法进行确认
6.Server对算法进行确认

根据wireshak结果，对TLS进一步剖析。TCP三次握手建立连接，作为礼貌，Client先打招呼"Client Hello"。里面包含了Client的**版本号、所支持的密码套件和随机数**，如下图所示

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/client_hello.png"  
    alt="图片加载失败时，显示这段字"/>

Server端表示尊重，回复"Server Hello",同时进行版本校对，给出随机数(Server Random)，从Client算法列表中选择一个密码套件，在这里选择的"TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256"。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/cipher_suite.png"  
    alt="图片加载失败时，显示这段字"/>

这里的"TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256"什么意思呢?

> 密码套件选择椭圆曲线加RSA、AES、SHA256

双方通过证书验证身份。因为本机服务器选用了ECDHE算法，为了实现密钥交换算法，它会发送证书后把椭圆曲线的公钥（Server Params）连带"Server Key Exchange"消息发送出去。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/server_key_exchange.png"  
    alt="图片加载失败时，显示这段字"/>

意思是，刚才混合加密套件比较复杂，给你个算法参数，好好记住，别弄丢了。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/server_hello_done.png"  
    alt="图片加载失败时，显示这段字"/>

随后服务端回复"hello done"告知打招呼完毕

打完招呼完毕后，客户端对证书进行核实。然后根据密码套件也生成椭圆曲线的公钥，用"Client Key Exchange"消息发给服务器

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/client_key_exchange.png"  
    alt="图片加载失败时，显示这段字"/>

此时客户端和服务端都有了密钥交换的两个参数(Client Params、ServerParams），然后通过 ECDHE 算法算出了一个新的值，叫“Pre-Master”

有了主密钥和会话密钥，客户端发送“Change Cipher Spec”和“Finished”消息，最后将所有消息加上摘要发送给服务器验证。

服务器同样发送“Change Cipher Spec”和“Finished”消息，握手结束，开始进行HTTP请求与响应


#### 域名

> 我们知道域名的出现让我们更容易记忆，按照"."分割，越靠近右边级别越高。域名本质是一个名字空间系统，采用多级域名的方式区分不同的国家，公司等，作为一种身份的标识。

- 根域名服务器（Root DNS Server）：管理顶级域名服务器，返回“com”“net”“cn”等顶级域名服务器的 IP 地址；

- 顶级域名服务器（Top-level DNS Server）：管理各自域名下的权威域名服务器，比如
com 顶级域名服务器可以返回 apple.com 域名服务器的 IP 地址；

- 权威域名服务器（Authoritative DNS Server）：管理自己域名下主机的 IP 地址，比如apple.com 权威域名服务器可以返回 `www.apple.com `的 IP 地址


### HTTP特点小结

> 写到这里，说它简单是假的，简单的东西通常更具有扩展的可能性。根据需求的变更，越来越复杂。

- 1.**灵活且易扩展**，他的头部字段很多都是可定制且可扩展

- 2.**应用广泛**。各个领域都有涉及。"跨平台，跨语言"

- 3.**无状态**。没有记忆功能，少功能即少占用资源。另外无状态更容易搭建集群，通过负载均衡将请求转发到任意一台服务器。缺点是无法支持需要连续步骤的"事务"操作。我们知道TCP协议有11种状态，不同状态代表通信过程中不同的含义。同样操作系统中的进程也有执行，就绪，活动阻塞等多种状态。但是HTTP全程都是"懵逼"无状态。比如小华请求服务器获取视频X，服务器觉得可行就发给小华。小华还想获取视频Y，这时服务器不会记录之前的状态，也就不知道这两个请求是否是同一个，所以小华还得告诉服务器自己的身份。

- 4.**明文**。优点是能让开发人员通过wireshark工具更直观的调试。缺点即裸奔互联网，没隐私可言。

- 5.**可靠传输**。HTTP为应用层协议，基于TCP/IP，而TCP为“可靠”传输协议，因此HTTP能在请求应答中"可靠"传输数据。

- 6.**应用层协议**。应用层协议很多，其中常用的邮件协议SMTP，上传下载文件ftp，默认端口22/23，SSH远程登录(XSHELL)。这些应用层协议都太专一，而HTTP通过各种头部字段，实体数据的组合，并综合缓存代理等功能，不得不说是网络中的冠希哥。

### HTTP识别

> 这里说的识别，通过代码层面(libpcap封装)实现HTTP的识别，也能进一步体现TCP/IP协议栈的分层特性。先看回忆一下IP头部格式。

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/IP_header.png"  
    alt="图片加载失败时，显示这段字"/>

注意头部中的协议字段，如果此字段值为0x0600则为TCP分组。当知道了是TCP分组后，是不是可以通过TCP头部中端口(80)就可以判断为HTTP呢，不能的，很多情况都会**使用动态端口的方式**进行部署。此时可以通过HTTP中的关键字进行判断。如果为HTTP，再通过头部字段中的"Content-type"，charset等确认文本信息，编码方式，最后采用解码算法进行还原。


#### HTTPS 识别

> 方法一也是比较直接的方法是直接通过抓包工具，插件配置即可。这里想给大家分享另一种思路和在Linux持续捕包的方法。

- 数据采集

> 使用python的dpkt库(pip install dpkt即可)，dpkt库方便对每一层协议进行拆解，同时也能进行流的拆分以及特征的提取。下面举一个通过无头浏览的方式自动化采集流量(ps如果需要较大规模的流量采集则可以考虑使用docker集群的方式)

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/read_pcap.png"  
    alt="图片加载失败时，显示这段字"/>

- 根据所提特征生成npz(实际上是numpy提供的数组存储方式)
- 使用开源skearn库进行模型训练并识别预测，此处假设使用SVM(仅使用默认参数)

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/svm.png"  
    alt="图片加载失败时，显示这段字"/>

- 识别结果(参数进行适度调整定会更好的效果)

<img src="https://github.com/ShireHong/Doraemon/blob/master/linux/network/pic/result.png"  
    alt="图片加载失败时，显示这段字"/>

### HTTP面试题

- Get和Post区别

- HTTP与HTTPS区别

- HTTP通信过程

- 游览器输入一个地址。到页面展示中间经历了哪些步骤？

- cookies机制和session机制的区别：

- HTTP请求报文与响应报文格式

- 一次完整的HTTP请求所经历的7个步骤

- HTTP优化方案

- 不同版本的HTTP区别

- HTTP优点缺点

- URI和URL的区别

- 如何判断是否为http

- HTTP 1.1引入分块传输编码提供了以下几点好处

- 长连接与短连接的区别，以及应用场景

- 常见web攻击

- 站内跳转和外部重定向有何区别

- HTTP的keep-alive是干什么的？

- 关于Http 2.0 你知道多少？

- 讲讲304缓存的原理

- HTTP与RPC异同
