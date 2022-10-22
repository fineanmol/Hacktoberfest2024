#include <stdio.h>    
     
int main()    
{    
    //Initialize array     
    int arr[] = {1, 2, 3, 4, 5};     
        
    //Number of elements present in an array can be calculated as follows    
    int length = sizeof(arr)/sizeof(arr[0]);    
        
    printf("Number of elements present in given array: %d", length);     
     
    return 0;    
}    
