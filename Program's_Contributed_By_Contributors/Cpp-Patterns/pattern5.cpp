// HALF PYRAMID USING NUMBERS
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    for(int i=1; i<=n;i++){
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;

    }
}