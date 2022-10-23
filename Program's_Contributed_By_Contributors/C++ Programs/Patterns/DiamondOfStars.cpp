#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int n1 = (n+1)/2;
    int n2 = n/2;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n1-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<(2*i+1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n2;i>0;i--){
        for(int j=0;j<n2-i+1;j++){
            cout<<" ";
        }
        for(int j=0;j<(2*i-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}