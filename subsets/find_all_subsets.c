#include<stdio.h>
#include<stdlib.h>


/*给定一个带重复项的集合，找出所有子集*/
/*
注意事项
子集中的每个元素都是非降序的
两个子集间的顺序是无关紧要的
解集中不能包含重复子集
样例 
如果 S = [1,2,2]，一个可能的答案为：
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*这道题我没做出来，c语言感觉有点吃力，递归也没有好办法，后面想到再来填坑*/




int sp[]={1,1,2,2};

int st[100]={0};


void find_subsets(int len,int s,int n)
{
	int i;
	if(n==0)
		return ;
	for(i=s;i<len;i++)
	{
		if(i>s && sp[i] == sp[i-1])
		{
			continue;
		}
		printf("%d ", sp[i]);

	}
	find_subsets(len,s++,n--);
}

int main()
{
	int i,j;
	int count=0;
	int len = sizeof(sp)/sizeof(int);
	for(i=0;i<len-1;i++)
	{
		st[sp[i]]++;
		printf("%d ",sp[i]);
		for(j = i+1;j<len;j++)
		{
			if(j>i+1 && sp[j] == sp[j-1] )
			{
				//printf("hh ");
				continue;
			}
			//printf("j:%d=%d ",j,sp[j]);
			printf("%d ",sp[j]);
			count++;
			if(count == 2)
			{
				printf("zz ");
				count = 0;
				break;
			}
		}
		printf("\n");
	}
}