class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        int maxSize;

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            maxSize = 1;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            // Finds the root of x
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y) {
            // Connects x and y
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                maxSize = max(maxSize, size[rootX]);
                return true;
            }
            return false;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        auto newEdges = edges;
        // Add index to edges for tracking
        int m = newEdges.size();
        for (int i = 0; i < m; i++) {
            newEdges[i].push_back(i);
        }

        // Sort edges based on weight
        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        // Find MST weight using union-find
        UnionFind ufStd(n);
        int stdWeight = 0;
        for (const auto& edge : newEdges) {
            if (ufStd.unite(edge[0], edge[1])) {
                stdWeight += edge[2];
            }
        }

        vector<vector<int>> results(2);
        // Check each edge for critical and pseudo-critical
        for (int i = 0; i < m; i++) {
            UnionFind ufIgnore(n);
            int ignoreWeight = 0;
            for (int j = 0; j < m; j++) {
                if (i != j && ufIgnore.unite(newEdges[j][0], newEdges[j][1])) {
                    ignoreWeight += newEdges[j][2];
                }
            }

            // If the graph is disconnected or the total weight is greater, 
            // the edge is critical
            if (ufIgnore.maxSize < n || ignoreWeight > stdWeight) {
                results[0].push_back(newEdges[i][3]);
            } else {
                // Force this edge and calculate MST weight
                UnionFind ufForce(n);
                ufForce.unite(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for (int j = 0; j < m; j++) {
                    if (i != j && ufForce.unite(newEdges[j][0], newEdges[j][1])) {
                        forceWeight += newEdges[j][2];
                    }
                }

                // If total weight is the same, the edge is pseudo-critical
                if (forceWeight == stdWeight) {
                    results[1].push_back(newEdges[i][3]);
                }
            }
        }

        return results;
    }
};