#include<bits/stdc++.h>
using namespace std;

int ltr[100005], rtl[100005];

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        cin>>n>>q;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        ltr[0]=rtl[n+1]=0;
        for(int i=1; i<=n; i++)
        {
            ltr[i]=gcd(ltr[i-1], arr[i-1]);
        }
        for(int i=n; i>=1; i--)
        {
            rtl[i]=gcd(rtl[i+1], arr[i-1]);
        }
        while(q--)
        {
            int l, r;
            cin>>l>>r;
            cout<<gcd(ltr[l-1], rtl[r+1])<<endl;
        }
    }
    return 0;
}