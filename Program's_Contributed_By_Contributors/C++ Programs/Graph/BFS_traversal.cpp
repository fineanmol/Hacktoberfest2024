// BFS : Breadth first Search

#include <bits/stdc++.h>
using namespace std;

void adjList(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void BFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q;

    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // traverse all the neighbours Node
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    vector<pair<int, int>> edges;
    //     0 1
    // 0 2
    // 0 3
    // 1 4
    // 1 7
    // 2 5
    // 3 6
    edges.push_back({0, 1});
    edges.push_back({0, 2});
    edges.push_back({0, 3});
    edges.push_back({1, 4});
    edges.push_back({1, 7});
    edges.push_back({2, 5});
    edges.push_back({3, 6});

    int n = 8;

    unordered_map<int, list<int>> adj;

    adjList(edges, adj);

    unordered_map<int, bool> visited;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(adj, visited, ans, i);
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}