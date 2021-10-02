#include <bits/stdc++.h>
using namespace std;
int lcm(int a,int b,int i)
{
  if(i>a && i>b)
  {
    return 1;
  }
  else if(a%i==0 && b%i==0)
  {
    return i*lcm(a/i,b/i,i);
  }
  else if(a%i==0)
  {
    return i*lcm(a/i,b,i);
  }
  else if(b%i==0)
  {
    return i*lcm(a,b/i,i);
  }
  else
  {
    return lcm(a,b,i+1);
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
    res=lcm(n,m,2);
    cout<<res<<endl;
  }
  return 0;
}
