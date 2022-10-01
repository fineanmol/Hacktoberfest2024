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

lli n,sum1=0,max1=0,max2=0,sum2=0;
cin>>n;
lli r[n];
for(lli i=0;i<n;i++)
{cin>>r[i];
 sum1+=r[i];
max1=max(max1,sum1);

}
lli n1;
cin>>n1;
lli b[n1];
for(lli i=0;i<n1;i++)
{cin>>b[i];
sum2+=b[i];
max2=max(max2,sum2);
}
cout<<max1+max2<<endl;}
 return 0;
}