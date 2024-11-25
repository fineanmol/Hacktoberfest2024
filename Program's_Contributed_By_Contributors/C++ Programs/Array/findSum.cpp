#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(), a.end())
#define sa(a, n) sort(a, a + n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define unique(v) v.erase(std::unique(v.begin(), v.end()), v.end());

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        ll a[n];
        ll b[n];
        ll ans = 0;
        fo(i, 0, n)
        {
            cin >> a[i];
        }
        fo(i, 0, n)
        {
            cin >> b[i];
        }
        vector<pair<ll, ll>> v;

        fo(i, 0, n)
        {
            v.pb(make_pair(b[i], a[i]));
        }

        sv(v);
        for (int i = v.size(); i > 0; i--)
        {
            if (v[i].first == v[i - 1].first)
            {
                if (v[i].second > v[i - 1].second)
                {
                    swap(v[i].second, v[i - 1].second);
                }
            }
        }
        
        cout<<endl;
        ans += p;
        ll count = 1;
        int remaining = n-1;
        fo(i, 0, v.size())
        {   
            if (count >= n)
            {
                break;
            }
            if(remaining<v[i].second){
                v[i].second = remaining;
            }
                if (v[i].first * v[i].second <= p * v[i].second)
                {
                    ans += v[i].second * v[i].first;
                    count += v[i].second;
                    remaining -=v[i].second; 
                }

                else
                {
                    ans += p;
                    count++;
                    remaining--;
                }
        }
        cout << ans << endl;
        cout<<endl<<endl;;
    }
    return 0;
}
