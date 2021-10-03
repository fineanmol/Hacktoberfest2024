#include<stdio.h>

int main(){

    int arr[100];           // array set with 100 as max elements
    int n;                  // variable for total no. of elements
    int *ptr = arr;           //setting a pointer to array

    printf("no. of elements : ");
    scanf("%d",&n);                 // recieves total no. of elements

    printf("The enter the elements : \n");

    for(int i=0; i<n; i++)
    {
        scanf("%d",ptr);            // recieves each elements to the array
        ptr++;                      // shifts to next pointer
    }
    ptr=arr;
    printf("The elements entered: \n");
    for(int i=0; i<n; i++)
    {
        printf(" %d ,",*ptr);       // dispays each elements of the array
        ptr++;                      // shifts to next pointer
    }
    return 0;
}
