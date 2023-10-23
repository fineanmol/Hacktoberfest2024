//program to find the minimum and the maximum element in an unsorted array
#include<stdio.h>
int main(){
	int n,i;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		printf("enter the element number %d \n",i+1);
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	int min=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
		if(arr[i]<min)
		min=arr[i];
	}
	printf("max is %d min is %d",max,min);
	return 0;
	
}
