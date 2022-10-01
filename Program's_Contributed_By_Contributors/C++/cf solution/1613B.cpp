#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
const int N = 2e5 + 10;
int a[N];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        fo2(i, n)
                cin >>
            a[i];
        sort(a + 1, a + n + 1);
        fo2(i, n / 2)
                cout
            << a[i + 1] << " " << a[1] << endl;
    }
}