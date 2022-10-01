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

    int n;
    cin>>n;
    string s="",a="",b="";
    cin>>s;
    a+=s[0];
    if(s[0]==s[1]|| s[1]>s[0])
    {
        cout<<a;
        reverse(a.begin(),a.end());
        cout<<a<<endl;
    }

    else{
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=s[i+1])
                a+=s[i+1];
            else break;
        }
        b=a;
        reverse(b.begin(),b.end());
        a+=b;
        cout<<a<<endl;
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