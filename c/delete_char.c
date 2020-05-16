#include<stdio.h>

/*去掉字符串中指定字符，将字符串的ASCii中的256个字符进行标记，利用双指针的处理，将需要替换的字符用后一个指针代替*/

void delete_char(char *psrc,char *del)
{
	if(psrc==NULL || del==NULL)
		return;
	int hashtable[256]={0};
	while(*del!=0)
	{
		hashtable[*del]=1;
		del++;
	}
	char *pslow=psrc;
	char *pfast=psrc;
	while(*pfast!=0)
	{
		if(hashtable[*pfast]!=1)
		{
			*pslow=*pfast;
			pslow++;
			//pfast++;
		}
		pfast++;
	}
	*pslow=0;
}

int main()
{
	char str1[]="they are students";
	char str2[]="te";
	delete_char(str1,str2);
	puts(str1);	
}





