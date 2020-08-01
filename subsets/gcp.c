#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
图的着色问题

和旅行商的问题有点相似



*/


int color[]={1,2,3,4};
int piont[5]={0};

int sum1 = 0;

/*1表示有通道，0表示没有*/
int map[5][5]={
	{1,1,1,1,0},
	{1,1,1,1,1},
	{1,1,1,1,0},
	{1,1,1,1,1},
	{0,1,0,1,1}
};

int cmp(int cur,int t)
{
	int i;
	/*和之前出现的值作比较*/
	for(i=0;i<t;i++)
	{
		/*这个地方判断不符合要立即退出，否则会多出不符合的值*/
		if(map[t][i])
		{
			if(piont[i] == cur)
				return 1;
		}
	}
	return 0;
}

void gcp(int len,int kind,int t)
{
	int i;
	if(t >= len)
	{
		sum1++;
		for(i=0;i<len;i++)
		{
			printf("%d ",piont[i]);
		}
		printf("\n");
		return;
	}else{
		/*分别从不同的驻地出发*/
		for(i=0;i<kind;i++)
		{
			/*需要加入到路径的值，是之前没有加入过的，这里使用cmp函数来去除相同路径的情况*/
			if(!cmp(color[i],t))
			{
				piont[t] = color[i];
				gcp(len,kind,t+1);
			}
		}

	}
}


int main()
{
	int len = sizeof(piont)/sizeof(int);
	int kind = sizeof(color)/sizeof(int);
	printf("%d %d\n", len,kind);

	gcp(len,kind,0);

	printf("sum = %d\n",sum1);

}