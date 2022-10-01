#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    int m, n, i, j, ans, k;
    cin >> n;
    int arr[n], p;
    int cnt = 0;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    sort(arr, arr + n);
    while (m--)
    {
        cin >> k;
        ans = upper_bound(arr, arr + n, k) - arr;
        cout << ans << endl;
    }
}
