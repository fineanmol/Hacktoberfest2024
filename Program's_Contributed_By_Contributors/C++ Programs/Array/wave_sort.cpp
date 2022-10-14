#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void waveSort(int arr[], int n){
    for (int i = 1; i < n; i+=2) {
        if(arr[i]>arr[i-1]) swap(arr, i, i-1);
        
        if(arr[i]>arr[i+1] && i<=n-2) swap(arr, i, i+1);
    }
    
}
int main() {
    int arr[5] = {5, 4, 3, 2, 1};

    waveSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout<<arr[i]<<" ";
    } 
    cout<<endl; 

    return 0;
}