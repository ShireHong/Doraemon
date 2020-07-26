#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
八皇后问题，皇后所处的位置的行和纵向都不能有其他皇后，而且对角线上也不能有皇后

例子:
1 5 8 6 3 7 2 4

在一个8x8的棋盘上
表示皇后在每一行的位置。

此题类似旅行商的问题，约束条件不一样

*/

/*本来想通过二维数组来实现，但是没有成功，还是使用了全排列来解决*/



int sp[8]={1,2,3,4,5,6,7,8};
int st[8] = {0};

int sum1 = 0;


int cmp(int nn, int t)
{
	int i;
	
	for(i=0;i<t;i++)
	{
		/*约束条件，若同一纵列有皇后，或者存在对角线上的皇后，都舍弃*/
		if(nn == st[i] || abs(st[i] - nn) == t-i)
			return 1;
	}
	return 0;

	
}

void queen(int len,int t)
{
	int i,j;
	if(t >= len)
	{
		sum1++;
		for(i=0;i<len;i++)
		{			
			printf("%d ",st[i]);		
		
		}
		printf("\n");
		
		return;
	}else{
		for(i=0;i<len;i++)
		{
			/*满足条件就存储值*/
			if(!cmp(sp[i],t) )
			{
				st[t] = sp[i];
				queen(len,t+1);
			}
			
			
		}
	}
}


int main()
{
	int i, len = sizeof(st)/sizeof(int);
	printf("%d\n", len);

	queen(len,0);

	printf("sum1 = %d\n",sum1);

}