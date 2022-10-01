#include<bits/stdc++.h>
using namespace std;
typedef long long int lli ;
#define max 1000000007 
int main()
{
lli t,n,k;
cin>>t;
while(t--)
{
    cin>>n>>k; //lli index=1,arr[max];
   lli x;
   x=k/(n-1);
   lli rem=k-x*(n-1);

   if(!rem)
{
    cout<<x*n-1<<endl;
}
else cout<<x*n+rem<<endl;
}
}
