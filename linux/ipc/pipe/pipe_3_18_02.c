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

	if(argc!=2)
		perror("a.out <pathname>");
	if((fin=fopen(argv[1],"r"))==NULL)
		perror("argv[1] can't open");

	fout=popen("more ","w");
	while(fgets(line,4096,fin)!=NULL)
	{
		fputs(line,fout);
	}
	if(ferror(fin))
		perror("fgets error");
	pclose(fout);
	

}

















