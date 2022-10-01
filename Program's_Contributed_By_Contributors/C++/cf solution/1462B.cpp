#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  lli n;
  cin>>n;
  while(n--){
string s;
lli x;
bool flag=0;
cin>>x;
cin>>s;
for(lli i=0;i<=4;i++)
if(s.substr(0,i)+s.substr(x-4+i,4-i)=="2020")
{flag=1; break;}
//else {cout<<"NO"<<endl; break;}

if(flag==1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}}