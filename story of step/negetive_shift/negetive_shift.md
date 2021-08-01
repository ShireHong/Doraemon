# 负数的移位

最近再做项目时发现，读取PSU的值需要通过移位，为此，又去了解了一下负数的移位的问题。
<img src="https://github.com/ShireHong/Doraemon/blob/master/story%20of%20step/negetive_shift/psu.png"  
    alt="图片加载失败时，显示这段字"/>

负数的移位在左移和右移的补数方面时不同的，数的右移需要截断，所以不能等价于除2的n次幂。负数转2进制需要+1，2进制转负数也要+1.


## 负数的移位：
以-96为例，其二进制数是1010 0000，若右移5位，根据负数移位规则，高位应该补1，则结果是1111 1101，则根据反补码是0000 0011 是-3，若我们根据按正数的理解，右移n位，表示除以2^n,则结果-3 = -96/2^5,但是如果移去的5位不是0，而是1，则结果就相差很大了。

如何使用代码实现负数的移位，获取正确的值。
以8位负数为例
```
#define BIT_POS(bit_num)                    ((bit_num) - 1)
#define BIT_MASK(bit_num)                   (uint8)(pow_2(bit_num) - 1)
#define COMPLEMENT(val, bit_num)            ((~(val) + 1) & BIT_MASK(bit_num))
#define COMPLEMENT_BYTE(val, bit_num)       ((((val) & ((uint8)1 << BIT_POS(bit_num))) == 0)?(int8)(val):(int8)(-COMPLEMENT(val, bit_num)))
```
**BIT_POS**	这个宏是为了计算移位时候用到的
**BIT_MASK**这个宏是用来做与运算，pow_2为2的n次幂运算，这个运算结果表示bit_num-1个bit都是1
**COMPLEMENT** 这个宏就是取val值的补码
**COMPLEMENT_BYTE**先判断这个值的最高位bit_num的bit是否为1，若为0则是按正数获取原值，若为1，则val是负数，通过对val反补码获得一个正值，补上负号。
