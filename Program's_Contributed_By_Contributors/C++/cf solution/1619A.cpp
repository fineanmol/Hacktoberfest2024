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
    string s;
    cin>>s;
    int len=s.length();
    bool flag=1;
    if(len&1)
        {
            cout<<"NO"<<endl;
            
        }
    else{
        len/=2;
        for(int i=0;i<len;i++)
        {
            // cout<<s[i]<<" "<<s[i+len]<<endl;
            if(s[i]!=s[i+len])
            {
                flag=0;
            }

        }
        if(flag==0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
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