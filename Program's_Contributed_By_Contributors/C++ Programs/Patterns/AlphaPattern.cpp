#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char count = 'A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<count;
        }
        cout<<endl;
        count++;
    }
    return 0;
}