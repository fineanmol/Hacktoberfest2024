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

void doit()
{
    string x, x1;
    int extra, extra1;
    cin >> x >> extra;
    cin >> x1 >> extra1;
    while (x.length() > 0 && x.back() == '0')
    {
        x.pop_back();
        extra++;
    }
    while (x1.length() > 0 && x1.back() == '0')
    {
        x1.pop_back();
        extra1++;
    }
    if ((x.length() + extra) > (x1.length() + extra1))
    {
        cout << ">" << endl;
    }
    else if ((x.length() + extra) < (x1.length() + extra1))
    {
        cout << "<" << endl;
    }
    else
    {
        if (x > x1)
            cout << ">" << endl;

        else if (x < x1)
            cout << "<" << endl;

        else
            cout << "=" << endl;
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}