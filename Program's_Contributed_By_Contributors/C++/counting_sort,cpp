#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void c_s(int arr[], int n){
    int largest = INT8_MIN;
    for(int i=0; i<n; i++){
        largest = max(largest,arr[i]);
    }

    vector<int> freq(largest+1,0);

    for(int i=0; i<n; i++){
        freq[(arr[i])]++;
    }

    int j=0;
    for(int k=0; k<=largest; k++){
        while (freq[k]>0)
        {
            arr[j] = k;
            freq[k]--;
            j++;
        }
        
    }
}

int main(){
    int arr[]={1,2,3,4,11,4,33,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);

   c_s(arr,n);
   for (auto x : arr){
       cout << x << " ";
   }
}
