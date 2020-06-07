#include<stdio.h>
#include<stdlib.h>

/*
与查找中间节点一样，借助一个中间的step
*/

typedef struct _node
{
	int data;
	struct _node *next;
}listnode_t;


/*插入节点，很简单，考虑第一个节点是空节点，所以使用双重指针*/

void insert_node(listnode_t ** node, int data)
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

void print_list(listnode_t* node)
{
	listnode_t *head = node;
	if(head == NULL)
		return ;
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

/*解法简单*/
listnode_t * find_mid_node_list(listnode_t *node, int k)
{
	listnode_t *head1 = node;
	listnode_t *head2 = node;

	int step = 0;

	while(head1)
	{		
		if(step >= k)
		{
			head2 = head2->next;
		}
		head1 = head1->next;
		step++;
	}
	return head2;
	
}


int main()
{
	int i;
	listnode_t * head = NULL;
	
	for(i=1;i<=11;i++)
	{
		insert_node(&head, i);
	}
	print_list(head);

	listnode_t *new = find_mid_node_list(head,4);
	printf("%d\n", new->data);

	
}