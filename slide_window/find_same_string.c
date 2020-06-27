#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*寻找字符相同但排序不一样的字符串*/
/*
这类问题其实就是套用相同的模式，两个while循环
找到移动窗口左边界的条件，当窗口大小大于比较字符串的大小的时候
*/


/*滑动窗口题目，是针对连续的数组进行操作，选定一个子数组通过这个子数组的移动来定位答案，这个移动窗口可以通过左右的边界来调整*/


/*这个代码是一个例子，判定小字母的，所以选择一个数组来存放26个字母*/
int alph[26] = {0};

char *sample = "abaeb";

char *str = "ab";

int main()
{
	int len = strlen(sample);
	int len1 = strlen(str);
	int i;

	int left = 0,right = 0;
	int count = 0;
	int tmp;

	for(i=0;i<len1;i++)
	{
		tmp = *(str+i)-'a';
		alph[tmp]++;
	}
	/*这是一个不定长字符数目的问题，所以右边界作为突破口，先调整右边界*/
	while(right < len)
	{
		tmp = *(sample+right) - 'a';
		//printf("%c ", tmp + 'a');
		if(alph[tmp] >= 1)//代表有值
		{
			count++;
		}
		alph[tmp]--;//这个地方不要漏掉减值，这是判断与要求字符串中比较是否存在的关键
		right++;
		/*
		*当右边界移动位置已经满足条件时，开始移动左边窗口寻找，
		*注意，这个时候窗口的大小已经基本形成，只要右边加入一个新的字符
		*左边就减少一个字符，
		*/
		
		while(right-left > len1)
		{			
			tmp = *(sample+left) - 'a';
			//printf("%c ", tmp + 'a');
			if(alph[tmp] >= 0)//如果为-1就不是要找的值
			{
				
				count--;/*根据循环条件，去掉左边一个字符*/
			}
			alph[tmp]++;//这个地方需要注意不要漏掉值的累加，否则count值会少计算，若出现值为-1的话，count值不变，就会出错
			left++;
		}
		/*留下大的字符串*/
		//printf("%d %d  %d\n", count,left,alph[tmp]);
		
		if(count == len1)
			printf("%d ", left);
	}
	printf("\n");
	return 0;
}