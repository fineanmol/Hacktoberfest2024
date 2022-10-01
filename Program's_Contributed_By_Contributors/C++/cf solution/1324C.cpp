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
        string s;
        cin >> s;
        vector<int> v;
        v.push_back(0);
        lli n = s.length();
        for (lli i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
                v.push_back(i + 1);
        }

        v.push_back(n + 1);
        int ans = 0;
        for (lli i = 0; i < v.size() - 1; i++)
        {
            ans = max(ans, v[i + 1] - v[i]);
        }

        cout << ans << endl;
    }
}
