#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Binary Search"<<endl;
    cout<< "Enter The Size of array  : ";
    cin>>n;
    int arr[n];
    int i;
    for(i =0;i<n;i++){
        cout<<"Arr["<<i<<"]  : ";
        cin>>arr[i];
    }
    int j,min,pos;
    for(i=0;i<n;i++){
        int temp=-1;
        min =arr[i];
        for(j=i+1;j<n;j++){
            if(arr[j]<min){
                pos=j;
                min = arr[j];
            }
        }
        if(min!=arr[i]){
            temp = arr[i];
            arr[i]=min;
            arr[pos]=temp;


            
        }
    }
    cout<< "Sorted Array"<<endl;
    printf("Arr[%d] = ",n);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}