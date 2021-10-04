#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k;
    cout<<"Enter k: ";
    cin>>k;

    // // METHOD 1 - Brute force
    // int sum=0;
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(arr[i]+arr[j] == k) {
    //             cout<<"Index: "<<i<<" "<<j<<endl;
    //             cout<<"True";
    //             return 0;
    //         }
    //     }
    // }
    // cout<<"False";

    //  METHOD 2 - First sort the array in ascending order
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        while(current<arr[j] && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";


    int low=0, high=n-1;
    while(low<high) {
        if(arr[low]+arr[high]==k){
            cout<<"\nIndex: "<<low<<" "<<high<<endl;
            cout<<"True";
            return 0;
        }
        else if(arr[low]+arr[high]>k)
            high--;
        else
            low++;
    }
    cout<<"False";

    return 0;
}