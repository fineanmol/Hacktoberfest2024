#include <stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int a[], int l, int h){
    int pivot = a[l];
    int i = l, j = h;

    while(i <j){
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i < j){
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}

void QuickSort(int a[], int l, int h)
{
    int j;
    if (l<h){
        j = Partition(a, l, h);
        QuickSort(a, l, j-1);
        QuickSort(a, j+1, h);
    }
}


int main(){
    int arr[]={10, 15, 1, 2, 9, 16, 11};
    printf("The array is:- \n");
    for (int i=0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        printf("%d  ",arr[i]);
    }


    QuickSort(arr, 0 , (sizeof(arr)/sizeof(arr[0])));


    printf("\n The new array is:- \n");
    for (int i=0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        printf("%d  ",arr[i]);
    }

    return 0;
}


