#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)

lli a[1000006] = {0};
lli lastocc[1000006] = {0};
lli ans[1000006] = {0};

int main()
{
    lli n;
    cin >> n;
    for (lli i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(lastocc, 0, sizeof(lastocc));
    memset(ans, 0, sizeof(ans));

    ans[0] = 0;
    double sum = 0.0;
    for (lli i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + (i - lastocc[a[i]]);
        lastocc[a[i]] = i;
        sum = sum + ans[i];
    }
    double finalans = 0.0;
    finalans = (2 * (sum - n) + n) / (n * n * 1.0);
    cout << setprecision(6) << fixed << finalans << endl;
    return 0;
}