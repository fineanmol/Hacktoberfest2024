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
        lli a, b;
        cin >> a >> b;

        if (a % 2 != 0 && b % 2 != 0 && b * b <= a)
            cout << "YES" << endl;
        else if (a % 2 == 0 && b % 2 == 0 && b * b <= a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    // }
}
