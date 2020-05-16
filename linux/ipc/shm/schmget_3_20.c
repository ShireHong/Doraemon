#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char array[40000];

int main()
{
	int shmid;
	char *ptr,*shmptr;
	
	printf("array from %x to %x\n",array,&array[39999]);
	printf("stack around %x\n",&shmid);
	ptr=(char*)malloc(100000);
	printf("malloc from %x to %x\n",ptr,ptr+99999);
	shmid=shmget(IPC_PRIVATE,100000,SHM_R|SHM_W);
	shmptr=shmat(shmid,0,0);
	
	printf("shared memory from %x to %x\n",shmptr,shmptr+99999);
	shmctl(shmid,IPC_RMID,0);
	exit(0);
}
