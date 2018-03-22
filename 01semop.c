#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int id = semget(0x8888,1,IPC_CREAT|0644);
	if(id<0) {perror("semget");return -1;}
	semctl(id,0,SETVAL,5);
	int i;
	for(i=0;i<10;i++)
	{
		if(fork()==0)
		{
			struct sembuf sp;
			sp.sem_num = 0;
			sp.sem_op  = -5;
			sp.sem_flg = SEM_UNDO;
			while(semop(id,&sp,1)==-1)
			{}
			srand(getpid());
			printf("%d进程开始工作\n",getpid());
			sleep(rand()%5+5);
				
			printf("%d进程停止工作\n",getpid());
			sp.sem_op = +1;
			semop(id,&sp,1);
		        exit(0);		
		}
	}
	while(wait(NULL)!=-1);
	printf("over!\n");
	semctl(id,0,IPC_RMID,NULL);
}
			
