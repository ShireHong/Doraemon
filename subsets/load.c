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

/*以下解法比网上的解法更容易理解，而且特别简单，不需要把增加的值减回去*/


#define TH 34
//#define TH 152
int sp[]={5,8,21,10};

//int sp[]={90,80,40,30,20,12,10};

int st[100] = {0};
int best[100]= {0};
int sum1 = 0;
void load(int len,int t)
{
	int i,sum = 0;
	i=t;
	if(i >= len)
	{
		for(i=0;i<len;i++)
		{
			//printf("%d ",st[i] );
			sum += st[i];
		}
		//printf("\n");
		//printf("sum = %d\n",sum);
		if(sum > sum1 && sum <= TH )
		{
			sum1 = sum;
			for(i=0;i<len;i++)
			{
				best[i] = st[i];
			}
		}
		
		
		return ;		
	}else{
		st[i] = 0;
		load(len,i+1);
		st[i]=sp[i];
		load(len,i+1);
	}
	
}


int main()
{
	int i, len = sizeof(sp)/sizeof(int);
	printf("%d\n", len);

	load(len,0);

	for(i=0;i<len;i++)
	{
		printf("%d ",best[i] );
	}
	printf("\n");
}