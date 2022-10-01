#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    int n, a, a1 = 0, b, b1 = 0, c, c1 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a1 += a;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> b;
        b1 += b;
    }
    for (int i = 0; i < n - 2; i++)
    {
        cin >> c;
        c1 += c;
    }

    cout << a1 - b1 << endl;
    cout << b1 - c1;
}
