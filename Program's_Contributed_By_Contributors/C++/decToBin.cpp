#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  // int n;
  // cin>>n;
  
  // int ans=0;
  // for (int i = 0; n; i++)
  // {
  //   int bit=n&1;
  //   ans=(bit*pow(10,i))+ans;
  //   n>>=1;
  // }
  // cout<<ans;

  // dec to bin for -ve number
  int n;
  cin>>n;
  n=abs(n);
  
  int ans=0;
  for (int i = 0; n; i++)
  {
    int bit=n&1;
    int carry=1;
    if(bit)
      bit=0;
    else
      bit=1;
    if (bit && carry==1)
    {
      bit=0;
      carry=1;
    }
    else if((bit==0 && carry==1)||(bit && carry==0))
    {
      bit=1;
      carry=0;
    }
    else bit=0;
    
    ans=(bit*pow(10,i))+ans;
    n>>=1;
  }
  cout<<ans;

  return 0;
}