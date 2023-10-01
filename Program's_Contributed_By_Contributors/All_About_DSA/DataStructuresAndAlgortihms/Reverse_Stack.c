#include <stdio.h>

int push(int a[],int size,int element){
    a[size] = element;
    return 0;
}

int pop(int a[],int size,int n){
    return a[n-size-1];
}

int main(){
    int stack[5];
    int temp_stack[5];

    int element;
    for (int i=0;i<5;i++){
        printf("Enter element : ");
        scanf("%d",&element);
        push(stack,i,element);
    }
    for (int i=0;i<5;i++){
        push(temp_stack,i,pop(stack,i,5));
    }

    printf("Reversed Array : ");
    for (int i=0;i<5;i++){
        printf("%d ",temp_stack[i]);
    }
    printf("\n");
    for (int i=0;i<5;i++){
        push(stack,i,pop(temp_stack,i,5));
    }
    printf("Copied Array : ");
    for (int i=0;i<5;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
    return 0;
}