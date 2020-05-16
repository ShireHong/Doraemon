#include<stdio.h>

/*从4个数中提取3个数作为一组数据，求出多少组数据和分别的组合*/

int main()
{
	int v[4]={1,2,3,4};
	int tmp[3]={0};
	int i,j,k,num=0;
	for(i=0;i<4;i++)
	{
		tmp[0]=v[i];
		for(j=0;j<4;j++)
		{
			if(v[j]!=v[i])
			{				
			   tmp[1]=v[j];
			   for(k=0;k<4;k++)
			   {
			   		if(v[k]!=v[j]&&v[k]!=v[i])
					{	
						num++;
						tmp[2]=v[k];	
						printf(" %d : %d %d %d\n",num,tmp[0],tmp[1],tmp[2]);
					}
			   } 
			}
			  
		}
	}
}
