#include<stdio.h>
#include<stdlib.h>

/*
单链表实现约瑟夫环，要实现一个单循环链表，实现方式很多，最重要的是把最后一个节点指向首节点就ok
这样在判断是否有最后结果的时候就有下一个节点是否等于自己
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

listnode_t * merge_sort_list(listnode_t *node1, listnode_t *node2)
{
	listnode_t *head1 = node1;
	listnode_t *head2 = node2;

	listnode_t *new = NULL;

	while(head1 && head2)
	{		
		if(head1->data < head2->data)
		{
			insert_node(&new,head1->data);
			head1 = head1->next;
		}
		if(head1)
		{
			if(head1->data > head2->data)
			{
				insert_node(&new,head2->data);
				head2 = head2->next;
			}	
		}		
	}
	while(head1)
	{
		insert_node(&new,head1->data);
		head1 = head1->next;
	}
	while(head2)
	{
		insert_node(&new,head2->data);
		head2 = head2->next;
	}	
	return new;
}

int main()
{
	int i;
	listnode_t * head1 = NULL;
	listnode_t * head2 = NULL;
	
	insert_node(&head1,2);
	insert_node(&head1,6);
	insert_node(&head1,7);
	insert_node(&head1,9);
	insert_node(&head1,12);
	print_list(head1);

	insert_node(&head2,1);
	insert_node(&head2,3);
	insert_node(&head2,5);
	insert_node(&head2,8);
	print_list(head2);


	listnode_t *new = merge_sort_list(head1,head2);
	print_list(new);

}