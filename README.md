# 学习笔记

## 为什么？
```
一切伟大的行动和思想，都有一个微不足道的开始。
                                          --- 加缪
```
- [ ] 学无止境，以前代码的编写都是写完就丢，后续再看又去撸一遍，而且每次的思路都会有差别，在不停的积累新的知识，需要对比以前的不足，所以开始做这个记录来看看自己以前的想法。
- [ ] 总受有很多的新的知识会添加进来，新的算法，linux相关的知识，c++相关的知识，图形图像相关的知识等等，我相信我的大脑内存受制于人类共同的极         限，幸运的是他支持片外扩展。所以，我把这里作为我的永久非易失性的存储空间。
- [ ] 向那些神一样的程序员致敬， Linus Benedict           Torvalds（Linux之父），Richard Matthew Stallman（GNU），Dennis MacAlistair Ritchie（c语言和unix），John D. Carmack II（3D 引擎），Bill Joy（BSD TCP/IP）

## 目录
- [为什么？](#为什么？)
- [C语言](#C语言)
- [C++](#C++)
- [算法](#算法)
- [linux](#linux)
- [图形图像](#图形图像)
- [数据结构](#数据结构)
- [学习网站](#学习网站)

---
## C语言
自己实现的一关于数学和字符串处理的c语言练习，数据库是基于UNIX实现的，使用了hash算法，其实数据库最好的算法是B树，有时间会去重构：
- [ ] [在linux上实现一个数据库](https://github.com/ShireHong/unix_c_db) 
- [ ] [c语言小甜点](https://github.com/ShireHong/algorithm-note/tree/master/c)
       一些数学上的小练习，考察c语言基础能力
- [ ] **字符串问题汇总**
    - [ ] [双指针逆序](https://github.com/ShireHong/algorithm-note/blob/master/string/str_reverse.c)
- [ ] **基础面试题**
    - [ ] [嵌入式C](https://github.com/ShireHong/Doraemon/blob/master/c/embedded_c/embedded_c.md)

## C++
使用栈的功能实现了一个计算器，主要考察栈的使用机理
- [ ] [计算器的实现](https://github.com/ShireHong/algorithm-note/tree/master/c%2B%2B/calculator)

## 算法
- [ ]  **排序**:
    - [ ] [快速排序](https://github.com/ShireHong/algorithm-note/tree/master/sort) 
    - [ ] [归并排序](https://github.com/ShireHong/algorithm-note/tree/master/sort)
- [ ] [动态规划](https://github.com/ShireHong/algorithm-note/tree/master/dp) 
- [ ] [贪心算法](https://github.com/ShireHong/algorithm-note/tree/master/greedy) 
- [ ] **滑动窗口**:
    - [ ] [查找等长但排序不同的字符串](https://github.com/ShireHong/Doraemon/blob/master/slide_window/find_same_string.c)
    - [ ] [带有不同字符的最长子字符串](https://github.com/ShireHong/Doraemon/blob/master/slide_window/k_different_string.c)
- [ ] **双指针**:
    - [ ] [排序数组的平方和排序](https://github.com/ShireHong/Doraemon/blob/master/two_pointers/square_sort_vector.c)
    - [ ] [和为零的三元组](https://github.com/ShireHong/Doraemon/blob/master/two_pointers/three_num_zero.c)
    - [ ] [包含回退（backspace）的字符串](https://github.com/ShireHong/Doraemon/blob/master/two_pointers/backspace_string.c)
- [ ] **区间交叉**:
    - [ ] [找到不相交的区间](https://github.com/ShireHong/Doraemon/blob/master/overlap/remove_overlap.cpp)

## Linux
 > Linux有几大部分组成，进程管理、内存管理、文件系统以及网络管理
- [ ] **内存管理**
  - [ ] [Linux内存介绍](https://github.com/ShireHong/algorithm-note/blob/master/linux/mem/linux_mem.md) 这是我在微信上看到的关于linux内存的介绍，相当完善，所以把他整理放在这里
- [ ] **进程管理**
  - [ ] [进程](https://github.com/ShireHong/Doraemon/blob/master/linux/process/process.md) (这是腾讯技术的文章)编辑这篇文章的时候发现不能设置字体颜色。
- [ ] **网络管理**
  - [ ] [HTTP](https://github.com/ShireHong/Doraemon/blob/master/linux/network/http.md) 。

## 图形图像
- [ ] **OPENGL**:
  用于渲染2D、3D矢量图形的跨语言、跨平台的应用程序编程接口（API）,通过一个很好的网站[LearnOpenGL CN](https://learnopengl-cn.github.io/)感受到了它的神奇魅力，并自己搭建了Mingw平台去练习。
    - [ ] [练习](https://github.com/ShireHong/OpenGL/tree/master/OpenGL)
    - [ ] [BreakOut](https://github.com/ShireHong/OpenGL/tree/master/my_game/breakout) 基于OpenGL完成的一个游戏，主要是基于c++搭建一个框                     架，包含渲染，物理碰撞，声音（Mingw的声音库有问题，在研究），游戏逻辑。实现了一个2D引擎，基于这个引擎可以制作所有的2D游                     戏。
    - [ ] [AirCraft](https://github.com/ShireHong/OpenGL/tree/master/my_game/aircraft)根据上面的引擎开发的游戏，主要是练习多目标物理碰                       撞，使用C++的STL容器，但是算法有待改进。
 overlap/a.exe
 ## 数据结构
 >> 链表
 >>> 单链表
 >>>> - [ ] [约瑟夫环](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%93%BE%E8%A1%A8/Josephus_list.c)
 >>>> - [ ] [反转单链表](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%93%BE%E8%A1%A8/reverse_list.c)
 >>>> - [ ] [合并有序链表](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%93%BE%E8%A1%A8/merge_sort_list.c)
 >>>> - [ ] [寻找中间节点](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%93%BE%E8%A1%A8/find_mid_node_list.c)
 >>>> - [ ] [倒数k个节点](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%93%BE%E8%A1%A8/find_bottom_k_list.c)
 >>>> - [ ] [链表中环的长度](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%93%BE%E8%A1%A8/circle_length_list.c)

 >> 树
 >>> 二叉树
 >>>> - [ ] [树的层遍历](https://github.com/ShireHong/algorithm-note/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91/tree_traversal.c)
 >>>> - [ ] [树的路径之和](https://github.com/ShireHong/Doraemon/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91/tree_trace_sum.c)
 >>>> - [ ] [树的深度](https://github.com/ShireHong/Doraemon/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91/tree_depth.c)

 - [ ] [环形队列](https://github.com/ShireHong/algorithm-note/tree/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%8E%AF%E5%BD%A2%E9%98%9F%E5%88%97)


## 学习网站
- [ ] [C/C++资源](https://ezlippi.com/blog/2014/12/c-open-project.html),这个BLOG有很多开源的C/C++的资源，内容丰富，囊括很多方面的内容
- [ ] [C++学习](https://github.com/Light-City/CPlusPlusThings) , 很全面的C++学习资源，对入门学习有很大的帮助




