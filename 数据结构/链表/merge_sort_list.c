#include<stdio.h>
#include<stdlib.h>

/*
合并两个有序单链表，新的链表仍然是一个有序单链表，这个解法，网上有些解法有错误，我尝试了种新的解法
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

/*这个解法理解非常简单，*/

listnode_t * merge_sort_list(listnode_t *node1, listnode_t *node2)
{
	listnode_t *head1 = node1;
	listnode_t *head2 = node2;

	listnode_t *new = NULL;

	while(head1 && head2)
	{		
		/*将小的节点插入到新的链表中，因为是有序的，所以直接插入*/
		if(head1->data < head2->data)
		{
			insert_node(&new,head1->data);
			head1 = head1->next;
		}
		/*这个地方需要判断上一次的head1有没有到链表的尾巴节点，如果是尾巴节点，说明可以循环*/
		if(head1)
		{
			if(head1->data > head2->data)
			{
				insert_node(&new,head2->data);
				head2 = head2->next;
			}	
		}		
	}
	/*如果有一个链表已经插入结束，就把剩下的单链表的所有节点插入到新链表中*/
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