#include<stdio.h>
int arr_insert(int[],int,int,int);
int main()
{
	int arr[20],i,n,element,loc;
	printf("\n Enter the number of elements in an array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",& arr[i]);
	}
	printf("\n Enter an element to be inserted\n");
	scanf("%d",&element);
	printf("\n Enter the location of the element to be inserted\n");
	scanf("%d",&loc);
	arr_insert(arr,element,loc,n);
	printf("\n The array after insert");
	for(i=0;i<n+1;i++)
	{
		printf("%d ",arr[i]);
	}
}
int arr_insert(int a[],int element,int loc, int size)
{
	int i;
	loc--;
	for(i=size-1;i<=loc;i++)
	{
		a[i+1]=a[i];
	}
	a[loc]=element;
}
