#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

void doit()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto i : s)
        if (i == '2')
            cnt++;
    if (cnt == 1 || cnt == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        char a[n][n];
        fo1(i, n)
        {
            fo1(j, n)
            {
                if (i == j)
                    a[i][j] = 'X';
                else
                    a[i][j] = '=';
            }
        }

        fo1(i, n)
        {
            if (s[i] == '2')
            {
                for (int j = i + 1; j < n + i; j++)
                {
                    if (s[j % n] == '2')
                    {
                        a[i][j % n] = '+';
                        a[j % n][i] = '-';
                        break;
                    }
                }
            }
        }
        fo1(i, n)
        {
            fo1(j, n)
                    cout
                << a[i][j];
            cout << endl;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}