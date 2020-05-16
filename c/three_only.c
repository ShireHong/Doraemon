#include<stdio.h>


int findbit1(int xor)
{
	int index=0;
	while((xor & 0x1)==0 && index<=31)
	{
		xor>>=1;
		index++;
	}
	return index;
}

int main()
{
	int vec[11]={1,2,1,3,3,5,5,7,7,4,6};
	int i,xor=1,a=0,b=0,c=0,tmp=0;
	for(i=0;i<11;i++)
		xor^=vec[i];
	
	int res=findbit1(xor);
	printf("%d\n",xor);
	for(i=0;i<11;i++)
	{
		if((vec[i]>>res)&(1))
			a^=vec[i];
		else
		
        	tmp^=vec[i];
	
	}
	printf("a=%d,b=%d\n",a,b);
	xor^=a;
	res=findbit1(xor);
	
	printf("%d\n",xor);
	if((a>>res)&1)
		b^=a;
	else
		c^=a;
	for(i=0;i<11;i++)
	{
		
		if((vec[i]>>res)&(1))
		  b^=vec[i];
		else
          c^=vec[i];
	}
	
	printf("%d %d %d\n",a,b,c);

    return 0;
}
