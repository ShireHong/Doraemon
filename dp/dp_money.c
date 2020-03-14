#include "stdio.h"


int coin[100]={0};

int cnt = 100;

void count_star(int i)
{
	if(i>=5)
		coin[i] = 1+coin[i-5];
	else if(i>=2)
		coin[i] = 1+coin[i-2];
	else if(i>=1)
		coin[i] = 1;
}

int main()
{

	int i = cnt;
	for(i=1;i<=cnt;i++)
	{
		count_star(i);
	}
	for(i = 1;i<=cnt;i++)
	{
		printf("coin[%d] = %d\n",i,coin[i]);	
	}
	return 0;
}