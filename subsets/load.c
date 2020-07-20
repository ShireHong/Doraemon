#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
例子
输入 5  21 10
最大转载 34
输出  21 10
                   -  ---- --
                  5      	  0
               /     \      /   \
              21      0    21    0
            /    \   / \   /      \
          10      0 10  0 10       0

*/


#define TH 34

int sp[]={5,8,21,10};

int st[100] = {0};
int best[100]= {0};
int sum1 = 0;
void load(int len,int t)
{
	int i,sum = 0;
	i=t;
	if(i > len)
	{
		for(i=0;i<len;i++)
		{
			sum += st[i];
		}
		if(sum > sum1 && sum <= TH)
		{
			for(i=0;i<len;i++)
			{
				best[i] = st[i];
			}
		}
		
		
		return ;		
	}
	/*当i值=>len时，通过递归出去计算，不然的话，会重复计算*/
	if(i<len)
	{	
		/*非常简单的递归思想，要么转载，要么不转载，计算所有情况*/
		st[i] = 0;
		load(len,i+1);
		st[i]=sp[i];
		load(len,i+1);
	}
	else
		load(len,i+1);
}


int main()
{
	int i, len = sizeof(sp)/sizeof(int);
	printf("%d\n", len);

	load(len,0);

	for(i=0;i<len;i++)
	{
		printf("%d ",best[i] );;
	}
	printf("\n");
}