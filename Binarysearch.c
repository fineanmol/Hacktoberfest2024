#include<stdio.h>
int binary_search(int p[],int n, int key)
{
    int low=0,high,mid;
    high=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(p[mid]==key)
        {
            printf("Element %d has found at %d index\n",key,mid+1);
            break;
        }
        else if(p[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(low>high)
    {
        printf("Element %d has NOT found\n",key);
    }
}
int main()
{
    int maxsize,i,element;
    printf("Enter size of the array: ");
    scanf("%d",&maxsize);
    int arr[maxsize];
    printf("Enter the element in the array:\n");
    for(i=0;i<maxsize;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to find: ");
    scanf("%d",&element);
    binary_search(arr,maxsize,element);
    return 0;
}
