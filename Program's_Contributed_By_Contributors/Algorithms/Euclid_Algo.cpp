// This algorith is used to find the HCF of given two numbers!😀
#include<bits/stdc++.h>
using namespace std;

void gcd(int a ,int b)
{
    // 🧠Logic is modulus of a/b karne se ya a-b karne se gcd change nahi hota ie gcd of 24 & 18 == Gcd of 18 & 6
    int t1 = max(a,b);
    int t2= min(a,b);
    int gcd;
    while((t2!=0))
    {
        gcd=t1%t2;
        t1=t2;
        t2=gcd;
    }
    cout<<t1;
}

int main()
{
    int a=50, b=45;
    // cin>>a>>b;
    gcd(a,b);
    return 0;
}