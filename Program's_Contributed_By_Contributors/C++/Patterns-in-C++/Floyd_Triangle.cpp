
#include<iostream>
using namespace std;
int main()
{ int n,i,j;
  cin>>n;
  int count=1;
  for(i=1;i<=n;i++)
  {
      for(j=1;j<=i;j++)
      {
          cout<<count<<" ";
          count++;
      }
      cout<<endl;
  }
    return 0;
}
