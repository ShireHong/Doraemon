#include<stdio.h>

/*
	fx=x*x+2x+1;
*/

float f_x(float  x)
{
	return x*x+2*x+1;
}

float integral(float (*fun)(float) ,float min,float max,float step)
{
	float i;
	float res=0;
	for(i=min;i<=max;)
	{
			res+=fun(i)*step;
			i+=step;
	}
	return res;
}

int main()
{
	float result=integral(f_x,0,1,0.0001);
	printf("%f\n",result);

	
	return 0;
}



