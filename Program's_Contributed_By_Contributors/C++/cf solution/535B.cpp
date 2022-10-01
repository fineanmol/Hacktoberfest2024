#include <bits/stdc++.h>
typedef long long lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
int main()
{
    char a[20];
    cin >> a;

    int len = strlen(a);
    lli ans = 0;
    ans = (1 << len) - 2;
    for (int i = len - 1, pos = 0; i >= 0; i--, pos++)
    {
        if (a[i] == '7')
            ans += (1 << pos);
    }
    cout << ans + 1 << endl;
    return 0;
}
