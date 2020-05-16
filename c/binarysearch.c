#include<stdio.h>

/*二分查找*/

int binarysearch(int v[],int len,int num)
{
	int low=0;
	int high=len-1;
	while(1)
	{
		if(num==v[(low+high)/2])
		{
			return (low+high)/2;
		}
		else if(num<v[(low+high)/2])
		{
			high=(low+high)/2-1;			
		}
		else
		{
			low=(low+high)/2+1;
		}
	}
	
}

int main()
{
	int i,b;
	printf("%d\n",(2+7)/2);
	int v[8]={2,4,5,8,12,14,15,19};
	for(i=0;i<8;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
	fflush(stdout);
	scanf("%d",&b);
	
	int a=binarysearch(v,8,b);
	printf("%d\n",a);
}

