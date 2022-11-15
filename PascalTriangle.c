#include <stdio.h>

int factorial(int num){
    int fact = 1,i;
    for(i = 2;i <= num;fact *= i++);
    return fact;
}

void main(){
int n, i, j, k,num;
printf("Enter the total rows: ");
scanf("%d",&n);

for(i = 0;i < n; i++){
    for(j = 2*(n - i); j > 0; j--){
        printf(" ");
    }
    
    for(j = 0;j <= i; j++){
        num = factorial(i)/(factorial(j)*factorial(i-j));
        printf("%3d ",num);
    }
    printf("\n");
}
}
