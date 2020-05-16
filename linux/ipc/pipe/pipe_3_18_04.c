#include<sys/wait.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<error.h>
#include<signal.h>



int main(int argc,char *argv[])
{
	int n,fd1[2],fd2[2];
	pid_t pid;
	char line[4096];
	FILE  *fin,*fout;
	
	signal()
	for(;;)
	{
		fputs("promt>",stdout);
		fgets(line,4096,fin);
		fputs(line,stdout);
		
	}
	pclose(fin);
	putchar('\n');

}

















