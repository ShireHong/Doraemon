#include<stdio.h>

/*
	本题在编码的奥秘中加法器得到启发，两个数相加非进位部分用异或处理，进位部分用与处理，进位要坐移一位，若进位不为0,继续叠加。
*/


void add(int a,int b)
{
	int c=a^b;
	int d=(a&b)<<1;
	if(d!=0)
	   add(c,d);
	else
		printf("%d\n",c|d);
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	add(a,b);
	return 0;

}
