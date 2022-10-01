#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    lli test;
    cin>>test;
    while(test--)
    {
        lli c,m,x;
        cin>>c>>m>>x;
       lli count=min(c,m);
       lli ans;
       if(x>=count)
        ans=count;
        else{
            ans=(c+x+m)/3;
            if(ans>count) ans=count;
        }
        cout<<ans<<endl;




    }
}