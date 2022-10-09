
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  int n,ans=0;
  cin>>n;
  for (int i = 0; n; i++)
  {
    if (n%10==1)
      ans+=pow(2,i);
    n/=10;
  }
  cout<<ans;
  
  return 0;
}