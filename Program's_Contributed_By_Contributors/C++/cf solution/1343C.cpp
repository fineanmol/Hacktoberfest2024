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
        lli arr[n];
        for (lli i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        lli j, maxi, sum = 0;
        for (lli i = 0; i < n; i++)
        {
            j = i;
            maxi = arr[i];
            while (j < n && sgn(arr[i]) == sgn(arr[j]))
            {
                maxi = max(arr[j], maxi);
                j++;
            }
            i = j - 1;
            sum += maxi;
        }

        cout << sum << endl;
    }
}
