#include<iostream>
using namespace std;

void anglePattern(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    anglePattern(n-1);
    for(int i =1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    anglePattern(n);

    return 0;
}