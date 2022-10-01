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
        vector<string> bi(n - 2);
        for (auto &b : bi)
            cin >> b;
        string str = bi[0];
        bool found = false;

        for (int i = 1; i < (n - 2); i++)
            if (str.back() != bi[i].front())
            {
                found = true;
                str += bi[i];
            }
            else
            {
                str += bi[i].back();
            }

        if (!found)
            str += 'a';
        cout << str << '\n';
    }
}
