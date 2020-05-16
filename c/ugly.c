#include<stdio.h>



int main()
{
	long num=859963392;
	while(num!=1)
	{
		if(num%2==0)
			num/=2;
		else if(num%3==0)
			num/=3;
		else if(num%5==0)
			num/=5;
		else /*if((num%2!=0) && (num%3!=0) && (num%5!=0))*/
		{	
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
}


