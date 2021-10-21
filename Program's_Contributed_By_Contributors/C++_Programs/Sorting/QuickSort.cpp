// Introduction to Quick Sort

// QuickSort is a Divide and Conquer algorithm
// We take an element as pivot and we use partition() function to sort the before and after elemets of the pivot.

// Following are the ways in which you can take a pivot element : 
// 1) Pick first element as pivot
// 2) Pick last element as pivot
// 3) Pick a random element as pivot
// 4) Pick median as pivot

// We took last element as pivot in the below code demonstration


// Time Complexity of Quick Sort
// 1) Worst Case : When pivot is the greatest or the smallest element, then we have to iterate from increasing and decreasing order. Time complexity will be O(n^2).
// 2) Average Case : When pivot is choosen between the greatest/smallest element to the middle most element, Time Complexity then will be O(nLogn).
// 3) Best Case : When pivot choosen is the middle most element, Time Complexity will be O(nLogn).

// Quick Sort is the most used sorting technique all over the world becasue even the Worst Case of Time complexity of quick sort is lesser than other sorting technique.


// C++ code for Quick Sort
#include<iostream>
using namespace std;

// Partition() function to sort the before and after elements of the pivot.
// we start from the leftmost element(i = s-1) and keep track of index of smaller (or equal to) elements as i.
// While traversing, if we find a smaller element, we swap current element with arr[i]. Otherwise we ignore current element. 
int partition(int arr[], int s, int e) {

    // We decided the last element as pivot
    int pivot = arr[e];

    int i = s-1;
    for(int j=s; j<e; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}

// quicksort() function which takes the array from main() function and decide the pivot and send the before and after elements of pivot to partition() function.
void quicksort(int arr[], int s, int e) {
    if(s<e) {
        int pi = partition(arr, s, e);
        quicksort(arr, s, pi-1);
        quicksort(arr, pi+1, e);
    }
}

// main() function
int main() {
    // We created the array
    int arr[] = {5,2,7,10,4,8,23,14,21,1};
    // Total elements in the array is 10
    int n = 10;

    // quicksort() function is called
    quicksort(arr, 0, n-1);

    // Printed the Sorted array
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    // Expected Output: 1 2 4 5 7 8 10 14 21 23
    cout<<endl;

    return 0;
}