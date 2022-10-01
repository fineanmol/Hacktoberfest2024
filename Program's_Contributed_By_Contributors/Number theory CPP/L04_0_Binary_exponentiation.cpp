#include<bits/stdc++.h>
using namespace std;

int power(int a, int n)
{
    int res=1;
    while(n)
    {
        if (n%2)
        {
            res*=a; 
            n--;
        }
        else
        {
            n/=2; 
            a*=a;
        }
    }
    return res;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<power(a, n)<<endl;
    return 0;
}