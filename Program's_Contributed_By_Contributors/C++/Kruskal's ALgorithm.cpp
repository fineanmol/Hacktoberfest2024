#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int u;
    int v;
    int weight;
    Node(int first, int second, int wt)
    {
        u = first;
        v = second;
        weight = wt;
    }
};
bool cmp(Node a, Node b)
{
    return a.weight < b.weight;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Node> v;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v.push_back(Node(x, y, w));
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> parent(n, 0), rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int cost = 0;
    vector<pair<int,int>> mst;

    for (auto it : v)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.weight;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << " - " << it.second << endl;
    }
    return 0;
}
