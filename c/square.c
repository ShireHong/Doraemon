#include<stdio.h>

/*求出一个数+100 和+268 都是一个数的平方。范围是0-100000*/

int issquare(int num)
{
	int i=10;
	int res;
	while(i<num)
	{
		res=i*i;
		if(res==num) return 0;
		i++;
	}
	return 1;
}


int main()
{
	int i;
	for(i=0;i<100000;i++)
	{
		if(!issquare(i+100)&&!issquare(i+268))
		{
			printf("%d\n",i);
			//break;
		}		
	}
}



