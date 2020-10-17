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


static void str_echo(int fd,SA *paddr,socklen_t clilen)
{
	int n;
	socklen_t len;
	char line[1024];
	for(;;)
	{
		len = clilen;
		n = recvfrom(fd,line,1024,0,paddr,&len);
		sendto(fd,line,n,0,paddr,len);
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
	int sockfd,connectfd;
	struct sockaddr_in serv_addr,cli_addr;
	int cli_len;
	pid_t childpid;

	if((sockfd = socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		printf("socket error\n");
		return -1;
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sockfd,(SA*)&serv_addr,sizeof(serv_addr));
	
	str_echo(sockfd,(SA*)&cli_addr,sizeof(cli_addr));
	
	return 0;
}







