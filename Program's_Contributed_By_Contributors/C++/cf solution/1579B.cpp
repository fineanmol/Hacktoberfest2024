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
struct s
{
    int x, y, z;
};
void doit()
{
    int n;
    cin >> n;
    int a[55], b[55];
    vector<s> v;
    fo2(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    fo2(i, n)
    {
        int idx = 0;
        if (a[i] == b[i])
            continue;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] == b[i])
            {
                idx = j;
                break;
            }
        }
        v.push_back({i, idx, idx - i});
        for (int j = idx - 1; j >= i; j--)
        {
            a[j + 1] = a[j];
            //cout<<a[j+1]<<" "<<a[j]<<endl;
        }
    }
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i.x << " " << i.y << " " << i.z << endl;
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