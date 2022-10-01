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

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;

        lli arr[n];
        arr[0] = 0;

        for (lli p = 1; p <= n; p++)
        {
            cin >> arr[p];
        }
        lli j, count = 0;
        for (lli i = 1; i <= n; i++)
        {
            // if(j<0)
            // continue;
            // j=arr[i]-i;
            for (j = arr[i] - i; j <= n; j += arr[i])
            {
                if (j >= 0)
                    if (arr[i] * arr[j] == i + j && i < j)
                        count++;
            }
        }
        cout << count << endl;
    }
}
