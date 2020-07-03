#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*比较包含回退（backspace）的字符串*/


/*
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
*/

/*
字符串碰到#号就把前面的字符去掉
利用双指针，一个指针负责遍历输入字符串，一个指针负责储存数组的位置
*/

char *s1="aab#c";
char *s2="a#ab#c";

char * convert_string(char *s,int len)
{
	int p = 0;
	int q = 0;
	char *t = (char*)malloc(len);
	while(q < len)
	{
		/*碰到普通字符就存储*/
		if(*(s1+q)!='#')
		{
			t[p] = *(s1+q);
			p++;
		/*#字符就减去前面的字符，直到为0*/
		}else{
			if(p>0)			
				p--;							
			t[p] = 0;
		}
		q++;
	}
	p++;
	t[p]=0;
	return t;
}

int main()
{
	char *t1 = convert_string(s1,strlen(s1));
	char *t2 = convert_string(s2,strlen(s2));
	printf("%s  %s\n",t1,t2);
	if(strcmp(t1,t2)==0)
		printf("ture");
	else
		printf("false");
	return 0;
}