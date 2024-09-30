class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n + 1);
        vector<int> result;

        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n + 1, false);

            if (bfs(u, v, adjList, visited)) {
                return edge;
            }

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return result;
    }
    bool bfs(int start, int target, vector<vector<int>>& adjList, vector<bool>& visited) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == target) {
                return true; 
            }
            visited[current] = true;
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};