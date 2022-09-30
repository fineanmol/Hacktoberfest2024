//Binary Search

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int k){
    
    int high = n-1;
    int low = 0;

    while(high>=low){
        int mid = (high + low)/2;
        if(arr[mid]==k) return mid;
        else if (k>arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){

    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int* arr = new int[size];

    for(int i=0;i<size;i++){
        cout<<"enter element "<<i<<": ";
        cin>>arr[i];
        cout<<endl;
    }

    int key;

    cout<<"Enter element you want to search: ";
    cin>>key;
    cout<<"Element is present at index "<<binarySearch(arr, size, key)<<endl;
    return 0;
}