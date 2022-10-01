#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int l = -1, r = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                l = i;
        }
        int i = 1;
        r = l + 1, l--;
        while (1)
        {
            if (l < s.size() && s[l] == 'a' + i)
                l--, i++;
            else if (r < s.size() && s[r] == 'a' + i)
                r++, i++;
            else
                break;
        }
        if (l == -1 && r == s.size())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}