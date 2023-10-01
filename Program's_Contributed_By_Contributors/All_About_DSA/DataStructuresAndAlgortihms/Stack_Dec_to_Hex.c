#include <stdio.h>
int push(int a[],int size,int element){
    a[size] = element;
    return 0;
}

char pop(int a[],int size,int n){
    if (a[n-size]<10){
        return (char)(a[n-size]+48);
    }
    else{
        return (char)(a[n-size]+55);
    }
    return '0';
}

int main(){
    int s;
    printf("Enter the number : ");
    scanf("%d",&s);

    int stack[100];
    int temp,count=0;
    temp = s;
    while (temp!=0){
        push(stack,count,temp%16);
        temp = temp/16;
        count++;
    }

    char b[count];
    for (int i=0;i<count;i++){
        b[i] = pop(stack,i,count-1);
    }
    printf("Decimal Numbe : %d\n",s);
    printf("Hexa Decimal Number : ");
    for (int i=0;i<count;i++){
        printf("%c",b[i]);
    }
    printf("\n");
    return 0;
}