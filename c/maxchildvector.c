#include<stdio.h>

/*找出矩阵最大值*/

int maxSum1(int *A, int n)
{
    int max = -1;
    int i, j, sum;
    
    for(i = 0; i < n; i++)
    {
          sum = A[i];
          for(j = i+1; j < n; j++)
          {
                sum += A[j];
                if(sum > max )
                       max = sum;
          }
    }
    
    return max;
}

int main()
{
	int a[6]={-1,4,-1,6,2,-3};
	int m=maxSum1(a,6);
	printf("%d\n",m);
}
