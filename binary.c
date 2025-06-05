#include <stdio.h>

int result = -1;

void binary(int *a, int lb, int ub, int key){
    if(lb>ub){
        return;
    }
    int mid = (lb + ub)/2;

    if(key == a[mid]){
        result = mid;
        return;
    }
    else if(key < a[mid]){
        binary(a, lb, mid-1, key);
    }
    else if(key > a[mid]){
        binary(a, mid +1, ub, key);
    }
    
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 10, 12, 43, 50, 61, 73};
    binary(arr, 0, 9, 12);
    printf("\nFound at Index: %d", result);
    return 0;
}
