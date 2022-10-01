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

    lli n, h, i = 1, sum = 0, h1, h2;
    cin >> n >> h;
    lli arr[n];
    fo1(i, n)
            cin >>
        arr[i];
    sort(arr, arr + n, greater<int>());
    sum = arr[0] + arr[1];
    if (h < arr[0])
    {
        cout << i << endl;
    }
    else
    {
        h2 = h / sum;
        //cout<<h<<endl;
        i = h2 * 2;
        h1 = h % sum;
        // cout<<i<<endl;
        //cout<<h<<endl;
        if (h1 > 0)
        {
            //   cout<<h<<endl;
            if (h1 > arr[0])
                i += 2;
            else
                i++;
        }
        cout << i << endl;
    }
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