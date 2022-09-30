// Binary Search using recursion

#include <iostream>
using namespace std;
int BinarySearch(int arr[], int k, int high, int low){
    int mid = (high + low)/2;
    if(arr[mid]==k) return mid;
    if(arr[mid]>k) return BinarySearch(arr, k, mid-1, low);
    if(arr[mid]<k) return BinarySearch(arr, k, high, mid+1);
    else return -1;
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
    cout<<"Index of key element is "<<BinarySearch(arr, key, size-1, 0)<<endl;
}