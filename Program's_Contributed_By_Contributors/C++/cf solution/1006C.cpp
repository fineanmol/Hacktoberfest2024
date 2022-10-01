#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define for(i,a) for(int i=1;i<=(a);i++)
int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    lli n;
    cin>>n;
    
    lli arr[n];
    for(i,n)
    {
        cin>>arr[i];
    }

    lli s1=0,s2=0; lli i=1,j=n,ans=0;
    while(i<=j)
    {
        if(s1<s2)
        {
            s1+=arr[i++]; 
        }
        else //(s1>s2)
        {
            s2+=arr[j--];
        }
        if(s1==s2)
        {
            ans=s1;
        }

    }
cout<<ans<<endl;



    }
