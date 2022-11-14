#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    

    void solve(int arr[],int currk,int count,int a,int b,int c){
        //base case
    if(arr[currk]==0 and count==2){
        cout<<"YES"<<endl;
        count++;
    }
    else if(arr[currk]==0 and count!=2){
        cout<<"NO"<<endl;
        count++;
    }
    //rec case
    
    if(arr[currk]==a and arr[currk]!=0){

        currk=a;
        count++;
        solve(arr,currk,count,a,b,c);
    }
    else if(arr[currk]==b and arr[currk]!=0){

        currk=b;
        count++;
        solve(arr,currk,count,a,b,c);
    }
    else if(arr[currk]==c and arr[currk]!=0){

        currk=c;
        count++;
        solve(arr,currk,count,a,b,c);
    }
    
    
    }
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
    int x,a,b,c,count=0;
    cin>>x;
    cin>>a>>b>>c;
    int arr[4];
    int currk=x;
    arr[1]=a;
    arr[2]=b;
    arr[3]=c;
    solve(arr,currk,count,a,b,c);


}
    return 0;
}