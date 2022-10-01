#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    lli n, m, count = 0, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        z = m / i;

        if (z <= n && m % i == 0)
        {
            count++;
        }
    }
    cout << count;
}
