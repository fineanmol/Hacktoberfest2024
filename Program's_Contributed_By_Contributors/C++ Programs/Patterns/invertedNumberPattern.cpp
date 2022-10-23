#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<n-i;
        }
        cout<<endl;
    }
    return 0;
}