#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  lli n,sum=0;
  cin>>n;
  lli arr[]={1,5,10,20,100};
  for(lli i=4;i>=0;i--)
  {
      if(n>=arr[i])
      {sum+=n/arr[i];
      n-=((n/arr[i])*arr[i]);}
      


  }
  cout<<sum;
}