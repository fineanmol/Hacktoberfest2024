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
lli n,sum=0;
cin>>n;
lli a[n];
for(lli i=0;i<n;i++)
cin>>a[i];

if(n==1&&a[0]%2!=0)
cout<<"-1"<<endl;
else if(a[0]%2==0)
    cout<<1<<endl<<1<<endl;
    else if(a[1]%2==0)
    cout<<1<<endl<<2<<endl;
else {
    
    for(lli i=0;i<n;i++)
   { sum+=a[i];
   if(sum%2==0)
   {
       cout<<i+1<<endl<<1<<" "<<i+1<<endl;
       break;
   }

   }
}

 }return 0;
}