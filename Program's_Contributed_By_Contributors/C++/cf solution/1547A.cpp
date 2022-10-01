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
    lli t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int i, j, cnt = 0;

        cnt = abs(y2 - y1) + abs(x2 - x1);

        if ((x1 == x3 && x2 == x3) && ((y1 >= y3 && y3 >= y2) || (y3 >= y1 && y2 >= y3)))
        {
            cnt += 2;
        }
        else if ((y1 == y3 && y2 == y3) && ((x1 >= x3 && x3 >= x2) || (x3 >= x1 && x2 >= x3)))
        {
            cnt += 2;
        }
        else if (x1 != x2 && y1 != y2)
        {
            cout << cnt << endl;
            continue;
        }
        cout << cnt << endl;
    }
}
