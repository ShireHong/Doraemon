#include<stdio.h>

int main()
{
	int i;
	double sum=0;
	for(i=0;i<3;i++)
	{
		if(i%2)
		   sum+=(double)(-1)*1/(2*i+1);
		else
			sum+=(double)1/(2*i+1);
	}
	printf("%lf\n",4*sum);
	return 0;
}
