#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
 int n;
 cin>>n;
 int arr[n+1];
 int min1,min2;
 int c1=0,c2=0,c3=0;
 for (int i = 1; i < n+1; i++)
 {
    cin>>arr[i];
    if(arr[i]==1){
        c1++;
    }
    else if(arr[i]==2){
        c2++;
    }
    else if(arr[i]==3){
        c3++;
    }
     
 }
 min1=min(c1,c2);
 min2=min(min1,c3);

 cout<<min2<<endl;
 for (int i = 0; i < min2; i++)
 {
    for(int i=1;i<n+1;i++){
        if(arr[i]==1){
            cout<<i<<" ";
            arr[i]=0;
            break;
        }
    }
    for(int i=1;i<n+1;i++){
        if(arr[i]==2){
            cout<<i<<" ";
            arr[i]=0;
            break;
        }
    }
    for(int i=1;i<n+1;i++){
        if(arr[i]==3){
            cout<<i;
            arr[i]=0;
            break;
        }
    }
    cout<<endl;
 }
 
 

return 0;
}