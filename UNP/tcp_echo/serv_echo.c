#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#include<signal.h>
#include"comm_api.h"
#include<sys/wait.h>




#define SA struct sockaddr 




static void str_echo(int fd)
{
	int n;
	char line[1024];
	for(;;)
	{
		if((n = read_line(fd,line,1024)) == 0 )
			return;
		writen(fd,line,n);
		
	}
}


void sig_handle(int signo)
{
	pid_t pid;
	int stat;
	
	pid = wait(&stat);
	printf("child %d over\n",pid);
	return;
}



int main(int argc,char *argv[])
{
	int listenfd,connectfd;
	struct sockaddr_in serv_addr,cli_addr;
	int cli_len;
	pid_t childpid;

	if((listenfd = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("socket error\n");
		return -1;
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(listenfd,(SA*)&serv_addr,sizeof(serv_addr));

	listen(listenfd,1024);
	
	signal(SIGCHLD,sig_handle);
	
	for(;;)
	{
		cli_len = sizeof(cli_addr);
		connectfd = accept(listenfd,(SA*)&cli_addr,&cli_len);
		if((childpid = fork()) == 0)
		{
			close(listenfd);
			str_echo(connectfd);
			exit(0);
		}
		close(connectfd);
	}	
	
	return 0;
}







