#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {

        lli n, x = 0, xr = 1;
        cin >> n;
        lli arr[n];
        fo1(i, n) cin >> arr[i];
        if (n % 2 == 0)
            xr = 0;
        else
        {
            fo1(i, n - 1)
            {
                if (arr[i + 1] <= arr[i])
                {
                    xr = 0;
                    break;
                }
            }
        }
        if (xr == 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}

// lli count = 1;
// lli n;
// cin >> n;
// lli arr[n];
// arr[0] = 0;
// for (lli i = 1; i <= n; i++)
// {
//     cin >> arr[i];
// }

// lli j = 1;
// lli i = 1;
// lli xr = 0;
// lli last = 0;
// while (n--)
// {
//     if (arr[i - 1] > arr[i])
//     {
//         j = i - j;
//         //   j += arr[i] - (j);
//         last = i - j;
//         cout << j << " " << last << endl;
//         xr ^ last;
//     }
//     i++;
// }
// cout << j << endl;
// cout << n - j - 1 << endl;
// xr ^= (n - j - 1);
// cout << xr << endl;
