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
//#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

lli mod = 1000000007;
void doit()
{

    lli n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    fo1(i, n)
    {
        cin >> a[i];
    }
    vector<string> b(n);
    fo1(i, n)
        fo1(j, m) b[i]
            .push_back('.');

    while (k < 11)
    {
        fo1(i, n)
        {
            fo1(j, m)
            {
                if (i >= k && j >= k && m - 1 - j >= k && a[i][j] == '*')
                {
                    int f = 1;
                    for (int p = i, q = j; p >= i - k, q >= j - k; p--, q--)
                        if (a[p][q] == '.')
                            f = 0;
                    for (int p = i, q = j; p >= i - k, q <= j + k; p--, q++)
                        if (a[p][q] == '.')
                            f = 0;

                    if (f == 1)
                    {
                        for (int p = i, q = j; p >= i - k, q >= j - k; p--, q--)
                            b[p][q] = '*';

                        for (int p = i, q = j; p >= i - k, q <= j + k; p--, q++)
                            b[p][q] = '*';
                    }
                }
            }
        }
        k++;
    }
    fo1(i, n)
    {
        fo1(j, m)
        {
            if (b[i][j] == '.' && a[i][j] == '*')
            {
                cout << "NO\n";
                return;
            }
            if (b[i][j] == '*' && a[i][j] == '.')
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}