#include <stdio.h>

void selection(int arr[],int size);
void printArr(int arr[],int size);
void swap(int *x,int *y);

int main(){

    int arr1[] = {1,5,9,4,3};
    int arr2[] = {20,15,10,2,12};
    size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
    size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
    selection(arr2,size2);
    printArr(arr2,size2);
}

void selection(int arr[],int size){
    int min_idx;
    int k;
    for(int i = 0; i<size ;i++){
        min_idx = i;
        for(int j = i+1; j<size ;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[i],&arr[min_idx]);
    }
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}