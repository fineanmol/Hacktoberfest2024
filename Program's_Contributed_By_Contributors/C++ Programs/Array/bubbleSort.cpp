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
    int j,temp;
    for (i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<< "Sorted Array"<<endl;
    printf("Arr[%d] = ",n);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}


#Changes proposed in this Pull Request :
# 1. Added a new python program for finding the longest common prefix in a list of strings

#Other changes :
#none
