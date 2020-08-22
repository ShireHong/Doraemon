#include<stdio.h>
#include<stdlib.h>

/*求最大面积*/

/*
*例如
*input = [ 3，8，6，4，5，7，9，7，2]
*output = 42
*
*从8到第二个7，高度为7，经过长度6，6x7
*
*/

/*******************************************************
*双指针思路很简单
*利用双指针，求解两个指针内的面积
*指针变化条件时当左边的值小于右边的值，就移动左边的指针，反之，移动右边的
*/

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))


int sample[] = {1,8,6,2,5,4,8,3,7};

int main()
{
	int start = 0,end = sizeof(sample)/sizeof(int) - 1;	
	int a,b;
	int sum = 0,i;
	int square;

	while(start < end)
	{
		int l = sample[start];
		int r = sample[end];
		square = MIN(l,r)*(end-start);
		if(square > sum)
		{
			a = start;
			b = end;
		}
		sum = MAX(sum,square);
		
		if(l < r)
			start++;
		else
			end--;
	}
	printf("%d\n ",sum );
	//printf("%d %d\n ",a,b);
	
	for(i = a;i<=b;i++)
	{
		printf("%d ", sample[i]);
	}
	printf("\n");
	
	return 0;
}