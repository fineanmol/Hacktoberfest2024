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
        lli n;
        cin >> n;
        lli x, even = 0, odd = 0;
        fo1(i, n * 2)
        {
            cin >> x;
            if (x % 2 != 0)
                odd++;
            else
                even++;
        }

        if (even == odd)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}