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
    int temp,j;
    for (i=1;i<n;i++){    // 1 2 3 4 
        temp = arr[i];    // temp= 2
        j = i-1;          // j = 0 arr[j] = 1
        while(j>=0 && temp<arr[j]){ // j!>=0 and 2> 1
            arr[j+1] = arr[j];          
            j--;
        }
        arr[j+1] = temp;       
    }
    cout<< "Sorted Array"<<endl;
    printf("Arr[%d] = ",n);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}