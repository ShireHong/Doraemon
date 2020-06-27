#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*带有 K 个不同字符的最长子字符串*/

/*
找到需要移动左边界的条件，当不同字符的个数大于K的时候
*/

/*滑动窗口题目，是针对连续的数组进行操作，选定一个子数组通过这个子数组的移动来定位答案，这个移动窗口可以通过左右的边界来调整*/

#define max(x,y)  ((x)>(y)?(x):(y))

#define K 3

/*这个代码是一个例子，判定小字母的，所以选择一个数组来存放26个字母*/
int alph[26] = {0};

char *sample = "aabaccddfffh";


int main()
{
	int len = strlen(sample);
	int left = 0,right = 0;
	int count = 0;
	int tmp,maxlen = 0;
	/*这是一个不定长字符数目的问题，所以右边界作为突破口，先调整右边界*/
	while(right < len)
	{
		tmp = *(sample+right) - 'a';
		if(alph[tmp] == 0)
		{
			count++;
		}
		alph[tmp]++;
		right++;
		/*
		*当右边界移动位置已经满足条件时，开始移动窗口来寻求最大值，
		*注意，这个时候窗口的大小已经基本形成，只要右边加入一个新的字符
		*左边就减少一个字符，而且是循环的减少，因为字符有重叠。
		*然后比较子字符串大小，选择大的留下来
		*/
		while(count > K)
		{			
			tmp = *(sample+left) - 'a';			
			alph[tmp]--;
			if(alph[tmp] == 0)
				count--;/*根据循环条件，去掉左边一个字符*/			
			left++;
		}
		/*留下大的字符串*/
		maxlen = max(maxlen,right - left);
	}
	printf("%d\n",maxlen);
	return 0;
}