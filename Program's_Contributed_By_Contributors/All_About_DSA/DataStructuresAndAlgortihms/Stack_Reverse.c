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
    int temp,n=0;
    temp = s;
    while (temp>0){
        n++;
        temp = temp/10;
    }
    temp = s;
    int stack[100];
    int element;
    for (int i=0;i<n;i++){
        element = temp%10;
        push(stack,i,element);
        temp = temp/10;
    }
    int a[n];
    int b = 0;
    for (int i=0;i<n;i++){
        push(a,i,pop(stack,i,n-1));
    }
    for (int i=0;i<n;i++){
        b = 10*b+pop(a,i,n-1);
    }
    printf("Original Number : %d\n",s);
    printf("Reversed Number : %d\n",b);
    return 0;
}