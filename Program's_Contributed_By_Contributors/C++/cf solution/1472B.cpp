#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  lli n,sum=0;
  cin>>n;
 while(n--)
 {
     lli x,a,cnt1=0,cnt2=0;
     cin>>x;
     while(x--)
     {
         cin>>a;
         if(a==1)
         cnt1++;
         else cnt2++;
     }
     if(cnt1%2==0 && cnt2%2==0)
     cout<<"YES"<<endl;
     else if(cnt2%2==1 && cnt1%2==0 && cnt1!=0)
     cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
 }
      


  
 // cout<<sum;
}