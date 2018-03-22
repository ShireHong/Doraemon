#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>
#include"sync_lock.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
static int update(long *ptr)
{
	printf("%d\n",(*ptr)+1);
	return((*ptr)++);
}

int main()
{
	int fd,i,counter;
	pid_t pid;
	caddr_t area;
	fd=open("/dev/zero",O_RDWR);
	area=mmap(0,sizeof(long),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);
	TELL_WAIT();
	if((pid=fork())<0)
		perror("fork");
	else if(pid>0)
	{
		for(i=0;i<100;i+=2)
		{
			if((counter=update((long*)area))!=i)
				printf("parent:expected %d ,got %d\n",i,counter);
			TELL_CHILD(pid);
			WAIT_CHILD();
		}
	}else{
		for(i=1;i<101;i+=2)
		{
			WAIT_PARENT();
			if((counter=update((long*)area))!=i)
				printf("child:expected %d ,got %d\n",i,counter);
			TELL_PARENT(getppid());
		}
		//exit(0);		
	}	
	exit(0);
}







