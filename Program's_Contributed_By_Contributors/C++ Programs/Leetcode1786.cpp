//Leetcode-#1786. Number of Restricted Paths From First to Last Node - https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

#define pii pair<int, int>
#define mod 1000000007
class Solution {
public:

    void minimumDistanceUsingDijkstra(vector<pii> graph[], vector<int> &distanceFromLastNode, int n) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,n});
        distanceFromLastNode[n] = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto edge : graph[u]) {
                int v = edge.first, dis = edge.second;
                if (distanceFromLastNode[v] > distanceFromLastNode[u] + dis) {
                    distanceFromLastNode[v] = distanceFromLastNode[u] + dis;
                    pq.push({distanceFromLastNode[v], v});
                }
            }
        }
    }

    int dfs(vector<int> &path, vector<pii> graph[], vector<int> &distanceFromLastNode, int src) {
        if (src==1)
            return 1;

        if(path[src]!=-1)
            return path[src];

        int ans=0;

        for (auto edge : graph[src]) {
            int v = edge.first;
            if (distanceFromLastNode[v] > distanceFromLastNode[src]) {
                ans = (ans%mod + dfs(path, graph, distanceFromLastNode, v))%mod;
            }
        }

        return path[src]=ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pii> graph[n+1];
        vector<int> distanceFromLastNode(n+1, INT_MAX);
        for(auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        minimumDistanceUsingDijkstra(graph, distanceFromLastNode, n);
        vector<int> path(n+1, -1);
        return dfs(path, graph, distanceFromLastNode, n );
    }

};
