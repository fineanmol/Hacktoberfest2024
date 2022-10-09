// ZIGZAG PATTERN
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(((i+j)%4==0) || (j%4==0 && i==2))
            cout<<" *";
            else cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}