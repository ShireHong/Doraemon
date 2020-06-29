#include<stdio.h>
#include<stdlib.h>

/*求一个有序的数组的平方后的排序*/

/*
*例如
*input = [ - 4，-1,0,3,10]
*output = [0,1,9,16,100]
*
*/

/*
*解题思路有点像快速排序，通过头指针和尾指针进行比较
*利用数组本身的特性，最先比较出来的结果一定是最大的，
*将比较出来的值放到存储的最右边，然后移动较大一边的指针
*/



int sample[] = {-5,-4,-1,0,3,4,5};

int main()
{
	int store[7]={0};
	int start = 0,end = sizeof(sample)/sizeof(int) - 1;	
	int i=end,j;

	while(start <= end)
	{
		if(abs(sample[start]) >= abs(sample[end]))
		{
			store[i] = sample[start] * sample[start];
			start++;
		}
		else{
			store[i] = sample[end] * sample[end];
			end--;
		}
		i--;
	}
	end = sizeof(sample)/sizeof(int) - 1;	
	for(i = 0;i<=end;i++)
	{
		printf("%d ",store[i]);
	}
	printf("\n");
}