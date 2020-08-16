#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/ip_icmp.h>
#include<unistd.h>
#include<signal.h>
#include<arpa/inet.h>
#include<errno.h>
#include<sys/time.h>
#include<string.h>
#include<netdb.h>
#include<pthread.h>


#define PACKET_SEND_MAX_NUM 64

typedef  unsigned short  uint16;
typedef  unsigned char   uint8;
typedef  unsigned int    uint32;

typedef struct _ping_packet_sta
{
	struct timeval start;
	struct timeval end;
	int flag;
	int seq;
}ping_packet_sta;


ping_packet_sta myping_sta[PACKET_SEND_MAX_NUM];

int alive;
int rawsock;
int send_count;
int recv_count;
pid_t pid;
struct sockaddr_in dest;
struct timeval start_time;
struct timeval end_time;
struct timeval time_interval;

//反码16进制求和

//这个不能求错，不然发送错误，select会一直位0
uint16 cal_checksum(uint16* addr,int len)
{
	uint16* p = addr;
	int temp_len = len;
	int sum = 0;
	while(temp_len >1 )
	{
		sum += *p++;
		temp_len -= 2;
	}
	if(temp_len == 1)
	{
		sum +=*(uint8*)p;
	}
	sum = (sum>>16)+(sum & 0xffff);
	sum += (sum >> 16);
	
		
	return ~sum;
	
}


void icmp_pack(struct icmp* icmphdr, int seq, int len)
{
	int i = 0;
	
	icmphdr->icmp_type = ICMP_ECHO;
	icmphdr->icmp_code = 0;
	icmphdr->icmp_cksum = 0;
	icmphdr->icmp_seq = seq;
	icmphdr->icmp_id = pid & 0xffff;
	/*为什么要填充？*/
    for(i=0;i<len;i++)
	{	
		icmphdr->icmp_data[i] = i;
	}
	icmphdr->icmp_cksum = cal_checksum((uint16*)icmphdr,len);
}


struct timeval cal_time_offset(struct timeval begin,  struct timeval end)
{
	struct timeval ans;
	ans.tv_sec = end.tv_sec - begin.tv_sec;
    ans.tv_usec = end.tv_usec - begin.tv_usec;

	if(ans.tv_usec < 0)
	{
		ans.tv_sec--;
		ans.tv_usec += 1000000;
	}
	return ans;
}

int icmp_unpack(uint8 *buf, int len)
{
	int iphdr_len;
	struct timeval start_time,recv_time,offset_time;
	int rrt;/*往返时延*/

	struct ip *ip_hdr = (struct ip*)buf;
	iphdr_len = ip_hdr->ip_hl * 4;
	struct icmp *icmp_hdr = (struct icmp*)(buf+iphdr_len); 
 	len -= iphdr_len;
	if(len < 8)
	{
		printf("error 1\n");
		return -1;
	}
	if(icmp_hdr->icmp_type == ICMP_ECHOREPLY && (icmp_hdr->icmp_id == pid & 0xfffff))
	{
		if(icmp_hdr->icmp_seq < 0 || icmp_hdr->icmp_seq > PACKET_SEND_MAX_NUM)
		{
			printf("error 2\n");
			return -1;
		}
		myping_sta[icmp_hdr->icmp_seq].flag = 0;
		start_time = myping_sta[icmp_hdr->icmp_seq].start;
		gettimeofday(&recv_time,NULL);

		offset_time = cal_time_offset(start_time,recv_time);
		rrt = offset_time.tv_sec*1000 + offset_time.tv_usec/1000;
		
		printf("%d byte from %s: icmp_seq=%u ttl=%d rtt=%d ms\n",
            len, inet_ntoa(ip_hdr->ip_src), icmp_hdr->icmp_seq, ip_hdr->ip_ttl, rrt);
		
	}
	else
	{
		printf("error 3\n");
		return -1;
	}
	return 0;
}

void ping_send()
{
	uint8  send_buf[128];
	memset(send_buf,0,sizeof(send_buf));
	gettimeofday(&start_time,NULL);
	while(alive)
	{
		int size = 0;
		gettimeofday(&(myping_sta[send_count].start),NULL);
		myping_sta[send_count].flag = 1;
		
		icmp_pack((struct icmp*)send_buf, send_count, 64);
		size = sendto(rawsock,send_buf,64,0,(struct sockaddr*)&dest,sizeof(dest));
		send_count++;
		if(size < 0)
		{
			printf("error 4\n");
			continue;
		}
		sleep(1);
		//printf("send count %d\n",send_count);
	}
}

void ping_recv()
{
	struct timeval tv;
    	tv.tv_usec = 200;
	tv.tv_sec  = 0;

	fd_set read_fd;
    	uint8 recv_buf[512];
	memset(recv_buf, 0, sizeof(recv_buf));
	
	while(alive)
	{
		int ret = 0;
		FD_ZERO(&read_fd);
		FD_SET(rawsock,&read_fd);
		ret = select(rawsock + 1,&read_fd,NULL,NULL,&tv);
		switch(ret)
		{
			case -1:
				printf("select err 5\n");
				break;
			case 0:
				//printf("select timeout \n");
				break;
			default:
				{
					int size = recv(rawsock,recv_buf,sizeof(recv_buf),0);
					if(size < 0)
					{
						printf("recv err 6\n");
						continue;
					}
					ret = icmp_unpack(recv_buf,size);
					if(ret == -1)
					{
						printf("unpack error\n");
						continue;
					}
					recv_count++;
				}
				break;
			printf("recv count %d\n",recv_count);
		}
	}
	
}

void icmp_sigint(int signo)
{
	alive = 0;
	gettimeofday(&end_time,NULL);
	time_interval = cal_time_offset(start_time, end_time);
}

void ping_state_show()
{
	long time = time_interval.tv_sec*1000+time_interval.tv_usec/1000;
     /*注意除数不能为零，这里send_count有可能为零，所以运行时提示错误*/
     printf("%d packets transmitted, %d recieved, %d%c packet loss, time %ldms\n",
         send_count, recv_count, (send_count-recv_count)*100/send_count, '%', time);
}

int main(int argc,char* argv[])
{
	int size = 60*1024;
	struct protoent* protocol = NULL;
	uint8 dest_addr[80];
	memset(dest_addr,0,80);
	
	uint32 inaddr = 1;
	struct hostent *host = NULL;

	pthread_t send_id,recv_id;

	if(argc < 2)
	{
		printf("argc err 7\n");
		return -1;
	}	
	
	protocol = getprotobyname("icmp");
	if(protocol == NULL)
     	{
        	 printf("Fail to getprotobyname!\n");
         	return -1;
	}	
	memcpy(dest_addr,argv[1],strlen(argv[1])+1);

	rawsock = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
	printf("rawsock %d\n",rawsock);
	pid = getpid();

	setsockopt(rawsock,SOL_SOCKET,SO_RCVBUF,&size,sizeof(size));

	bzero(&dest,sizeof(dest));

	dest.sin_family = AF_INET;

	inaddr = inet_addr(argv[1]);

	if(inaddr == INADDR_NONE)
	{
		host = gethostbyname(argv[1]);
		if(host == NULL)
		{
			printf("gethostbyname err 8\n");
			return -1;
		}
		memcpy((char*)&dest.sin_addr,host->h_addr,host->h_length);
	}
	else{
		memcpy((char*)&dest.sin_addr,&inaddr,sizeof(inaddr));
	}
	
	inaddr = dest.sin_addr.s_addr;
	printf("PING %s, (%d.%d.%d.%d) 56(84) bytes of data.\n",dest_addr,
         (inaddr&0x000000ff), (inaddr&0x0000ff00)>>8, 
         (inaddr&0x00ff0000)>>16, (inaddr&0xff000000)>>24); 

     alive = 1;  //控制ping的发送和接收
 
     signal(SIGINT, icmp_sigint);
 
     if(pthread_create(&send_id, NULL, (void*)ping_send, NULL))
     {
         printf("Fail to create ping send thread!\n");
         return -1;
     }
 
     if(pthread_create(&recv_id, NULL, (void*)ping_recv, NULL))
     {
         printf("Fail to create ping recv thread!\n");
         return -1;
     }
 
     pthread_join(send_id, NULL);//等待send ping线程结束后进程再结束
     pthread_join(recv_id, NULL);

	ping_state_show();
 
    close(rawsock);
    return 0;
}












