#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
输入: S = "3z4"
输出: ["3z4", "3Z4"]
输入: S = "12345"
输出: ["12345"]

		 -------------      
	   /              \
	  a                A
	 / \              / \
	1   1            1   1
   /     \          /     \
  b       B        b       B
 /         \      /         \
2           2    2           2
a1b2       a1B2 A1b2         A1B2
*/




//char *ss = "z35d";
char *ss = "abcd";

char st[100]={0};

int islowletter(char c)
{
	if(c >= 'a' && c <= 'z')
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isupperletter(char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isletter(char c)
{
	if(islowletter(c)||isupperletter(c))
	{
		return 1;
	}else{
		return 0;
	}
}

char lowtoupper(char c)
{
	return (c - 'a' +'A');
}

void find_subsets(int len,int t)
{
	int i = t;
	if(i>len)
	{
		for(i=0;i<len;i++)
		{
			printf("%c",st[i]);
		}
		printf("\n");
		return;
	}

	//i++;
	while(i<len && !isletter(*(ss+i)))
	{
		st[i] = *(ss+i);
		i++;
	}
	/*去掉这个判断，值会显示两遍*/	
	if(i<len)
	{

		//printf("hh = %d %c",i,st[i]);
		st[i] = *(ss+i);

		find_subsets(len, i+1);

		//printf("zz = %d %c",i,st[i]);
		st[i] =  lowtoupper(*(ss+i));

		find_subsets(len, i+1);
	
	}
	else
	 find_subsets(len, i+1);
	
}

int main()
{
	int i,j;
	int len = strlen(ss);
	printf("%d\n",len );
	find_subsets(len,0);
}