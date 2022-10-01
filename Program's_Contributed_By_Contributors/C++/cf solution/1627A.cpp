#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)


void doit(){

   ll n,m,r,c;
   char x;
   cin>>n>>m>>r>>c;
   vector<ll>a;
   vector<ll>b;
   a[0]=0;
   b[0]=0;
   fo1(i,n){
       fo1(j,m){
           cin>>x;
           if(x=='B'){
               a.push_back(i+1);
               b.push_back(j+1);
           }
       }
   }

   sort(a.begin(),a.end());
   sort(b.begin(),b.end());

    ll y=0;
   fo1(i,n){
        y=min(abs(r-a[i]),y);
   }
    ll k=0;
   fo1(i,m){
        k=min(abs(c-b[i]),k);
   }

   if(a[0]==0 && b[0]==0)
       {
           cout<<"-1"<<endl;
            return;
           
       }

    bool flag1=false,flag2=false;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==r)
            flag1=true;
    }
     for(ll i=0;i<m;i++)
    {
        if(b[i]==c)
            flag2=true;
    }
    if( flag1 && flag2)
    {
        cout<<0<<endl;
        return;
    }

    
    else{
        cout<<min(y,k)+1<<endl;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}


