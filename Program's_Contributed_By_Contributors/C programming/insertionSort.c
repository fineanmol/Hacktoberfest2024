#include <stdio.h>

void insertion(int arr[],int size);

int main(){

    int arr1[] = {1,5,9,4,3};
    int arr2[] = {20,15,10,2,12};
    size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
    size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
    insertion(arr1,size1);
    printArr(arr1,size1);
}

void insertion(int arr[],int size){
    
    int k; 
    int temp;
    for(int i=1; i<size ; i++){
        k=i-1;
        temp = arr[i];
        for(int j=i-1; j>=0 ; j--){
            if(temp<arr[j] && j >= 0){
                arr[j+1] = arr[j];
                k--;
            }
        }
        arr[k+1]=temp;
    }
}

void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}