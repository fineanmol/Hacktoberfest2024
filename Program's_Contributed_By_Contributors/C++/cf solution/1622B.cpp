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
    int a[n],b[n];
    map<int,int>mp;
    vector<int>zeroes;
    vector<int>ones;
    fo1(i,n)
    {
        cin>>a[i];
        b[i]=a[i];
        mp[a[i]]=i;
    }
    string s;
    cin>>s;
    int l=s.length();

    fo1(i,l)
        {
            if(s[i]=='0')
                zeroes.push_back(a[i]);
        else ones.push_back(a[i]);
        }

        sort(zeroes.begin(),zeroes.end());
        sort(ones.begin(),ones.end());
        sort(a,a+n);

        reverse(zeroes.begin(),zeroes.end());
        reverse(ones.begin(),ones.end());
        reverse(a,a+n);
int i;
            for(i=0;i<ones.size();i++)
            {
                b[mp[ones[i]]]=a[i];
                
            }
           
            fo1(j,zeroes.size())
            {
                b[mp[zeroes[j]]]=a[i];
                i++;
            }
 
        fo1(i,n)
            cout<<b[i]<<" ";
        cout<<endl;
        
        

    
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


