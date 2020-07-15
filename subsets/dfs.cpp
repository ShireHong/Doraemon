
#include<stdio.h>

#include<string.h>

#include<assert.h>

 

int arr[]={0};//存储当前第i个位置元素包含还是不包含

void Ziji(char brr[],int k,int length)//k是递归的层次，k与集合的长度有关

{

	assert(arr!=NULL); 

	if(k==length)//递归结束的条件

	{

		printf("{ ");

	    for(int i=0;i<length;i++)

	    {

	    	if(arr[i]==1)

	    	{

	    		printf("%c ",brr[i]);

	    	}

	    }

	    printf("}");

		printf("\n"); 

	}

	else

	{

		arr[k]=0;//集合中的第i个元素没有包含，也就是(No)

	    Ziji(brr,k+1,length); //进行没有被包含(No)的递归

	    arr[k]=1;//集合中的第i个元素被包含(Yes)

	    Ziji(brr,k+1,length);//然后进行被包含下(Yes)的递归

	} 

}

int main()

{

	char str[]="ACC";

	int lenth=strlen(str);

	Ziji(str,0,lenth);

	return 0;

}

