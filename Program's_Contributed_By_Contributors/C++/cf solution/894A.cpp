#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
string s;
cin>>s;
lli count=0;
lli len=s.length();
for(lli i=0;i<=len;i++)
{
    for(lli j=i+1;j<=len;j++)
    for(lli k=j+1;k<=len;k++)
    if(s[i]=='Q' && s[j]=='A' && s[k]=='Q')
    {count++;}
}
cout<<count;
}