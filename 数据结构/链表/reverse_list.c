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


/*前插列表，节点插在当前节点的前面*/
void front_insert_node(listnode_t **node, int data)
{
	listnode_t *head = *node;
	listnode_t *pnode = (listnode_t*)malloc(sizeof(listnode_t));
	pnode->data = data;
	pnode->next = NULL;

	/*数据往前插，插完之后把头移到当前的数据，有头有尾的链表这个就非常简单，但是考虑到单链表就多做一些操作*/
	if(head == NULL)
	{
		head = pnode;
		*node = pnode;
		return;
	}
	pnode->next = head;
	*node = pnode;

}

/*原理很简单，把正向的数据进行前插就可以*/

listnode_t * reverse_list(listnode_t *node)
{
	listnode_t* new_list = NULL;//一定要指向空指针，不然会有意想不到的问题
	listnode_t* head = node;

	while(head)
	{
		front_insert_node(&new_list, head->data);
		head = head->next;
	}
	return new_list;
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

	for(i=1;i < 11;i++)
	{		
		insert_node(&head,i);
	}

	listnode_t* new = reverse_list(head);
	print_list(new);

}