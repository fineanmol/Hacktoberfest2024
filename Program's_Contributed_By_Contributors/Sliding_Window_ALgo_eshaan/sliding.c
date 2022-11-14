#include<stdio.h>


int SlidingWindow(int arr[], int k,int n)
{
    int sum = 0;
    int max = -1000;
    //int min = _CRT_INT_MAX;
    int st = 0 , ed = k;
    //int n =  sizeof(arr) / sizeof((arr)[0]);
    //printf("The n is : %d",n);
    for(int i =0 ; i<k ; i++)
    {
        sum+=arr[i];
    }

    while(ed<n)
    {
        if(sum > max)
        {
            max = sum;
        }
        sum = sum - arr[st++] + arr[ed++];
    }

    return max;
}

int main()
{
    printf("Enter the size of array\n");
    int n;
    scanf("%d", &n);
    printf("Enter the size of window\n");
    int k;
    scanf("%d", &k);
    int arr[n];
    printf("Enter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int x = SlidingWindow(arr,k,n);
    printf("\nThe max of the consective is %d is : %d\n",k,x);
  

    return 0;
}