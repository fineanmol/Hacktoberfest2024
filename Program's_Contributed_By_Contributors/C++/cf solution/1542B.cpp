#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli dp[1000007];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli t;
    cin >> t;
    while (t--)
    {
        lli n, a, b, f;
        cin >> n >> a >> b;
        bool flag = 0;
        lli s = 1;

        if (a == 1)
        {
            if ((n - 1) % b == 0)
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
            continue;
        }
        while (s <= n)
        {
            if ((n - s) % b == 0)
            {
                flag = 1;
                break;
            }
            s = s * a;
        }

        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}
