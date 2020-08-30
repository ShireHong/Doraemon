#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
求公共的最大字串
*/



/*
*例子
* [1,2,3,2,1]
* [3,2,1,4]
*
*output = [3,2,1]
*/


/* 解题思路
* 这道题按照滑动窗口的方法来解，这个题类似有点像两列火车追赶的意思，固定短的列车不动，长火车往前开，短火车的长度等于
* 最大滑动串口的大小
* 
* 这里长列车的长度不是自己的长度，需要加上短列车的长度-1
* 此题会主要以长列车的变化为主，我们只要目前窗口的大小和短列车需要比较的起始点
* 所以此题主要有三种情况
*
* 1
* 当长列车的窗口的右指针小于短列车的长度时
* 这时候窗口大小时逐渐变大
* 短列车的//起始点//是从短列车的最后开始的
* 这个时候窗口的右指针在增加
*         _
*        |1| 2 3 2 1 x x x
*  3 2 1 |4|
*
* 2
* 这时候窗口大小已经等于短列车的长度了，
* 短列车的//起始点//自然等于其原来的起始点
* 这时候窗口会以最大短列车的长度向前进，右窗口的右指针加1，左指针就减1
*
*     _________
*    |1 2 3 2 1| x x x
*    |3 2 1 4  |
*      _______
*    1|2 3 2 1|x x x
*     |3 2 1 4|
*
* 3
* 这时候窗口额右指针已经大于长列车的长度了
* 短列车的//起始点//还是等于原来的起始点，只是这时候要考虑比较值的边界，因为右指针已经大于长度，所以右边界就是长列车的长度
* 
*           _________
*    1 2 3 |2 1 x x x|
*          |3 2 1 4  |
*            _______
*    12 3 2 |1 x x x|
*           |3 2 1 4|
*

*/







#define MAX(x,y)  ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)<(y)?(x):(y))


int base[] = {1,2,3,2,1,5};
int find[] = {1,2,1,4};


int main()
{
	int blen = sizeof(base)/sizeof(int);
	int flen = sizeof(find)/sizeof(int);
	int b_l = 0,b_r = 0;
	int count = 0;
	int s_l ,s_r,stemp;
	int fstart;
	int i ,cnt,rr;

	while(b_r < blen + flen -1) //窗口右指针的最大范围
	{
		
		cnt = 0;
		/*
		判定短列车的起始点，这里只关心短列车的起始点就够了，长列车的起始点时窗口左指针
		我们以长列车作为基准值，所以需要把长列车的基准值转化为短列车的基准值
		*/
		if(b_r < flen)
		{
			fstart = flen-1 - b_r;
		}
		else{
			fstart = 0-b_l;
		}
		
		/*
		窗口大小控制
		*/
		if(b_r - b_l < flen)	
		{
			/*
			右指针的边界，最大就是长列车的长度减1
			*/
			rr = MIN(blen-1,b_r);

			//printf("1:%d %d %d %d\n",b_l,b_r,fstart+b_l,rr);

			/*
			比较窗口内的值，如果相同就记录，记录第一次的起始值
			*/
			for(i = b_l;i <= rr;i++)
			{
				if(base[i] == find[fstart +i] )
				{
					if(cnt == 0)
					{
						stemp = i ;
					}
					cnt++;
					if(cnt > count)
					{
						s_l = stemp;
						s_r = i ;
					}
					count = MAX(cnt,count);
					//printf("%d\n",cnt);
				}
				else
				{					
					cnt = 0;
					//printf("%d\n",count);
				}
			}			
			b_r++;
		}
		else
		{
			b_l++;			
			//printf("2:%d %d\n",b_l,b_r);
		}		
		
	}
	
	printf("%d\n",count);
	for(i = s_l;i <= s_r;i++)
		printf("%d ",base[i]);
	printf("\n");
	
	return 0;
}