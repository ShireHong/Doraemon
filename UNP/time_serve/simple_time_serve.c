#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>


#define SA struct socketaddr 

int main(int argc,char *argv[])
{
	int sockfd,connectfd;
	char buf[1000];
	struct sockaddr_in serv_addr;


	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("socket error\n");
		return -1;
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(1113);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sockfd,(SA*)&serv_addr,sizeof(serv_addr));

	listen(sockfd,1024);
	
	time_t ticks;
	
	while(1)
	{
		connectfd = accept(sockfd,(SA*)NULL,NULL);
		ticks = time(NULL);
		snprintf(buf,sizeof(buf),"%.24s\r\n",ctime(&ticks));
		write(connectfd,buf,strlen(buf));
		close(connectfd);
	}	
	
	return 0;
}







