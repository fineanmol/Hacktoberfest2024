#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;

    vector<int>v(1001,0);

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v[x] = max(v[x],i);
    }
    int sum=0;
    for(int j=1; j<1001; j++)
    {
        for (int k=1; k<1001; k++)
        {
            if((v[j]>0) && (v[k]>0) && __gcd(j,k)==1)
            {
                int sum1=(v[j]+v[k]);
                if(sum1>sum)
                sum=sum1;
            }
        }
    }
    if(sum==0)
    cout<<"-1"<<endl;
    else
    cout<<sum<<endl;
    }
    return 0;
}
