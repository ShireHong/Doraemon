#include<stdio.h>

//#define MIN(a,b,c) ((a)<(b)?(a):((b)<(c))?(b):(c))

/*找丑数，*/

int MIN(int a,int b,int c)  
{  
    int min =(a<b)?a:b;  
    min = (min<c)?min:c;  
    return min;  
}

int storage[1500];


int main()
{
	int i=1,p1=0,p2=0,p3=0,tmp;
	storage[0]=1;

	while(i<1500)
	{
		//++i;
		tmp=MIN(storage[p1]*2,storage[p2]*3,storage[p3]*5);
		storage[i]=tmp;
		printf("%d : %d\n",i,tmp);
		while(storage[p1]*2<=storage[i])
			++p1;
		while(storage[p2]*3<=storage[i])
			++p2;
		while(storage[p3]*5<=storage[i])
			++p3;
	
		++i;
	}
	printf("%d\n",storage[1499]);
	
	//printf("%d\n",MIN(1*2,3*2,1*3));
}




