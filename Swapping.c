#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

int main()
{

    int *arr,n, min, max;
    scanf("%d", &n);
    arr=(int*)malloc(n*sizeof(int));
    
 
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
 
    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
        {
            min = i;
            for (int j = i; j < n; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(&arr[i], &arr[min]);
        }
        else{
            max=i;
            for (int j = i; j < n; j++)
            {
                if (arr[j] > arr[max])
                {
                    max = j;
                }
            }
            swap(&arr[i], &arr[max]);
        }
    }
    for( int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
