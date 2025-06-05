#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
    }

    cout<<"Your sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
   
    selectionSort(arr, n);
     
  return 0;
}
