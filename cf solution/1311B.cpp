#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
//#define fo1(x,y ) for(lli x=0;x<y;x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n);
        vector<int> p(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            int pos;
            cin >> pos;
            p[pos - 1] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (p[i] == 0)
                continue;
            int j = i;
            while (j < n && p[j])
                ++j;
            sort(arr.begin() + i, arr.begin() + j + 1);
            i = j;
        }

        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {

            ok &= arr[i] <= arr[i + 1];
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
