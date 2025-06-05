#include <stdio.h>  
 int main()  
{  
    int n;  
    printf("Enter the number of rows");  
    scanf("%d",&n);  
    for(int i=0;i<n;i++)  
    {  
        for(int j=0;j<n;j++)  
        {  
            printf("*");  
        }  
        printf("\n");  
    }  
      
    return 0;  
} 
