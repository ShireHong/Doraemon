#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};


struct list{
	struct node *phead;
	//struct node*current;	
};

void initlist(struct list *list)
{
	list=(struct list*)malloc(sizeof(struct list));
	list->phead=NULL;
}

void addlist(int num,struct list * list)
{
	/*这个地方犯了个超级低级错误，这个地方千万不要用局部变量,stupid me，调了那么久，算法一       直都没有问题啊！
    */
	struct node *tmp=(struct node*)malloc(sizeof (struct node));
	tmp->data=num;
	tmp->next=NULL;
	struct node*p=list->phead;
	
	if(list->phead==NULL)
	{
		list->phead=tmp;
	}		
	else
	{
		while(p->next!=NULL)
		{			
			p=p->next;
		}		
	    p->next=tmp;
		
   }
}

void reverselist(struct list *list)
{
	struct node *p=list->phead;
	struct node *q,*r=NULL;

	while(p!=NULL)
	{
	    q=p->next;
		p->next=r;
		r=p;
		p=q;
		/*
		以下是错误的方法，q不能省略，p=p->next,p->next的值在p->next=r时已经改变。
		*/
	    //q=p->next;
		//p->next=r;
		//r=p;
		//p=p=p->next;
				
	}
	list->phead=r;
}


void showlist(struct list *list)
{
	struct node *p=list->phead;
	if(p==NULL)
		printf("Empyt list!\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;		
		}		
		printf("\n");
	}
}


void insertlist(struct list *list,int frontnum,int num)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=num;
	n->next=NULL;
	struct node*p=list->phead;
	while(p->data!=frontnum)
	{
		p=p->next;
	}
	//struct node *q=p->next;
	//p->next=n;
	n->next=p->next;
	p->next=n;
}

struct list mylist;

int main()
{
	initlist(&mylist);
	addlist(3,&mylist);
	addlist(7,&mylist);
	addlist(6,&mylist);	
	addlist(1,&mylist);
	addlist(9,&mylist);
	addlist(8,&mylist);
	addlist(2,&mylist);
	addlist(5,&mylist);
	insertlist(&mylist,9,20);
    showlist(&mylist);
	reverselist(&mylist);
    showlist(&mylist);

}




