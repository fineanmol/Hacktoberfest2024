#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli t;
    cin >> t;
    while (t--)
    {
        lli a, b, gcd;
        cin >> a >> b;

        if (b > a)
            swap(a, b);

        gcd = abs(a - b);
        // lli ans1= abs(ans - (a % ans));

        if (a == b)
        {
            cout << 0 << " " << 0;
        }
        else if (abs(a - b) == 1)
            cout << 1 << " " << 0;

        else

        {
            lli down = (a / gcd) * gcd;
            lli up = (a / gcd + 1) * gcd;
            cout << gcd << " " << min((a - down), (up - a));
        }
        cout << endl;
    }
}
