#include<iostream>
using namespace std;
int Sqrt(int x)
{
  int s=0,e=x,ans=0;
  while(s<=e)
  {
    int mid=s+(e-s)/2;
    if (mid*mid==x)
    {
      return mid;
    }
    
    if(mid*mid>x)
      e=mid-1;
    else{
      ans=mid;
      s=mid+1;
    }
  }
  return ans;
}

double point(int x,int temp, int precision=3)
{
  double fac=1;
  double ans=temp;
  for (int i = 0; i < precision; i++)
  {
    fac=fac/10;
    for (double j = ans;j*j < x; j+=fac)
    {
      ans=j;
    }
  }
  return ans;
  
}

int main()
{
  int n;
  cin>>n;
  int P1=Sqrt(n);
  cout<<"ans= "<<point(n,P1);
  return 0;
}