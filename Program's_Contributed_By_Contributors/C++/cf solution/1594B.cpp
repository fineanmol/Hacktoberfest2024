#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
//#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

// void doit()
// {
//     lli MAX = lli(1000000007);
//     lli n, k, l, r, ans, n1;
//     cin >> n >> k;
//     n1 = n;
//     vector<pair<lli, lli>> p;
//     p.push_back(make_pair(-1, 0));
//     for (lli i = 1; i <= k; i++)
//     {
//         if (p.size() == k)
//             break;
//         p.push_back(make_pair(-1, i));
//         for (int j = 0; j < i; j++)
//         {
//             p.push_back(make_pair(j, i));
//             if (p.size() == k)
//                 break;
//         }
//     }

//     for (auto x : p)
//     {
//         cout << x.first << " " << x.second << endl;
//     }
//     cout << p.size() << endl;
//     //   // cout<<p[n-1].first<<" "<<p[n-1].second<<endl;
//     l = p[n - 1].first;
//     r = p[n - 1].second;
//     if (l == -1)
//         ans = pow(n1, r);
//     else
//         ans = pow(n1, l) + pow(n1, r);
//     cout << ans << endl;
// }
lli mod = 1000000007;
void doit()
{
    lli n, k;
    lli ans = 0, p = 1;
    cin >> n >> k;
    for (lli i = 0; i <= 30; i++)
    {
        if (k & (1 << i))
        {
            ans = (ans + p) % mod;
        }
        p = (p * n) % mod;
    }
    cout << ans << endl;
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