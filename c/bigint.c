#include<stdio.h>
#include<stdlib.h>

/*计算阶乘，并且可以存储大于64位的数值，主要利用进位的思想*/

int carry[200]={0};
int num[200]={1};

void putinvector(int n)
{
	int res,i;
	for(i=0;i<198;i++)
	{
		res=num[i]*n;
		num[i]=res%100;
		carry[i+1]=res/100;
	}
}

void calc(void)
{
	int i,res;
	for(i=0;i<198;i++)
	{
		res=num[i]+carry[i];
		num[i]=res%100;
		carry[i+1]=carry[i+1]+res/100;
	}
}

void f_calc(int n)
{
	int i;
	for(i=n;i>0;i--)
	{
		putinvector(i);
		calc();		
	}	

}
void printnum(void)
{
	int i=199,j;
	while(num[i]==0)
	{
		i--;
	}
	printf("拥有个数：%d\n",i);
	for(j=i;j>=0;j--)
	{
		printf("%d",num[j]);
	}
	printf("\n");
	
}
int main()
{
	
	int a;
	scanf("%d",&a);
	f_calc(a);
	printnum();
}















