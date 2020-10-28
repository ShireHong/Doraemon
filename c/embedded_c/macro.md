### 宏的一直展开
当使用参数调用宏时，会将参数替换为宏主体，并与其他输入文件一起检查结果，以进行更多的宏调用,可以将部分来自宏主体和部分自变量的宏调用组合在一起。

```
#define twice(x) (2*(x))
#define call_with_1(x) x(1)


int main()
{
    printf("%d\n",call_with_1 (twice));
}
```
通过使用"gcc -E macro_test.c -o mt.i"获得预编译结果
**部分截取**
```
# 7 "macro_test.c"
int main()
{
    printf("%d\n",(2*(1)));
}

```
看到宏被完全替换。

### 宏定义函数，使用do_while
在使用宏定义一个函数的时候，常常会在宏定义函数增加";",这会造成代码错误，例如:
```
#define FUN(p, limit)           \
{ char *lim = (limit);         \
  while (p < lim) {            \
    if (*p++ != ' ') {         \
      p--; break; }}}

if (*p != 0)
  FUN(p, lim);
else …
```
在if else中FUN后面还有个分号，会导致这个地方不是一条语句，而是两条语句，这样else就会出错。更改define函数
```
#define FUN(p, limit)     \
do { char *lim = (limit);         \
     while (p < lim) {            \
       if (*p++ != ' ') {         \
         p--; break; }}}          \
while (0)
```
do while只执行一次，不会形成额外代码。

### 宏的嵌套
宏参数在被替换为宏主体之前必须经过完全宏扩展，替换后，将再次扫描整个宏主体，包括替换的参数，以查找要扩展的宏。
如果参数包含任何宏调用，则它们将在第一次扫描时扩展，那么结果不包含任何宏调用，因此第二次扫描不会更改它。
如果按照给定的方式替换了参数，并且没有进行预扫描，则剩余的单个扫描将找到相同的宏调用并产生相同的结果。

```
#define AFTERX(x) #x
#define XAFTERX(x) AFTERX(x)
#define TABLESIZE 1024
#define BUFSIZE TABLESIZE
```
- 然后AFTERX（BUFSIZE）扩展为BUFSIZE，而XAFTERX（BUFSIZE）扩展为1024而不是TABLESIZE，预扫描始终会进行完整的扩展

- 如果要扩展宏，然后对其扩展进行字符串化或串联，则可以通过使一个宏调用进行该字符串化或串联的另一宏来实现