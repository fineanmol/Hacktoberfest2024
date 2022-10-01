#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

void doit()
{

    int n;
    cin >> n;
    char s[n];
    fo1(i, n)
            cin >>
        s[i];
    int r = NULL, l = -1;
    fo1(i, n)
    {
        int cnta = 0, cntb = 0;
        for (int j = i; j < n; j++)
        {
            if (s[j] == 'a')
                cnta++;
            if (s[j] == 'b')
                cntb++;

            if (cnta == cntb)
            {
                r = i;
                l = j;
                //     cout<<cnta<<" "<<cntb<<endl;
                //   cout<<r<<" "<<l<<endl;
                //break;
            }
        }
        if (r != NULL && l != -1)
            break;
    }
    if (r == NULL && l == -1)
        cout << -1 << " " << -1 << endl;
    else
        cout << r + 1 << " " << l + 1 << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}