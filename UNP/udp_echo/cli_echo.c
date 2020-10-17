#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include"comm_api.h"

//#define SA struct sockaddr 


static void str_cli(FILE *fp,int fd,SA* s_addr,socklen_t addr_len)
{
	int n;
	char recv_line[1024],send_line[1024];
	while(fgets(send_line,1024,fp)!= NULL)
	{
		sendto(fd,send_line,strlen(send_line),0,s_addr,addr_len);
		n = recvfrom(fd,recv_line,1024,0,NULL,NULL);
		recv_line[n] = 0;
		fputs(recv_line,stdout);
	}
}




int main(int argc,char *argv[])
{
	int sockfd,n;
	
	struct sockaddr_in serv_addr;

	if(argc < 2)
	{
		printf("error,must have a ip!\n");
		return -1;
	}

	printf("%s\n",argv[1]);

	if((sockfd = socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		printf("socket error\n");
		return -1;
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(SERV_PORT);
	
	if(inet_pton(AF_INET,argv[1],&serv_addr.sin_addr)<0)
	{
		printf("inet_pton error\n");
		return -1;
	}


	str_cli(stdin,sockfd,(SA*)&serv_addr,sizeof(serv_addr));
	exit(0);
	
	return 0;
}







