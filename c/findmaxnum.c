#include<stdio.h>
#include<stdlib.h>

typedef enum {
	err,
	ture
}bl;


bl findmax(int*a,int r,int c,int num)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		if(num<*(a+i*c))
			break;
		else if(num==*(a+i*c))
			return ture;
	}
	for(j=0;j<c;j++)
	{
		if(num==a[c*(i-1)+j])
			return ture;
	}	
	return err;
}

int main()
{
	int i,r,c,num;
	int a[100]={0};
	while(scanf("%d %d %d",&r,&c,&num)!=EOF)
	{	
		//int num;
		//scanf("%d",&num);
		for(i=0;i<r*c;i++)
			scanf("%d",&a[i]);
		bl x =findmax(a,r,c,num);
		if(x==ture)
			printf("yes\n");
		if(x==err)
			printf("no\n");
		a[100]=0;
	}
}
