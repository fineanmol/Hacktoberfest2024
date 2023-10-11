#include <bits/stdc++.h>
using namespace std;
void topoSortBFS(unordered_map<int, list<int>> &adj, int n, vector<int> &indegree, vector<int> &ans){

    //make queue
    queue<int> q;

    //push into queue which have 0 indegree
    for(int i=1; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //processing start
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
}
int main()
{
    //given graph
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({2, 5});
    edges.push_back({3, 5});
    edges.push_back({5, 4});

    int n = 5;

    //make adjacency list
    unordered_map<int, list<int>> adj;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }


    //take indgree of all nodes
    vector<int> indegree(n+1, 0);

    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    //data structure to store the values
    vector<int> ans;

    //calling the Breadth First Search function
    topoSortBFS(adj, n, indegree, ans);

    //printing the ans
    for(auto i : ans){
        cout << i << " ";
    }


    return 0;
}