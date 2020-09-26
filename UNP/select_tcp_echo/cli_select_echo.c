#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include"comm_api.h"
#include"sys/select.h"


#define SA struct sockaddr 


static void str_cli1(FILE *fp,int fd)
{
	char recv_line[1024],send_line[1024];
	while(fgets(send_line,1024,fp)!= NULL)
	{
		writen(fd,send_line,strlen(send_line));
		read_line(fd,recv_line,1024);
		fputs(recv_line,stdout);
	}
}


void
str_cli(FILE *fp, int sockfd)
{
	int			maxfdp1;
	fd_set		rset;
	char		sendline[1024], recvline[1024];

	FD_ZERO(&rset);
	for ( ; ; ) {
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfdp1 = MAX(fileno(fp), sockfd) + 1;
		select(maxfdp1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd, &rset)) {	/* socket is readable */
			if (read_line(sockfd, recvline, 1024) == 0)
				printf("str_cli: server terminated prematurely");
			fputs(recvline, stdout);
		}

		if (FD_ISSET(fileno(fp), &rset)) {  /* input is readable */
			if (fgets(sendline, 1024, fp) == NULL)
				return;		/* all done */
			writen(sockfd, sendline, strlen(sendline));
		}
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

	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
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

	if(connect(sockfd,(SA*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("connect error\n");
		return -1;
	}
	
	str_cli(stdin,sockfd);
	exit(0);
	
	return 0;
}







