#include<stdio.h>
#include<unistd.h>
#include<errno.h>




ssize_t new_read(int fd,char *ptr)
{
	static int 		read_cnt = 0;
	static char 	read_buf[1024];
	static char* 	read_ptr = NULL;

	if(read_cnt <= 0)
	{
again:
		if((read_cnt=read(fd,read_buf,1024))<0)
		{
			if(errno == EINTR)
				goto again;
			return -1;
		}
		else if(read_cnt == 0)
			return 0;
		read_ptr = read_buf;
	}
	*ptr = *read_ptr++;
	read_cnt --;
	return 1;
}

ssize_t writen(int fd,void *buf,size_t n)
{
	int nwrite;
	char *ptr = buf;
	int nleft = n;
	while(nleft > 0)
	{
		if((nwrite = write(fd,ptr,nleft)) <= 0)
		{
			if(errno == EINTR)
				nwrite = 0;
			else
                return -1;
		}
		nleft -= nwrite;
		ptr += nwrite;
	}
	return n;
}

ssize_t read_line(int fd,void* buf,size_t maxline)
{
	int rc,i;
	char c,*ptr = NULL;

	ptr = buf;	

	for(i=1;i<maxline;i++)
	{
		if((rc=new_read(fd,&c)) == 1)
		{
			*ptr++ = c;
			if(c == '\n')
				break;
				
		}
		else if(rc == 0)
		{
			if(i == 1)
				return 0;
			else
                break;
		}
		else
          return -1;
	}
	*ptr = 0;
	return i;
}





