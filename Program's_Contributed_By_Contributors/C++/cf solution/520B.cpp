#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    if (n >= m)
    {
        cout << n - m;
        return 0;
    }
    else
    {
        while (m > n)
        {
            if (m % 2 == 0)
            {
                m /= 2;
            }
            else
            {
                m++;
            }
            count++;
        }

        cout << abs(count + n - m);
    }
}
