#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)

int main()
{
    lli n;
    cin >> n;
    while (n--)
    {
        lli n, k;
        cin >> n >> k;
        n--;
        lli ans = 0;
        lli curr = 1;
        while (n > 0 && curr <= k)
        {
            ans++;
            n -= curr;
            curr = 2 * curr;
        }

        ans += (n + k - 1) / k;
        cout << ans << endl;
    }
}
