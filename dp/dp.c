#include<stdio.h>

int piles[]={3,9,1,2,7,8};


typedef struct {
	int fir;
	int sec;
}DP_t;

int main()
{
	DP_t dp[6][6]={0};
	int i,j,k;
	int length = sizeof(piles)/sizeof(int);
	for(i = 0;i < length;i++)
	{
		dp[i][i].fir = piles[i];
		dp[i][i].sec = 0;
	}
	
	for(i = 0; i < length; i++)
	{
		for(j = i+1;j<length;j++)
		{
			int left  = piles[i]+dp[i+1][j].sec ;
			int right = piles[j]+dp[i][j-1].sec ;
			
			if(left > right)
			{				
				dp[i][j].fir = left;
				dp[i][j].sec = dp[i+1][j].fir;
			}else{				
				dp[i][j].fir = right;
				dp[i][j].sec = dp[i][j-1].fir;
			}
			printf("dp[%d][%d]:fir %d ,sec %d\n",i,j,dp[i][j].fir,dp[i][j].sec);
		}
		
	}
	return 0;
}