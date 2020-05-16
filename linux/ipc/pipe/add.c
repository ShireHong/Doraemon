#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int  n,int1,int2;
	char line[4096];
	while((n=read(STDIN_FILENO,line,4096))>0)
	{
		line[n]=0;
		if(sscanf(line,"%d%d",&int1,&int2))
		{
			sprintf(line,"%d\n",int1+int2);
			n=strlen(line);
			write(STDOUT_FILENO,line,n);
		}
	}
	exit(0);
}

