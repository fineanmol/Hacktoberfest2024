#include <iostream>
#include<bits/stdc++.h>

using namespace std;



void printF(int i,vector<int> &ds, int arr[],int n,int sum,int s){
    if(i == n){
        if(s==sum){
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
        
    }
    
    ds.push_back(arr[i]);
    s+= arr[i];
    printF(i+1,ds,arr,n,sum,s);
    s-=arr[i];
    ds.pop_back();
    printF(i+1,ds,arr,n,sum,s);
}




int main() {
    int arr[]={1,2,1};
    int n=3;
    int sum =2;
    vector<int>ds;
    printF(0,ds,arr,n,sum,0);

    return 0;
}
