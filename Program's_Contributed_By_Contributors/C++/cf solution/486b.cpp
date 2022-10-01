#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m], b[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                    b[k][j] = 0;
                for (int p = 0; p < m; p++)
                    b[i][p] = 0;
            }
        }

    int g[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int d = 0;
            for (int k = 0; k < n; k++)
                d = d | b[k][j];
            for (int p = 0; p < m; p++)
                d = d | b[i][p];

            if (d != arr[i][j])
            {
                cout << "NO";
                return 0;
            }
        }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }

        cout << endl;
    }
}
