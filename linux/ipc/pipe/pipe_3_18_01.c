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
	FILE  *fp;

	if(argc!=2)
		perror("a.out <pathname>");
	if((fp=fopen(argv[1],"r"))==NULL)
		perror("argv[1] can't open");

	pipe(fd);
	if((pid=fork())<0)
		perror("fork");
	else if(pid>0)
	{
		close(fd[0]);
		while(fgets(line,4096,fp)!=NULL)
		{
			n=strlen(line);
			write(fd[1],line,n);
		}
		if(ferror(fp))
			perror("fgets error");
		close(fd[1]);
		waitpid(pid,NULL,0);
		exit(0);
	}
	else
	{
		close(fd[1]);
		if(fd[0]!=STDIN_FILENO)
		{
			if(dup2(fd[0],STDIN_FILENO)!=STDIN_FILENO)
				perror("dup2");
			close(fd[0]);
		}
		char *pager,*argv0;
		if((pager=getenv("PAGER"))==NULL)
			pager="/bin/more";
		if((argv0=strrchr(pager,'/')) !=NULL)
			argv0++;
		execl(pager,argv0,(char*)0);
	}

}

















