// FLOYD'S TRIANGLE
#include<iostream>
using namespace std;
int main()
{
    int n;
    int count=1;
    cout<<"enter the value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    return 0;
}