#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*计算从根节点出发，到达叶节点的路径之和*/


#define MAX_SIZE 20

/*找一个大的数组来存放路径上的值*/
int st[MAX_SIZE] = {0};
int num = 0;


typedef struct _tr_node{
	int data;
	struct _tr_node *lchild;
	struct _tr_node *rchild;
}tr_node;



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



void trace_sum(tr_node *root,int i)
{
	/*将路径上的值存数组*/
    st[i++] = root->data;
	if(!root->lchild && !root->rchild )
	{
		/*到达末节点时，计算所有值的和*/
		int j,sum = 0 ;
		num++;
		for(j=0;j<i;j++)
		{
			sum += st[j];
		}
		printf("%d sum=%d ",num,sum );
		for(j=i-1;j>=0;j--)
		{
			printf("%d->",st[j]);
		}
		printf("\n");		
		return;
	}
	/*递归计算*/
	if(root->lchild )
	{
		trace_sum(root->lchild,i);
	}
	if(root->rchild)
	{
		trace_sum(root->rchild,i);
	}
	
}


int main()
{
	tr_node *root = NULL;	

	insert_node(&root,10);
	insert_node(&root,4);
	insert_node(&root,9);
	insert_node(&root,3);
	insert_node(&root,8);
	insert_node(&root,5);
	insert_node(&root,17);
	insert_node(&root,15);
	insert_node(&root,12);
	insert_node(&root,13);
	insert_node(&root,20);
	//level_order_traversal(root);

	printf("-----------------\n");
	print_tree(root);

	printf("-----------------\n");
	int i = 0;
	trace_sum(root,i);
}