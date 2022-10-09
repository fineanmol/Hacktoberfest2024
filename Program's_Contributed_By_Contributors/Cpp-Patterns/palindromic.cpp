// PALINDROMIC PATTERN
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int j;
        for(j=1;j<=n-i;j++){
            cout<<"  "; //double space to be added
        }
        int k=i;
        for(;j<=n;j++){
            cout<<k--<<" ";
        }
        k=2;
        for(;j<=n+i-1;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
    }
    return 0;
}