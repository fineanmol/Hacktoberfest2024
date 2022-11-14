#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=0; i<5; i++){
        for(int j=5; j>i; j--){
            cout<<" ";
        }
        for(int k=0; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=5; i>=0; i--){
        for(int j=5; j>i; j--){
            cout<<" ";
        }
        for(int k=0; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
