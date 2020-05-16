#include<stdio.h>

/*鸡笼问题*/

int main()
{
	int i,j,k,a,b,c;
	for(i=0;i<=20;i++)
	{
		for(k=1;k<=100;k++)
		{
			for(j=100-i-k;j<100;j++)
			{
				if(j%3==0)
				{
					if(i+j+k==100)
					{
						if(5*i+3*k+j/3==100)
							printf("%d %d %d\n",i,k,j);
					}
				}
			}
		}
	}
	return 0;
}
