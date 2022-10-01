#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int

lli pow(lli a, lli n, lli d)
{
    lli res=1;
    while(n>=1)
    {
        if (n%2)
        {
            res=((res%d)*(a%d))%d;
            n--;
        }
        else
        {
            n/=2;
            a=((a%d)*(a%d))%d;
        }
    }
    return res;
}
//for very long integers euclid division algorithm can not be used to find gcd :\
// lli gcd(int a, int b)
// {
//     if (b==0)
//     {
//         return a;
//     }
//     else
//     {
//         return gcd(b, a%b); 
//     }
// }

lli gcd(lli a, lli b, lli n)
{
    if (a==b)// it means a-b=0 so gcd of a^n b^n and 0 will be equal to a^n b^n
    {
        return (pow(a, n, mod)+pow(b, n, mod))%mod;
    }
    lli candidate=1;
    lli num=a-b;
    for (lli i=1; i*i<=num; i++)
    if (num%i==0)
    {
        lli temp=(pow(a, n, i)+pow(b, n, i))%i;
        if (temp==0) 
        {
            candidate=max(candidate, i);
        }
        
        temp=(pow(a, n, num/i)+pow(b, n, num/i))%(num/i);
        if (temp==0)
        {
            candidate=max(candidate, num/i);
        }
    }
    return candidate%mod;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli a, b, n;
        cin>>a>>b>>n;
        cout<<gcd(a, b, n)<<endl;
    }
    return 0;
}