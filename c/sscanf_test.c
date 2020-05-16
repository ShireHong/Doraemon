#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int hexnum;
	//if(argc !=2 )
	//	exit(0);
	char *p="45";
    sscanf(p,"%d",&hexnum);
	printf("%x\n",hexnum);
}
