#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
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
   
    bubbleSort(arr, n);
     
  return 0;
}