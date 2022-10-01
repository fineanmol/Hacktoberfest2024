#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
//#define fo1(x,y ) for(lli x=0;x<y;x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
lli cat[100005], ans = 0;
vector<int> graph[100005];
bool visited[100005];
void dfs(lli sum_cat, int u, lli m)
{
    int sum = 0;
    visited[u] = true;
    if (sum_cat > m)
    {
        return;
    }

    bool ok = false;
    for (int v = 0; v < graph[u].size(); v++)
    {
        if (visited[graph[u][v]] == false)
        {
            cat[graph[u][v]] ? sum = sum_cat + 1 : sum = 0;
            dfs(sum, graph[u][v], m);
            ok = true;
        }
    }

    if (!ok)
        ans++;
}

int main()
{
    lli n, m;
    lli x, y;
    cin >> n >> m;

    for (lli i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }

    for (lli i = 1; i < n; i++)
    {
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(cat[1], 1, m);
    cout << ans;
}
