#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

auto sgn(int x)
{
    if (x > 0)
        return 1;
    else
        return -1;
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        int d = n / 2;
        int j = d;
        lli sum = 0;
        for (lli i = 0; i < d; i++)
        {
            sum += j * 2 * ((n) + (n - 2));
            n = n - 2;
            j--;
        }
        cout << sum << endl;
    }
}
