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
        int n;
        cin >> n;
        vector<int> v(n);
        lli a = 0, b = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];

            if (v[i] % 2 == 0)
            {
                a++;
            }
            else
                b++;
        }
        if (a % 2 != b % 2)
        {
            cout << "NO\n";
        }
        else
        {
            if (a % 2 == 0)
            {
                cout << "YES\n";
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    int j = i + 1;
                    while (j < n)
                    {
                        if (v[i] % 2 != v[j] % 2 && abs(v[i] - v[j]) == 1)
                        {
                            {
                                flag = 1;
                                break;
                            }
                        }
                        j++;
                    }
                }
                if (flag == 1)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}