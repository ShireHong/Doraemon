#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
旅行商问题

这个算法把所有的路径直接找出来了，没有剪枝，原理就是回溯法

例子
以1为例：
					   ___________1_________	          
					  /           |         \	
			         2  		  3 	     4
			       /   \      	/   \       / \ 
                  3     4      2     4     2   3
                 /       \    /       \   /     \
                4         3  4         3 3       2



*/


int sp[]={1,2,3,4};


int st[100] = {0};
int best[100]= {0};
int sum1 = 0;

int cmp(int nn,int t)
{
	int i;
	/*和之前出现的值作比较*/
	for(i=0;i<t;i++)
	{
		if(nn == st[i])
		{
			return 1;
		}
	}
	return 0;
}

void travel(int len,int t)
{
	int i;
	if(t >= len)
	{
		st[t]=st[0];
		for(i=0;i<len+1;i++)
		{
			printf("%d ",st[i]);
		}
		printf("\n");
		return;
	}else{
		/*分别从不同的驻地出发*/
		for(i=0;i<len;i++)
		{
			/*需要加入到路径的值，是之前没有加入过的，这里使用cmp函数来去除相同路径的情况*/
			if(!cmp(sp[i],t))
			{
				st[t] = sp[i];
				travel(len,t+1);
			}
		}

	}
}


int main()
{
	int i, len = sizeof(sp)/sizeof(int);
	printf("%d\n", len);

	travel(len,0);
#if 0
	for(i=0;i<len;i++)
	{
		printf("%d ",best[i] );
	}
	printf("\n");
#endif
}