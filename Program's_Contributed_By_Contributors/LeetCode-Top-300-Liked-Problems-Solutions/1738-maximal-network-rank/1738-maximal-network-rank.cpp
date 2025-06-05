class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        unordered_map<int, unordered_set<int>> adj;
        // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
        for (auto& road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        // Iterate on each possible pair of nodes.
        for (int node1 = 0; node1 < n; ++node1) {
            for (int node2 = node1 + 1; node2 < n; ++node2) {
                int currentRank = adj[node1].size() + adj[node2].size();
                if (adj[node1].find(node2) != adj[node1].end()) { // If there is a path bw two nodes, then one should be reduced
                    --currentRank;
                }
                // Find the current pair's respective network rank and store if it's maximum till now.
                maxRank = max(maxRank, currentRank);
            }
        }
        // Return the maximum network rank.
        return maxRank;
    }
};