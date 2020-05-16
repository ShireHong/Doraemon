#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[4][10][10]={{" ","I","II","III","IV","V","VI","VII","VIII","IX"}, //分别是0~9，10~90，100~900，1000~3000
						 {" ","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
						 {" ","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
						 {" ","M","MM","MMM"}},ch[20][10];
	int n,t,i=0,j,k=0;
	cin>>n;
	while (n)
	{
		t = n%10;
		strcpy(ch[k],str[k][t]);
		k++;
		n /= 10;
	}
	for (i=k-1; i>=0; i--)
	{
		cout<<ch[i];
	}
	return 0;
}
