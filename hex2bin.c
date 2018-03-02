#include<stdio.h>
#include<string.h>


int main()
{
	int a,i,j;
	char c;
	scanf("%d",&a);
	for(i=3;i>=0;i--)
	{
		c=*((char*)(&a)+i);
		for(j=7;j>=0;j--)
		{
			if(c>>j&0x01)
		    {
			  printf("1");
	        }else{
		      printf("0");
	        }
		}
		printf(" ");
		
	}
	printf("\n");

	return 0;
}