#include<sys/wait.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<error.h>




int main(int argc,char *argv[])
{
	int n,fd[2];
	pid_t pid;
	char line[4096];
	FILE  *fin,*fout;
	
	fin=popen("./myuclc","r");
	
	for(;;)
	{
		fputs("promt>",stdout);
		fgets(line,4096,fin);
		fputs(line,stdout);
		
	}
	pclose(fin);
	putchar('\n');

}

















