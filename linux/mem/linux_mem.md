### 一、走进 linux 内存
 #### 1、内存是什么？
- 1) 内存又称主存，是 CPU 能直接寻址的存储空间，由半导体器件制成
- 2) 内存的特点是存取速率快

<img src="https://github.com/ShireHong/algorithm-note/blob/master/linux/mem/hardware_componet.jpg" width="382" height="160" 
    alt="图片加载失败时，显示这段字"/>
    
#### 2、内存的作用
- 1) 暂时存放 cpu 的运算数据
- 2) 硬盘等外部存储器交换的数据
- 3) 保障 cpu 计算的稳定性和高性能

|计算机各级存储|典型存储容量|典型访问时间|
|-|-|-|
|可移动介质|几百GB~几TB|几ms~几十ms|
|硬盘|几百GB~几TB|3ms~15ms|
|内存|几百MB~几十GB|100ns~150ns|
|二级cache|几百KB~几MB|40ns~60ns|
|一级cache|几十B~几百KB|5ns~10ns|
|寄存器|几十B~几百B|1ns|

### 二、Linux内存地址空间
#### 1、linux 内存地址空间 Linux 内存管理
<img src="https://github.com/ShireHong/algorithm-note/blob/master/linux/mem/mem_management.jpg" width="856" height="568" 
    alt="图片加载失败时，显示这段字"/>
