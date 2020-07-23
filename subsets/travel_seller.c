#include<stdio.h>
#include<stdlib.h>
#include<string.h>





int sp[]={1,2,3,4};


int st[100] = {0};
int best[100]= {0};
int sum1 = 0;

int cmp(int nn,int t)
{
	int i;
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
		for(i=0;i<len;i++)
		{
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