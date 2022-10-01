#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    else
    {
        return gcd(b%a, a) ;
    }
}

int common_div(int a, int b)
{
    int count=0;
    int n=gcd(a, b);
    for(int i=1; i*i<=n; i++)
    {
            if(n%i==i)
            {
                count++;
            }
            else
            {
                count+=2;
            }
    }
    return count;
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<common_div(a, b);
    return 0;
}