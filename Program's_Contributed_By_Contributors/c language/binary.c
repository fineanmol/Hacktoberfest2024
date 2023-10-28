#include <stdio.h>
int main()
{
	int i,n,result,size;
	int arr[10]={1,5,6,62,65,95,122,150,500,667};
	scanf("%d",&n);
	size=sizeof(arr)/sizeof(arr[0]);
	result=search(arr,n,size-1);
	printf("%d",result);
}
int search(int a[],int x,int high){
	int low=0;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(a[mid]==x)
		return mid;
		
		if(a[mid]<x)
		low=mid+1;
		
		else
		high=mid-1;
	}
	return -1;
	}

