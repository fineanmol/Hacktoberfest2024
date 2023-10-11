#include <bits/stdc++.h>
using namespace std;

void prepareAdj(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}

void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, vector<int> &component, int node){

    component.push_back(node);
    vis[node] = 1;

    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(adj, vis, component, i);
        }
    }
}

int main()
{
    vector<pair<int, int>> edges;

    edges.push_back({0, 2});
    edges.push_back({2, 1});
    edges.push_back({2, 4});
    edges.push_back({1, 3});
    edges.push_back({3, 4});
    // edges.push_back({2, 5});
    // edges.push_back({3, 6});

    int n = 5;

    unordered_map<int, list<int>> adj;

    prepareAdj(edges, adj);

    unordered_map<int, bool> vis;

    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            vector<int> component;
            dfs(adj, vis, component, i);
            ans.push_back(component);
        }
    }

    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}