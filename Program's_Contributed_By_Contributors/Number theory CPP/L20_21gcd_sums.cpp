#include<bits/stdc++.h>
using namespace std;

int phi[1000001];

int getcount(int d, int n)
{
    return phi[n/d];
}
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
    int q;
    cin>>q;
    init(1000000);
    while(q--)
    {
        int n;
        cin>>n;
        
    }
    return 0;
}