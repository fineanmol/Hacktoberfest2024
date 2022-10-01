#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{
    int m, s;
    cin >> m >> s;
    if (s == 0)
    {
        if (m == 1)
        {
            cout << "0 0" << endl;
            return 0;
        }
        else
        {
            cout << "-1 -1" << endl;
            return 0;
        }
    }
    string maxi;
    string mini;
    for (int i = 0; i < m; i++)
    {
        int k = min(9, s);
        maxi.push_back('0' + k);
        s -= k;
    }
    if (s > 0)
    {
        cout << "-1 -1" << endl;
        return 0;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        mini.push_back(maxi[i]);
    }
    int j = 0;
    while (mini[j] == '0')
        j++;
    mini[0]++;
    mini[j]--;

    cout << mini << " " << maxi;
}
