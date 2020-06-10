#include<stdio.h>
#include<stdlib.h>

/*
求链表里面的环的长度，利用快慢指针，必定相遇，先找到第一次相遇的节点，然后一个站住不动，另外一个继续跑
再次相遇所走过的节点数就是环的长度
*/

typedef struct _node
{
	int data;
	struct _node *next;
}listnode_t;


/*插入节点，很简单，考虑第一个节点是空节点，所以使用双重指针*/

void inset_node(listnode_t ** node, int data)
{
	listnode_t *pnode = (listnode_t*)malloc(sizeof(listnode_t));
	pnode->data = data;
	pnode->next = NULL;
	if(*node == NULL)
	{
		*node = pnode;
		return;
	}
	listnode_t *head = *node;
	while(head->next)
	{
		head = head->next;
	}
	head->next = pnode;
}

/*
在单链表中找到一个指定节点，也很简单
*/
listnode_t *find_node(listnode_t * node, int num)
{
	listnode_t *head = node;
	
	while(head)
	{
		if(head->data == num)
			return head;
		head = head->next;
	}
	return head;
}

/*

*/
int circle_length_list(listnode_t * node)
{
	/*这个地方，快指针先走一步，不然while那里就直接不进去了*/
	listnode_t *fast = node->next;
	listnode_t *slow = node;
	int count = 1;
	int step = 1;
	while(fast != slow)
	{
		fast = fast->next;
		step++;
		if(step == 2)
		{
			slow = slow->next;
			step = 0;
		}

	}	
	/*同理，指针往前一步*/
	fast = fast->next;
	while(fast != slow)
	{
		fast = fast->next;
		count++;
	}
	return count;
}

/*
打印所有节点，debug，很简单
*/
void print_list(listnode_t* node)
{
	listnode_t *head = node;
	if(head == NULL)
		return ;
	while(head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main()
{
	int i;
	listnode_t * head = NULL;

	for(i=1;i <= 11;i++)
	{		
		inset_node(&head,i);
	}

	//print_list(head);

	listnode_t* mouse = find_node(head,7);
	listnode_t* tail = find_node(head,11);
	tail->next = mouse;

	//print_list(head);

	int count = circle_length_list(head);

	printf("%d\n", count);

}