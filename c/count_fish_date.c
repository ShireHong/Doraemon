#include<stdio.h>


/*从2010年1月1日开始，三天打鱼两天晒网，计算某一天的状态*/

/*思路就是计算总天数，然后取余，需要区别闰年和月份的不同*/


int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int i,sum=0;
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	if(day > 31 || month > 12 ) 
		return -1;

	for(i=2010;i<year;i++)
	{
		if(i%400 == 0 || (year%4==0 && year%100!=0))
		{
			sum += 366;
		}
		else{
			sum += 365;
		}
	}

	for(i=1;i<month;i++)
	{
		if(i == 2 && (year%400 == 0 || (year%4==0 && year%100!=0)))
		{
			sum+=1;
		}
		sum +=mon[i];
	}
	sum += day;

	if(sum%5 == 0|| sum%5 == 4) 
		printf("net\n");
	else if(sum%5 == 1|| sum%5 == 2 || sum%5 == 3)
		printf("fish\n");
	return 0;
}