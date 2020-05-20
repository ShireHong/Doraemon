#include<stdio.h>
#include<stdlib.h>

//两个注意


/*1，循环队列有一个特性，就是最后一个位置是空出来的，因为这是用来判断对了是否满的，
为(q->rear + 1)%q->max_size == q->front，如果要用满，则变成(q->rear )%q->max_size == q->front，
那么就会出大问题，你一插入队列，队列就满了*/

/*2，轮询队列的时候，要提取出值，不然会改变队列信息*/

#define QUEUE_SIZE 6

typedef struct QUEUE
{
	int* data;
	int front;
	int rear;
	int max_size;
}queue;


queue* creat_queue(void)
{
	queue * q = (queue*)malloc(sizeof(queue));
	
	q->front = q->rear = 0;
	q->max_size = QUEUE_SIZE;
	q->data = (int*)malloc(QUEUE_SIZE *sizeof(int));
	printf("%d\n", q->max_size);
	return q;
}

void en_queue(queue *q,int data)
{
	//printf("%d\n", data);
	//基本操作，判断队列有没有满
	if((q->rear + 1)%q->max_size == q->front)
	{
		printf("queue is full\n");
		return;
	}
	q->data[q->rear] = data;
	q->rear = (q->rear+1)%q->max_size;
}

int de_queue(queue* q)
{
	int out;
	//基本操作，判断queue有没有空
	if(q->front == q->rear)
	{
		printf("queue is empty\n");
		return 0;
	}
	out = q->data[q->front];
	q->front = (q->front+1)%q->max_size;
	return out;

}

void foreach_queue(queue* q)
{
	int d = 0;
	int i = q->front;
	//printf("%d %d\n",q->front,q->rear);
	while(i != q->rear)
	{
		d=q->data[i];
		i = (i+1)%q->max_size;
		printf("%d ", d);
	}
	printf("\n");
}

int main()
{
	queue *my_queue = creat_queue();
	printf("%d %d %d\n",my_queue->max_size,my_queue->front,my_queue->rear);
	en_queue(my_queue,2);
	en_queue(my_queue,3);
	en_queue(my_queue,5);
	en_queue(my_queue,6);
	en_queue(my_queue,7);
	en_queue(my_queue,14);
	en_queue(my_queue,34);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	en_queue(my_queue,22);
	foreach_queue(my_queue);

	en_queue(my_queue,55);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	de_queue(my_queue);
	foreach_queue(my_queue);

	return 0;
}






