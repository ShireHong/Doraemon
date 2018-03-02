#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int checknum(int *vv,int c,int num)
{
	int sum=0,j;
	for(j=0;j<c;j++)
	{
		if(num==vv[j]) sum++;
	}
	return sum;
}

int main(void)
{
   int count,i,m; 
   while(1)
   {
	   scanf("%d\n",&count);
	   if(count==0) break;
	   int *vec = (int*)malloc(count*sizeof(int));
	   for(i=0;i<count;i++)
	   scanf("%d",&vec[i]);
       fflush(stdin);
       scanf("%d",&m);
	   fflush(stdin);
	   int *vn = (int*)malloc(count*sizeof(int));
	   for(i=0;i<m;i++)
	   scanf("%d",&vn[i]);
       fflush(stdin);
	   
	   for(i=0;i<m;i++)
	   {
		   printf("%d ",checknum(vec,count,vn[i]));
	   }
	   printf("\n");
	   free(vn);
	   vn=NULL;
	   free(vec);
	   vec=NULL;
	   
   }
   return 0;
}