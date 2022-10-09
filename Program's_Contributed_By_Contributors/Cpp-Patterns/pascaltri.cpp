// PASCAL'S TRIANGLE
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            if(j==0 || i==0)
            { temp=1; }
            else { temp=temp*(i-j+1)/j; }
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}