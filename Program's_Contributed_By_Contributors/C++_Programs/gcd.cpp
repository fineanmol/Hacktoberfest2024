#include <bits/stdc++.h>
using namespace std;
int gcd(int n,int m)
{
  if(n==0)
  {
    return m;
  }
  else if(m==0)
  {
    return n;
  }
  else if(n==m)
  {
    return n;
  }
  else if(n>m)
  {
    return gcd(n-m,m);
  }
  else
  {
    return gcd(n,m-n);
  }
}
int main()
{
  //write your code here
  int t, i, n, m, res;
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n>>m;
    res=gcd(n,m);
    cout<<res<<endl;
  }
  return 0;
}
