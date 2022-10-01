#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
//#define fo1(x,y ) for(lli x=0;x<y;x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli arr[n], m = 0;
        unordered_map<lli, lli> mp;
        for (lli i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            m = max(m, mp[arr[i]]);
        }

        if (m == n)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            cout << "YES" << endl;
            lli second;
            for (lli i = 1; i < n; i++)
            {
                if (arr[i] != arr[0])
                {
                    second = i + 1;
                    break;
                }
            }

            for (lli i = 1; i < n; i++)
            {
                if (arr[i] != arr[0])
                {
                    cout << 1 << " " << i + 1 << endl;
                }
                else
                    cout << second << " " << i + 1 << endl;
            }
        }
    }
}
