#include<stdio.h>
#include<stdlib.h>

/*
这道题解法很随意，我还是比较喜欢，对每一次的next进行判断，所以增加了一个step作为判断，
step也可以设置成多倍的效果
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


listnode_t * find_mid_node_list(listnode_t *node)
{
	listnode_t *head1 = node;
	listnode_t *head2 = node;

	int step = 0;

	while(head1)
	{
		head1 = head1->next;
		step++;
		if(step == 2)//设置成2就是中间节点
		{
			head2 = head2->next;
			step = 0;
		}
		
	}
	return head2;
	
}

/*网上的一般解法*/
listnode_t * find_mid_node_list1(listnode_t *node)
{
	listnode_t *head1 = node;
	listnode_t *head2 = node;

	int step = 0;

	while(head1)
	{
		head1 = head1->next;
		if(head1 == NULL)
		{
			break;
		}
		head1 = head1->next;
		head2 = head2->next;
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

	listnode_t *new = find_mid_node_list1(head);
	printf("%d\n", new->data);

	new = find_mid_node_list(head);
	printf("%d\n", new->data);

}