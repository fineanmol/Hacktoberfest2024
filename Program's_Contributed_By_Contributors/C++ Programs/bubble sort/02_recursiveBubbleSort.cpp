#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) 
{
    if(n==1) return;

    for(int j = 0; j < n-1; j++) {
        if(arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;

        }
    }
    
    bubbleSort(arr,n-1); 
}

int main()
{   
    vector<int> v = {0,5,6,7,1,2,3,4};
    int n = v.size();
    bubbleSort(v,n);  
    return 0;
}