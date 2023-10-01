#include <stdio.h>

int push(int a[],int size,int element){
    a[size] = element;
    return 0;
}

int pop(int a[],int size,int n){
    return a[n-size];
}

int main(){
    int s;
    printf("Enter the number : ");
    scanf("%d",&s);

    int stack[100];
    int temp,count=0,b=0;
    temp = s;
    while (temp!=0){
        push(stack,count,temp%8);
        temp = temp/8;
        count++;
    }
    for (int i=0;i<count;i++){
        b = 10*b+pop(stack,i,count-1);
    }
    printf("Decimal Number : %d\n",s);
    printf("Octal Number : %d\n",b);
    return 0;
}