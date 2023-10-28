#include<stdio.h>
int main()
{
	int arr[20],n,i,key,result;
	printf("enter the number of elements in an array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be searched");
	scanf("%d",&key);
	result=linear_search(arr,n,key);
	if(result!=-1)
	printf("found at position %d",result);
	else
	printf("Unsuccesful Search");
	return 0;
}
int linear_search(int a[],int n,int k)
{
	int i,pos;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			pos=i;
			return pos+1;
		}
	}
		return -1;
}
