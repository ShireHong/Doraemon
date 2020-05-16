#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>


int main()
{
	int i;
	int msgid[5];
	for(i=0;i<5;i++)
	{
		msgid[i]=msgget((key_t)1234,0666|IPC_PRIVATE|IPC_CREAT);
		printf("%d\n",msgid[i]);
	}
	printf("---------------------------------------------------\n");
	system("ipcs");
	for(i=0;i<5;i++)
	{
		msgctl(msgid[i],IPC_RMID,0);
	}

	printf("---------------------------------------------------\n");
	system("ipcs");
}
