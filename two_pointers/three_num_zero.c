#include<stdio.h>
#include<stdlib.h>

/*求和为0的三元组*/

/*
*例如
*input = [ - 4，-3,-2,-1,0，1，2]
*output = [-3，1，2] [-2,0,2] [-1,0,1]
*注意：不能含相同的三元组（如果找出所有的，这个问题会非常复杂）
*/

/*
*此题的输入数组不一定是有序数组，需要将数组先排序，本题省略排序
*这个问题需要找到一个突破点，因为是双指针问题，所以确定了三个数中的两个数
*还有一个数，就是通过遍历来获取，作为突破口
*/



int sample[] = {-6,-3,-2,-1,0,1,2,2,4};

int main()
{
	int store[7]={0};
	int start = 0,end,len = sizeof(sample)/sizeof(int);	
	int i=end,j;

	for(i=0;i<len;i++)
	{
		start = i;
		end = len-1;
		while(start < end)
		{
			/*过滤掉相同的数值，不可重复计算*/
			if(i == start)
				start++;
			if(i == end)
				end--;
			/*=0时，就是找到了一组三元数，我没有存储，直接打印出来，因为不含相同的数组，所以要变化左右指针，保证数组不一样*/
			if((sample[i]+sample[start]+sample[end]) == 0)
			{				
				printf("%d %d %d\n", sample[i],sample[start],sample[end]);
				#if 0
				/*无法考虑相同的数组，会无法退出循环*/
				while(start < end && sample[start] == sample[start+1])
				{					
				 	start++;
				}				
				while(start < end && sample[end] == sample[end-1])
				{
					end--;	

				}
				#endif
				start++;
				end--;		
				
			}
			/*当三数之和大于0时，说明右值偏大，需要缩小*/
			else if((sample[i]+sample[start]+sample[end]) > 0)
			{
				end--;
			}
			/*当三数之和小于0时，说明左值偏小，需要增加*/
			else 
			{
				start++;
			}
			
		}
	}
	return 0;
}