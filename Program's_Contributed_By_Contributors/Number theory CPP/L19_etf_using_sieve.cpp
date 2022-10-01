#include<bits/stdc++.h>
using namespace std;

int phi[1000001];

void init( int n)
{
    for(int i=0; i<1000001; i++)
        phi[i]=i;
    for(int i=2; i<n; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<1000001; j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
}


int main()
{
    init(1000000);

    int t;
    cin>>t;
    while(t--)
    {
        int input;
        cin>>input;
        cout<<phi[input]<<endl;
    }
    return 0;
}