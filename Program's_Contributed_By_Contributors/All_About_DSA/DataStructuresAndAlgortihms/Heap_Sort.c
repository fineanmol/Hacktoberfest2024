#include <stdio.h>
#include <stdlib.h>
int heap_size;

int max_heapify(int a[],int i,int heap_size){
    int largest;
    int l = 2*i;
    int r = 2*i+1;
    if ((l<=heap_size)&&(a[l]>a[i])){
        largest = l;
    }
    else{
        largest = i;
    }
    if ((r<=heap_size)&&(a[r]>a[largest])){
        largest = r;
    }
    if (largest!=i){
        int t;
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        max_heapify(a,largest,heap_size);
    }
    return 0;
}

int build_max_heap(int a[],int n){
    int heap_size = n;
    int t;
    if (n%2==0){
        t = n/2;
    }
    else{
        t = (n/2)+1;
    }
    for(int i=t;i>0;i--){
        max_heapify(a,i,heap_size);
    }
    return 0;
}

int heapsort(int a[],int n){
    int t;
    build_max_heap(a,n);
    for (int i=n;i>1;i--){
        t = a[1];
        a[1] = a[i];
        a[i] = t;
        heap_size--;
        max_heapify(a,1,n);
    }
    if (a[n-1]<a[n]){
        t = a[n-1];
        a[n-1] = a[n];
        a[n] = t;
    }
    return 0;
}

int display(int a[],int n){
    printf("Array -- ");
    for (int i=1;i<n+1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}

int main(){
    int n;
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    printf("--------HEAP SORT--------\n");
    printf("--------MENU--------\n");
    printf("1. Enter the array\n");
    printf("2. Heap Sort\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    int a[n+1];
    int choice=0,flag=0;
    while (choice!=4){
        printf("Enter the command -- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            for (int i=1;i<n+1;i++){
                printf("Enter the element : ");
                scanf("%d",&a[i]);
            }
            flag = 1;
            break;
            case 2:
            if (flag==0){
                printf("Please enter an array!\n");
            }
            else{
                heapsort(a,n);
            }
            break;
            case 3:
            if (flag==0){
                printf("Please enter an array!\n");
            }
            else{
                display(a,n);
            }
            break;
            case 4:
            printf("----EXITING----\n");
            break;
            default:
            printf("Please enter a valid input!\n");
        }
    }
    return 0;
}