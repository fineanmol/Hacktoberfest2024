#include<stdio.h>
int binary_search(int[],int,int,int);
int main()
{
	int arr[20],i,n,low=0,high,pos;
	printf("Enter the length of an array\n");
	scanf("%d",&high);
	printf("Enter the elements of the array:\n");
	for(i=0;i<high;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched");
	scanf("%d",&n);
	pos=binary_search(arr,low,high-1,n);
	if(pos!=-1)
	printf("found at position %d",pos);
	else
	printf("unsuccesful Search");
	return 0;
}
int binary_search(int a[],int low,int high,int n)
{
	int mid;
	mid=(low+high)/2;
	if(low>high)
		return -1;
	if(a[mid]== n)
		return mid+1;
	if(a[mid]>n)
		binary_search(a,0,mid-1,n);
	else
	binary_search(a,mid+1,high,n);
	
}
