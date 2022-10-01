#include<bits/stdc++.h>
using namespace std;

void interval(int l, int r)
{
    int prime[r]={0};
    for (int i=2; i<=r; i++)
    {
        if (prime[i]==0)
        {
            for(int j=i*i; j<=r; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for (int i=l; i<=r; i++)
    {
        if (prime[i]==0)
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int L, R;
    cin>>L>>R;
    interval(L,R);
    return 0;
}