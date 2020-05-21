#include<stdio.h>

/*快速排序，运用递归的思想，把数组第一个数x作为一个需要移到正确
位置的数，只要在这个数的左边出现的比x大的数统统换到到右边去，右边出现比
x小的数换到左边去，这样这个数最后出现的位置就是正确的位置，然后通过分治法
处理左边的数组和右边的数组*/

/*在这里千万不要遗漏15-16行的判断，不然会出不来，这是递归的停止条件*/

void q_sort(int vec[],int start,int end)
{
	int i 	= start;
	int j 	= end;
	int tmp = vec[i];
	if(i >= j)
        return;
	while(i<j)
	{
		while(vec[j] >= tmp && i<j)
		{
			j--;
		}		
		vec[i] = vec[j];
		while(vec[i]<=tmp&&i<j)
		{
			i++;
		}
		
		vec[j]=vec[i];
	}
	vec[i] = tmp;
	q_sort(vec , start,i-1);
	q_sort(vec , i+1,end);
}

int main()
{
	int i;
	int vv[]={4,5,2,7,3};
	for(i = 0;i<5;i++)
	 {
	 	printf("%d ",vv[i]);
	 }
	 printf("\n");
	 q_sort(vv,0,4);
	 for(i = 0;i<5;i++)
	 {
	 	printf("%d ",vv[i]);
	 }
	 printf("\n");
}