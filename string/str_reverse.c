#include<stdio.h>
#include<string.h>


char s[] = "hello,world";

void reverse(char* str,int n)
{
	char* p = str;
	char* q = str+n;
	unsigned char c ;
	while(1)
	{

		if(p>=q )
			break;
		
		c = *p;
		*p = *q;
		*q = c;
		p++;
		q--;
	}
}

int main()
{
	int n = strlen(s) - 1;
	//*(s+2) = 'y';
	printf("%s %d\n", s,n);
	reverse(s,n);
	printf("%s\n", s);
	return 0;
}