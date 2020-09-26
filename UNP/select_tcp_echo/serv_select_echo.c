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
#include<sys/select.h>





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
	int listenfd,connectfd,client[FD_SETSIZE],sockfd;
	struct sockaddr_in serv_addr,cli_addr;
	int cli_len;
	
	pid_t childpid;
	
	int maxfd,maxi,i;

	fd_set rdset,allset;

	int n;
	char recv_line[1024];

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
	
	//signal(SIGCHLD,sig_handle);
	
	maxfd = listenfd;
	maxi = -1;

	FD_ZERO(&allset);
	FD_SET(listenfd,&allset);

	for(i=0;i<FD_SETSIZE;i++)
	{
		client[i] = -1;
	}
	int nready;	

	for(;;)
	{
		rdset = allset;
		nready = select(maxfd+1,&rdset,NULL,NULL,NULL);
		if(FD_ISSET(listenfd,&rdset))
		{
			cli_len = sizeof(cli_addr);
			connectfd = accept(listenfd,(SA*)&cli_addr,&cli_len);
			
			for(i=0;i<FD_SETSIZE;i++)
			{
				if(client[i] < 0)
				{
					client[i] = connectfd;
					break;
				}
			}
			
			if(i == FD_SETSIZE)
			{
				printf("error:client is full!\n");
				return -1;
			}
			FD_SET(connectfd,&allset);
			if(connectfd > maxfd)
				maxfd = connectfd+1;
			if(i > maxi)
				maxi = i;
			if(--nready <= 0) //nready 为1,或比1小，1是刚才读出来，说明后续没有值了
				continue;
		}
		for(i=0;i<=maxi;i++)
		{
			if((sockfd = client[i]) < 0)
				continue;			
				
			if(FD_ISSET(sockfd,&rdset))
			{
				if( (n = read_line(sockfd,recv_line,1024)) == 0 )
				{
					close(sockfd);
					FD_CLR(sockfd,&allset);
					client[i] = -1;
				}
				else
				{
					writen(sockfd,recv_line,n);
				}
			}
			
			if(--nready <= 0)
				break;
			
		}
	}	
	
	return 0;
}







