#include<stdio.h>
int arr_delete(int[],int,int);
int main()
{
	int arr[20],i,n,pos;
	printf("\n Enter the number of elements in an array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",& arr[i]);
	}
	printf("\n Enter the location of the element to be deleted\n");
	scanf("%d",&pos);
	arr_delete(arr,pos,n);
	printf("\n The array after deleteion");
	for(i=0;i<n-1;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
int arr_delete(int a[],int loc, int size)
{
	int i;
	loc--;
	for(i=loc;i<size;i++)
	{
		a[i]=a[i+1];
	}
	a[size-1]=0;
}
