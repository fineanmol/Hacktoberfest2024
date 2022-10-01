#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  lli n,cnt=1,sum,res=1;
  cin>>n;
  lli arr[n];
  for(lli i=0;i<n;i++)
  cin>>arr[i];
  for(lli i=1;i<n;i++)
 {
     if(arr[i]>arr[i-1])
    { cnt++;
     sum=cnt;}
     else cnt=1;
     res=max(cnt,res);
 }

      
cout<<res;
}