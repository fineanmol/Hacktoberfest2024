#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    int n, m, pairs = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> m;
    int b[m];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(arr, arr + n);
    sort(b, b + m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (abs(arr[i] - b[j]) < 2)
            {
                b[j] = 1000000;
                pairs++;
                break;
            }
    cout << pairs << endl;
}
