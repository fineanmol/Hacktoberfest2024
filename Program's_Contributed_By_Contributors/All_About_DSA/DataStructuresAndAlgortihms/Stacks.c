#include <stdio.h>

int push(int a[],int element,int size){
    a[size] = element;
    return 0;
}
int pop(int a[],int size){
    printf("%d Popped!\n",a[size-1]);
    a[size-1] = 0;
    return 0;
}
int display(int a[],int size){
    for (int i=size-1;i>=0;i--){
        printf("%d\n",a[i]);
    }
    return 0;
}
int peek(int a[],int size,int element){
    int flag;
    for (int i=size-1;i>=0;i--){
        if (a[i]==element){
            flag = 1;
            printf("Element found at %d",size-i);
        }
    }
    return flag;
}
int main(){
    int n,choice,size,flag;
    printf("Enter the size of the stack : ");
    scanf("%d",&n);
    printf("    -----------   STACK   ----------   \n");
    printf("    -----------   MENU    ----------   \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("5. Exit\n");

    int a[n];
    size = 0;
    while (choice!=5){
        printf(" ---- COMMAND ---- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            if (size+1>n){
                printf("STACK OVERFLOW\n");
            }
            else{
                int element;
                printf("Enter the element : ");
                scanf("%d",&element);
                push(a,element,size);
                size = size+1;
            }
            break;
            case 2:
            if (size==0){
                printf("STACK UNDERFLOW\n");
            }
            else{
                pop(a,size);
                size = size-1;
            }
            break;
            case 3:
            if (size==0){
                printf("EMPTY STACK\n");
            }
            else{
                display(a,size);
            }
            break;
            case 4:
            flag = 0;
            int search_element;
            printf("Enter the element : ");
            scanf("%d",&search_element);
            flag = peek(a,size,search_element);
            if (flag==0){
                printf("Element not found !\n");
            }
            break;
            case 5:
            break;
            default:
            printf("Please enter a valid choice!\n");
        }
    }
    return 0;
}