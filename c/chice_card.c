#include<stdio.h>

int straight(int n,int low,int front,int sum)
{
	int i;
	if(n==0)
		return sum;
	
	if(i==front+1)
	{		
			
		   straight(n-1,low+1,i,sum*4);
	}
		
	
}


int main()
{
	int sum=1;
	straight(5,0,0,sum);
	printf("%d\n",sum);
}
