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

    lli n;
    char c;
    string s;
    cin >> n >> c >> s;
    bool ok = true;
    lli in = -1, count = 0, count1 = 0;
    fo1(i, n)
    {
        if (s[i] == c)
        {
            in = i;
            count1++;
        }
        if (s[i] != c)
        {
            ok = false;
            count++;
        }
    }
    if (ok)
        cout << "0\n";
    else if (in == -1)
    {
        cout << "2\n"
             << n - 1 << " " << n << endl;
    }
    else if (in == n - 1)
    {
        cout << "1\n"
             << in + 1 << "\n";
    }
    else if (in >= n / 2)
        cout << "1\n"
             << in + 1 << endl;
    else
        cout << "2\n"
             << n - 1 << " " << n << "\n";
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