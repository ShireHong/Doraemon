#include<stdio.h>
#include<stdlib.h>



void merge_vec(int source[],int temp[],int start,int mid,int end)
{
	int i = start;
	int j = mid+1;
	int k = start;
	while(i <= mid && j <= end)
	{
		if(source[i]<source[j]) 
			temp[k++] =source[i++];
		else
		    temp[k++] =source[j++];
	}
	while(i <= mid)
		temp[k++] = source[i++];
	while(j <= end)
		temp[k++] = source[j++];
}


void merge_sort(int source[],int temp[],int start,int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		merge_sort(source,temp,start,mid);
		merge_sort(source,temp,mid+1,end);
		merge_vec(source,temp,start,mid,end);
	}
}