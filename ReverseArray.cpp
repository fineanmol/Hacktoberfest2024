//Two cases in this
//even case or odd case
//elements are to be swapped
// for example is take a array arr={1,23,43,45,32}
// so in this array we have to swap 
// (1 with 32), (23 with 45), (43 with 43)
// and the array is reversed
#include<iostream>
using namespace std;
void reverseArray(int arr[], int n);
void swap(int &a, int &b);
void printArray(int arr[], int n);

// Static Memory Allocation
// int main(){
//     int arr[] = {1, 3, 45, 34, 12, 43};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     reverseArray(arr, n);
//     printArray(arr, n);
// }

//Dynamic Memory Allocation
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    reverseArray(arr, n);
    printArray(arr, n);
    delete[] arr;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;      
    }

}
