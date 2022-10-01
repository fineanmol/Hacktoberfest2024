#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if(n==1){return false;}
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        string ans=is_prime(n)? "yes":"no"; 
        cout<<ans;
    }
    return 0;
}