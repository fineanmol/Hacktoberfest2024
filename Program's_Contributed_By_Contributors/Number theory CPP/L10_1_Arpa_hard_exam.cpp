#include<bits/stdc++.h>
using namespace std;
#define lli long long int 


lli pow(lli a, lli n, lli p)
{
    lli res=1;
    while(n)
    {
        if (n%2)
        {
            res=(res*a)%p;
            n--;
        }
        else
        {
            a=(a*a)%p;
            n/=2;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    cout<<pow(8, n, 10);
    return 0;
} 