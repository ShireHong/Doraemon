#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20


/*二叉树的层遍历，包括二叉树的数据增加，二叉树的层遍历借助了队列。*/
/*利用队列先进先出的原则，所有节点会被以父节点，左子节点和右子节点的顺序依次存储起来，然后依次打印出来
但是此程序没有区分所打印节点在哪一层，这是需要改进的地方*/


typedef struct _tr_node{
	int data;
	struct _tr_node *lchild;
	struct _tr_node *rchild;
}tr_node;


typedef struct _queue{
	tr_node* data[MAX_SIZE];
	int head;
	int rear;
}queue_t;


void insert_node(tr_node **root , int data)//双层指针，因为首次传入的root节点为空
{
	if(*root == NULL)
	{
		tr_node * pnode = (tr_node*)malloc(sizeof(tr_node));
		pnode->data = data;
		pnode->lchild = NULL;
		pnode->rchild = NULL;
		(*root) = pnode;
		return;
	}
	if(data < (*root)->data )
	{
		insert_node(&(*root)->lchild, data);
	}
	if(data > (*root)->data )
	{
		insert_node(&(*root)->rchild, data);
	}	
	
}


void print_tree(tr_node *root)//中 左 右
{
	if(root)
	{
		printf("%d\n", root->data);
		print_tree(root->lchild);
		print_tree(root->rchild);

	}
}

void en_queue(queue_t * q, tr_node* node)
{
	if((q->head+ MAX_SIZE - 1)%MAX_SIZE == q->rear)
	{
		printf("queue is full \n");
		return ;
	}
	q->data[q->rear] = node;
	q->rear = (q->rear+1)%MAX_SIZE;
}

tr_node* de_queue(queue_t* q)
{
	//tr_node*tmp = (tr_node*)malloc(sizeof(tr_node));
	if(q->head == q->rear)
	{
		printf("queue is empty \n");
		return NULL;
	}
	tr_node* tmp = q->data[q->head];
	q->head = (q->head+1)%MAX_SIZE;
	return tmp;
}


void level_order_traversal(tr_node *root)
{
	queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
	queue->rear = queue->head = 0;

	en_queue(queue, root);
	tr_node *node;
	int count = 1;
	while(queue->head != queue->rear)
	{
		node = de_queue(queue);
		printf("%d:%d\n", count, node->data);
		if(node->lchild)
		{
			en_queue(queue,node->lchild);			
		}
		if(node->rchild)
		{
			en_queue(queue,node->rchild);			
		}
		count++;
	}

} 

int main()
{
	tr_node *root = NULL;	

	insert_node(&root,7);
	insert_node(&root,4);
	insert_node(&root,9);
	insert_node(&root,3);
	insert_node(&root,8);
	insert_node(&root,5);

	level_order_traversal(root);

	printf("-----------------\n");
	print_tree(root);
}