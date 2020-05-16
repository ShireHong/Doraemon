#include<stdio.h>
#include<stdlib.h>

/*
	学会找规律，算法问题还是数学问题，找到规律才能解决，本题贵在理解其循环原理，先搞定大矩阵，在轮询小矩阵
*/

int main()
{
	int i=0,j=0,k=0,l=0;
	int a[5][5] = {
					{ 1, 2, 3, 4, 5},
					{ 6, 7, 8, 9,10},
					{11,12,13,14,15},
					{16,17,18,19,20},
					{21,22,23,24,25}
					
			      };
	int r=5,c=5;
	int n=0,count=0;
while(1)
{
	for(j=n;j<c-n;j++)
	{
		printf("%d ",a[i][j]);
		count++;
		if(count>24)
		{
			printf("\n%d\n",count);
			return 0;
		}
	}

	j=j-1;//j=2
	for(i=i+1;i<r-n;i++)
	{
		printf("%d ",a[i][j]);
		count++;
		if(count>24)
		{
			printf("\n%d\n",count);
			return 0;
		}
		
	}
	i=i-1;//2
	for(j=j-1;j>n-1;j--)
	{
		printf("%d ",a[i][j]);
		count++;
		if(count>24)
		{
			printf("\n%d\n",count);
			return 0;
		}
	}
	j=j+1;//0
	for(i=i-1;i>n;i--)
	{
		printf("%d ",a[i][j]);
		count++;
		if(count>24)
		{
			printf("\n%d\n",count);
			return 0;
		}
	}
	i=i+1;
	n++;
}
	return 0;
}
