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
        lli n, s = 0;
        cin >> n;
        lli arr[n];
        fo1(i, n)
        {
            cin >> arr[i];
            s += arr[i];
        }

        lli k = s % n;
        cout << k * (n - k);
        cout << endl;
    }
}
