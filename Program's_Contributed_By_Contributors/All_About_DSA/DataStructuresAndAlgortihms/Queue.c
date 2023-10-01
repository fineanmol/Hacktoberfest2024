#include <stdio.h>

int enqueue(int a[],int size,int element){
    a[size]=element;
    return 0;
}
int dequeue(int a[],int size){
    printf("%d is popped\n",a[0]);
    for (int i=0;i<size;i++){
        a[i] = a[i+1];
    }
    return 0;
}
int display(int a[],int size){
    for (int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
int displayFront(int a[]){
    printf("%d\n",a[0]);
    return 0;
}
int displayRear(int a[],int size){
    printf("%d\n",a[size-1]);
    return 0;
}
int main(){
    int n;
    printf("Enter the length of the queue : ");
    scanf("%d",&n);
    if (n>0){
        int a[n];
        printf("-------MENU-------\n");
        printf("-------Queue-------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Display Front\n");
        printf("5. Display Rear\n");
        printf("6. Exit\n");

        int element,size=0,choice = 0;
        while (choice!=6){
            printf("----Enter Command----");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                if (size<n){
                    printf("Enter the element :");
                    scanf("%d",&element);
                    enqueue(a,size,element);
                    size = size+1;
                }
                else{
                    printf("Full Queue\n");
                }
                break;
                case 2:
                if (size==0){
                    printf("EMPTY QUEUE!\n");
                }
                else{
                    dequeue(a,size);
                    size = size-1;
                }
                break;
                case 3:
                if (size==0){
                    printf("EMPTY QUEUE\n");
                } 
                else{
                    display(a,size);
                }
                break;
                case 4:
                if (size==0){
                    printf("EMPTY QUEUE\n");
                }
                else{
                    displayFront(a);
                }
                break;
                case 5:
                if (size==0){
                    printf("EMPTY QUEUE\n");
                }
                else{
                    displayRear(a,size);
                }
                break;
                case 6:
                printf("-------Exiting-------\n");
                break;
                default:
                printf("PLease enter a valid input !\n");
            }
        }
    }
    else{
        printf("Length cannot be negative !\n");
    }
    return 0;
}