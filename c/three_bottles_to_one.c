#include<stdio.h>


/*
*计算总的酒瓶数量，空瓶子继续换
*
*
*
*/

int main()
{
	int start_num,num_changes;
	scanf("%d %d",&start_num,&num_changes);
	int sum = start_num;
	while(start_num >= num_changes)
	{
		sum += start_num/num_changes;
		start_num = start_num%num_changes + start_num/num_changes;
	}
	printf("%d\n", sum);
}