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
    printf("Enter a number : ");
    scanf("%d",&s);

    int stack[100];
    int temp,size=0,b=0;
    temp = s;
    while (temp!=0){
        push(stack,size,temp%2);
        temp = temp/2;
        size++;
    }
    for (int i=0;i<size;i++){
        b = 10*b+pop(stack,i,size-1);
    }
    printf("Decimal Number : %d\n",s);
    printf("Binary Number : %d\n",b);
    return 0;
}