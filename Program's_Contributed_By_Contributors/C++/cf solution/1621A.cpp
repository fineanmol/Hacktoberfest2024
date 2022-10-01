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
void doit()
{

    int n,k,r=1,l=1;
    cin>>n>>k;
    int c=0;
    int a[42]={0};
    for(int i=1;i<43;i++)
    {
        if(i&1)
        c++;
        a[i]+=c;
        
    }

    if(k>a[n])
    {
        cout<<"-1"<<endl;
    }
    else{
        fo2(i,n)
        {
            fo2(j,n)
            {    
                if(i==r && j==l && k!=0)
                {
                    cout<<"R";
                    r+=2;
                    l+=2;
                    k--;
                }
                else cout<<".";
            }
            cout<<endl;
        }
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