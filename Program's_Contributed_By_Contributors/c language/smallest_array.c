#include<stdio.h>
int Small_Element(int[],int);
int main()
{
	int arr[20],i,n,result;
	printf("\n Enter the number of elements in an array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",& arr[i]);
	}
	result=Small_Element(arr,n);
	printf("\n The smallest number in the array= %d",result);
}

int Small_Element( int arr[],int n)
{
	int smallest,i,pos;
	smallest=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]<smallest)
		{
			smallest=arr[i];
			pos=i;
		}
	}
	printf("The position of smallest integer = %d",pos+1);
	return smallest;
}
