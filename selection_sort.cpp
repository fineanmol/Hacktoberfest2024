#include<iostream>
using namespace std;

void selection_sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}
int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    selection_sort(arr,n);

    for(int i=0; i<n; i++) {
        cout<< arr[i] <<" ";
    }
    return 0;
}
