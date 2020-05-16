#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define I 'I'
#define V 'V'
#define X 'X'
#define L 'L'
#define C 'C'
#define D 'D'
#define M 'M'

int c2i(char c)
{
	switch(c)
	{
		case I:
			return 1;
		case V:
			return 5;
		case X:
			return 10;
		case L:
			return 50;
		case C:
			return 100;
		case D:
			return 500;
		case M:
			return 1000;
	}
}
int   num[]  ={1000,900,500,400, 100, 90, 50,  40, 10,  9,   5,  4,   1};
char* roma[] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int main()
{
	char *p=(char*)malloc(100);
	memset(p,0,100);
	//char *q=p;
	//scanf("%s",p);
	//printf("%s\n",p);
	int input;
	scanf("%d",&input);
	int i=0;
	while(input!=0)
	{
		if((input/num[i])>0)
		{
			strcat(p,roma[i]);
			input-=num[i];
		}else{	
			i++;
		}
	}
	
	printf("%s\n",p);
	return 0;
}
