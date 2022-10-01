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
        lli n, x;
        cin >> n >> x;
        lli r, count = 0, count1 = 0;
        // vector<lli> v(n);
        for (lli i = 0; i < n; i++)
        {
            cin >> r;
            if (r % 2 != 0)
                count++;
            else
                count1++;
        }
        lli need;
        bool flag = 0;
        for (lli i = 1; i <= count && i <= x; i += 2)
        {
            need = x - i;
            if (need <= count1)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}