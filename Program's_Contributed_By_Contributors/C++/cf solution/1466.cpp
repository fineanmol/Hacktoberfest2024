#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  lli t;
  cin>>t;
  while(t--){

lli n;
cin>>n;
//lli arr[n];
// lli count=0;
// for(int i=0;i<n;i++)
// cin>>a[i];
// for(lli i=1;i<n;i++)
// {
//     if(arr[i-1]!=arr[i])
//     count++;
//     else {
//         arr[i-1]++;
//         count++;

//     }
// }
// cout<<count<<endl;
set<lli> S;
for(lli i=1;i<=n;i++)
{
    lli v;
    cin>>v;
    if(S.count(v))
    v++;
    S.insert(v);
}

cout<<S.size()<<endl;
 }
}