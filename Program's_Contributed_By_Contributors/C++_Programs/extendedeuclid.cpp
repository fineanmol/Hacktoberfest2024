#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Triplet{
public:
    int gcd;
    int x;
    int y;

    };
Triplet Extendedeuclid(int a,int b){
if(b==0)
{
    Triplet ans;
    ans.gcd=a;
    ans.x=1;
    ans.y=0;
    return ans;
}
Triplet smallAns=Extendedeuclid(b,a%b);
Triplet ans;
ans.gcd=smallAns.gcd;
ans.x=smallAns.y;
ans.y= (smallAns.x)-((a/b)*(smallAns.y));
return ans;
}
void modInverse(int A,int M)
{
    Triplet ans=Extendedeuclid(A,M);
    ll y=ans.x;
    cout<<(y%M +M)%M<<" ";
}
ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
  return gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
      //  ll ans=0;
        //a>b
        cin>>a>>b;
        Triplet ans=Extendedeuclid(a,b);
       // modInverse(a,b);
        cout<<ans.gcd<<" ";
        //if(a>b)
     //   {
           //  ans=gcd(a,b);
       // }
       // else{
           // ans=gcd(b,a);
       // }
//        cout<<ans<<"\n";
    }
    return 0;
}


