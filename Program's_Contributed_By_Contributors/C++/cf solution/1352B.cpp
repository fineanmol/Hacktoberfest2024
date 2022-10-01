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
#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

bool check_even(int n, int k)
{
    int rem = n - 2 * k;
    if (rem < 0)
        return 0;
    if (rem & 1)
        return 0;

    cout << "YES\n";

    for (int i = 0; i < k - 1; i++)
        cout << 2 << ' ';

    cout << 2 + rem << '\n';

    return 1;
}
bool check_odd(int n, int k)
{
    int rem = n - k;
    if (rem < 0)
        return 0;
    if (rem & 1)
        return 0;

    cout << "YES\n";

    for (int i = 0; i < k - 1; i++)
        cout << 1 << ' ';

    cout << 1 + rem << '\n';

    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        int n, k;
        cin >> n >> k;

        if (check_even(n, k) || check_odd(n, k))
            continue;
        else
            cout << "NO\n";
    }
}