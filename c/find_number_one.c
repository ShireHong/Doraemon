#include<stdio.h>

/*寻找两个区间中整数中包含1的个数*/

int find_one(int a)
{
	int count=0;
	while(a)
	{
		if((a-1)%10==0)
			count++;
		a/=10;
	}
	return count;
}

int main()
{
	int i,min,max,sum=0;
	int vec[100000]={0};
	while(scanf("%d %d",&min,&max)!=EOF)
	{
		for(i=0;i<=max-min;i++)
			vec[i]=min+i;
		for(i=0;i<=max-min;i++)
			sum+=find_one(vec[i]);
		printf("%d\n",sum);
		sum=0;
	}
	return 0;
}
