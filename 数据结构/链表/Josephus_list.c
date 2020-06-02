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
约瑟夫环的数数，这里从0开始数，数到那个数，是把那个数替换为下一个数
*/
listnode_t * josephus_count(listnode_t * node, int count)
{
	listnode_t *head = node;
	listnode_t *cur = NULL;
	int tmp = 0;
	while(head->next != head)
	{
		tmp++;
		if(tmp == count)
		{
			/*
			使用一个临时指针指向下一个节点，方便free，然后把下一个指针替换到当前的节点
			*/
			cur = head->next;
			head->data = head->next->data;
			head ->next= head->next->next;
			tmp = 0;
			free(cur);
			cur = NULL;
		}
		/*
		这个地方需要注意，下一次开始数数是在下一个节点的位置，所以在替换完数字之后，直接就在当前节点开始数数，不然
		的话结果就会有问题
		*/
		else
			head = head->next;
	}
	return head;
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

	for(i=1;i < 10;i++)
	{		
		inset_node(&head,i);
	}

	//print_list(head);

	listnode_t * tail = find_node(head,9);
	tail->next = head;

	//print_list(head);
	listnode_t *res = josephus_count(head,3);
	//print_list(head);
	printf("%d\n", res->data);

}