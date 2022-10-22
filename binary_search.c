#include<stdio.h>
void main()
{
  int n,a[n],key,i,low,high,mid,found=0;
  printf("Enter the number of elements of the array:");
  scanf("%d",&n);
  printf("Enter the array elements in ascending order\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("Enter the element to be searched : \n");
  scanf("%d",&key);
  low=0;
  high=n-1;
  while(low<=high&&!found)
  {
    mid=(low+high)/2;
    if(a[mid]==key)
      found=1;
    else if(a[mid]<key)
      low=mid+1;
    else
      high=mid-1;
  }
  if(found==1)
    printf("Element found at position : %d",mid+1);
  else
    printf("Element not found in the array !!");
}
