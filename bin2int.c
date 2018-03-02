#include<stdio.h>
#include<string.h>


int main()
{
	char bin[32]={0};
	int i,num=0;
	while(1)
	{
		scanf("%s",bin);
		char*p=bin;
		if(strcmp(bin,"0")==0) break;
		int n=strlen(p);
		for(i=n-1;i>=0;i--)
		{
			if(*(p+i)=='1')
				num+=1<<n-1-i;
		}
		printf("%d\n",num);
		num=0;
	}
	return 0;
}