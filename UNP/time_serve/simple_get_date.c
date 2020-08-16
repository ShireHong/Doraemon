#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SA struct socketaddr 

int main(int argc,char *argv[])
{
	int sockfd,n;
	char recvline[1000];
	struct sockaddr_in serv_addr;

	if(argc < 2)
	{
		printf("error,must have a ip!\n");
		return -1;
	}

	printf("%s\n",argv[1]);

	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("socket error\n");
		return -1;
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(1113);
	
	if(inet_pton(AF_INET,argv[1],&serv_addr.sin_addr)<0)
	{
		printf("inet_pton error\n");
		return -1;
	}

	if(connect(sockfd,(SA*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("connect error\n");
		return -1;
	}
	while((n=read(sockfd,recvline,1000))>0)
	{
		recvline[n] = 0;
		if(fputs(recvline,stdout)==EOF)
		{
			printf("fputs error\n");
		}
	}	
	
	return 0;
}







