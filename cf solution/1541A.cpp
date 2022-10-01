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

lli arr[1000], b[1000];
int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;

        for (int j = 0; j < n; j++)
            arr[j] = j + 1;

        int i;
        for (i = 1; i < n; i += 2)
        {
            swap(arr[i - 1], arr[i]);
        }
        if (n % 2 != 0)
        {
            swap(arr[n - 1], arr[n - 2]);
        }

        for (int j = 0; j < n; j++)
            cout << arr[j] << " ";

        cout << endl;
    }
}
