#include<stdio.h>


/*冒泡算法*/

void choice(int v[],int len)
{
	int i,j,tmp;
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(v[j]<v[j-1])
			{
				tmp=v[j];
				v[j]=v[i];
				v[i]=tmp;
			}
		}
	}
}

void bubble(int v[],int len)
{
	int i,j,tmp;
	for(i=0;i<len;i++)
	{
		for(j=1;j<len-i;j++)
		{
			if(v[j]<v[j-1])
			{
				tmp=v[j];
				v[j]=v[j-1];
				v[j-1]=tmp;
			}
		}
	}
}


int main()
{
	int i,v[5]={7,4,8,5,10};
	bubble(v,5);
	for(i=0;i<5;i++)
		printf("%d ",v[i]);
	printf("\n");
	return 0;
}
