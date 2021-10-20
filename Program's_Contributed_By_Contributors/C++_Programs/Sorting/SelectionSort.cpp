// Introduction to selection sort
// The algorithm divides input array into two parts 
// 1) Sorted Part which is built up from left to right
// 2) Unsorted part. Elements remaining to be sorted 
// Initially, sorted part is empty and unsorted part is the entire input array 

// Algorithm finds the smallest element and places in the sorted array at the end(right) in each iteraion
// For the first iteration it will place at 0th index  
// We can say that the algorithm places smallest element at ith position, where i = iteration count 

// Time Complexity of Selection Sort
// Time compelxity - O(n^2) in all cases which makes it ineffecient on large arrays 

// Space Complexity - O(1)


// C++ code for Selection Sort 
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Function which will sort the array using Selection Sort algorithm
void selectionSort(int arr[],int n){
    // outer for loop
    // minimum element will be placed at ith position
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            // finding minimum element and storing its index in min
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        // if minimum element is found it will be swapped with the ith positon
        if(min!=i){
            int temp = arr[min];
            arr[min]=arr[i];
            arr[i]= temp;
        }
    }
}

// main() function 
int main(){
    // creating array 
    int arr[] ={23,0,44,1,3,90,31,26,100};

    // getting length of array 
    int n =  sizeof(arr)/sizeof(arr[0]);

    // calling selectionSort() function
    // It takes an array and length of array as arguments 
    selectionSort(arr,n);

    //printing sorted array
    cout<<"\nSorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    // Expected output : Sorted Array : 0 1 3 23 26 31 44 90 100 
    return 0;
}