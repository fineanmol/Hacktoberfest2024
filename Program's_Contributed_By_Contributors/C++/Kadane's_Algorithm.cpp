#include <bits/stdc++.h>

using namespace std;

int KadaneAlgorithm (int arr[], int size){
    int sum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<size;i++){
       sum+=arr[i];
       maxsum= max(sum,maxsum);
       if(sum<0){
         sum=0;
       }
    }
    return maxsum;
} 

int main()
{ 
    int size;
    cout<< "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout<< "Enter the elements ";
    for(int i=0;i<size;i++){
       cin>>arr[i];
    }
    
    int sum = KadaneAlgorithm(arr,size);
    cout<<"Maximum Subarray sum is: "<<sum;
    return 0;
}
