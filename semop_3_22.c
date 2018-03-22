#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>


static int update(long *ptr)
{   
 //   printf("%d\n",(*ptr)+1);
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

	union semum{
		int stval;
		struct semid_ds *buf;
		unsigned short *array;
	};
	union semum args;
	unsigned short array[2]={0,0};
	args.array=array;

	int semid=semget(0x8888,2,IPC_CREAT|0644);
	semctl(semid,1,SETALL,args);
	
	struct sembuf parent_wkup[1]={0,1,SEM_UNDO};
	struct sembuf parent_wait[1]={0,-1,SEM_UNDO};
	struct sembuf child_wkup[1]={1,1,SEM_UNDO};
	struct sembuf child_wait[1]={1,-1,SEM_UNDO};

	if((pid=fork())<0)
         perror("fork");
    else if(pid>0)
    {
       for(i=0;i<100;i+=2)
       {     
					
            if((counter=update((long*)area))!=i)
                 printf("parent:expected %d ,got %d\n",i,counter);
			semop(semid,child_wkup,1);         
            semop(semid,parent_wait,1);
        }
     }else{
         for(i=1;i<101;i+=2)
         {
             semop(semid,child_wait,1);
             if((counter=update((long*)area))!=i)
                 printf("child:expected %d ,got %d\n",i,counter);
             semop(semid,parent_wkup,1);
         }
         exit(0);      
     }
}			
