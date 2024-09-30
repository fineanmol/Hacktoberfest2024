class Solution {
public:

    void getAllPairShortestDist(int n, vector<vector<int>> &dist, vector<vector<int>> &graph){
        //floydd warshall:
        for(int k=0;k<n;k++){
            for(int source=0;source<n;source++){
                for(int dest=0;dest<n;dest++){
                    if(source == dest) continue;
                    if(dist[source][k] != INT_MAX and dist[k][dest] != INT_MAX){
                        if(dist[source][dest] > dist[source][k] + dist[k][dest])
                            dist[source][dest] = dist[source][k] + dist[k][dest];
                    }
                }
            }
        }
    }

    vector<vector<int>> dp;
    int visitAll(int source, int n, int mask, vector<vector<int>> &dist){
        if(dp[source][mask] != -1) return dp[source][mask];

        bool allVisited = true;
        int minDist = INT_MAX;

        for(int nbr=0;nbr<n;nbr++){
            if((mask & (1<<nbr))) continue;
            allVisited = false;
            int cur = visitAll(nbr, n, mask + (1<<nbr), dist);
            if(cur != INT_MAX) minDist = min(minDist, dist[source][nbr] + cur);
        }

        // seen[source] = false;
        if(allVisited) return dp[source][mask] = 0;
        else return dp[source][mask] = minDist;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(int i=0;i<n;i++) {
            dist[i][i] = 0;
            for(auto nbr: graph[i]) dist[i][nbr] = 1;
        }

        //shortest dist to all pairs:
        getAllPairShortestDist(n, dist, graph);

        //shortest path visiting all nodes:
        int result = INT_MAX, MASK = (1<<(n+1));
        dp = vector<vector<int>> (n+1, vector<int> (MASK+1, -1));
        for(int source=0;source<n;source++){
            result = min(result, visitAll(source, n, 0, dist));
        }

        return result;
    }
};