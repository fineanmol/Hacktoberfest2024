#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

ll mod = 1000000007;

bool isPal(vector<ll>&v){
    ll s=v.size();
    ll i=0,j=s-1;
    while(i<j){
        if(v[i]!=v[j])
            return 0;
        i++,j--;
    }
    return 1;
}

bool check(vector<ll>&a,ll x){
    vector<ll>b;
    for(int i=0;i<a.size();i++){
        if(a[i]!=x)
            b.push_back(a[i]);
    }
    bool ans=isPal(b);
    return ans;
}
void doit1()
{
      
    ll a,b,c;
    cin>>a>>b>>c;
    bool flag=0;
    if(b-a==c-b)
        flag=1;
    if(a==b==c){
        flag=1;
    }
    else if(a==b && b>c && b%c==0)
    {
        flag=1;
    }
     else if(a==c && a>b && c%b==0)
    {
        flag=1;
    }
    else if(b==c && b>a && b%a==0)
    {
        flag=1;
    }
    else if(a==b==1 && c%2!=0){
        flag=1;
    }
    else if(c==b==1 && a%2!=0){
        flag=1;
    }


    if(b>a && b>c){
        ll d=abs(a-b);
        ll x=c+d;
        if(x%c==0)
            flag=1;
        //else cout<<"NO"<<endl;

        // return;

    }
    if(b>a && b>c){
        ll d=abs(c-b);
        ll x=a+d;
        if(x%a==0)
            flag=1;
        // else cout<<"NO"<<endl;

        // return;

    }
    if(a>b && c>b){
        ll d=abs(a-c);
        d/=2;
        ll am=min(a,c);
        ll x=am+d;
        if(x%b==0)
            flag=1;
        // else cout<<"NO"<<endl;

        // return;
    }

    if(flag)
     cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    
}
void doit(){

    int a,b,c;
    cin>>a>>b>>c;
    bool flag=0;
    if(b-a==c-b)
    {
        flag=1;
    }
    if((a+c)%(2*b)==0)
        {
            flag=1;
        }
    if((2*b-c)>0)
        if((2*b-c)%a==0)
            {
                flag=1;
            }
    if((2*b-a)>0)
        if((2*b-a)%c==0)
            {
                flag=1;
            }
    if(flag)
     cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
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


