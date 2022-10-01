#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

// auto sgn(int x)
// {
//     if (x > 0)
//         return 1;
//     else
//         return -1;
// };
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n, a, secteam = 0, fteam = 0, ans = 0;
        map<lli, lli> mp;
        cin >> n;
        for (lli i = 0; i < n; i++)
        {
            cin >> a;
            mp[a]++;
            secteam = max(secteam, mp[a]);
        }

        fteam = mp.size();
        ans = max(min(secteam - 1, fteam), min(secteam, fteam - 1));
        cout << ans << endl;
    }
}
