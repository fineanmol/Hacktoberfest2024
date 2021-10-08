#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a>0 && b>0){
            cout<<"Solution";
        }
        else if(a==0 && b>0){
            cout<<"Liquid";
        }
        else if(b==0 && a>0){
            cout<<"Solid";
        }
        cout<<endl;
    }
}