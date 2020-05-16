#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int  c;
	while((c=getchar())!=EOF)
	{
			c=tolower(c);
			putchar(c);
			if(c='\n')
				fflush(stdout);
	}
	exit(0);
}

