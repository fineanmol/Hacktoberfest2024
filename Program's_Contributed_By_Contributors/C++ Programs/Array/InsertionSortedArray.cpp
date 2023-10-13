#include<bits/stdc++.h>
#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { 
                break;
            }
            
        }
        
        arr[j+1] = temp;  
    } 
}
int main(){
    vector<int> arr = {2,4,5,8,9,3,1,6};
    int n = 8;
    insertionSort(n,arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
    
}
