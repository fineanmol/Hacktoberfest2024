/*An ugly number is a positive integer 
whose prime factors are limited to 2, 3, and 5.*/
#include <stdio.h>

int isUgly(int n){
    if(n==1){
        return 1;
    }
    while(n>0){
        if(n%2==0){
            n=n/2;
        }
        else if(n%3==0){
            n=n/3;
        }
        else if(n%5==0){
            n=n/5;
        }
        else if(n==1){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int main()
{
    int n;
    printf("Enter the number--> ");
    scanf("%d",&n);
    if(isUgly(n)==1){
        printf("\nIt is an Ugly number\n");
    }
    else{
        printf("\nIt is not an Ugly number\n");
    }
    return 0; 
}