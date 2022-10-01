#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    lli n;
    cin >> n;
    while (n--)
    {

        lli x, y, a, b, ans = 0, res, ans1;
        cin >> x >> y >> a >> b;
        if (x > y)
        {
            swap(x, y);
        }
        res = abs(y - x);
        ans = a * res + x * b;
        ans1 = a * x + y * a;
        cout << min(ans1, ans) << endl;
    }
}
