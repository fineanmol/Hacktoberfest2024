#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    bool kahnsAlgo(vector<vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans) // n is no. of vertices
    {
        // STEP-2: Take a queue and push all vertices with indegree=0
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // STEP-2: Process all nodes with indegree=0 and keep decrementing other node's indegree while processing
        int count = 0; // Keep a count of no. of processed nodes (for cycle detection in graph)
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            // Decrement the indegree of all adjacent vertices
            for (auto a : adj[curr])
            {
                indegree[a] -= 1;
                if (indegree[a] == 0)
                {
                    q.push(a);
                }
            }

            ans.push_back(curr); // Push current node (forms topological ordering)
            count += 1;          // Keep count of no. of proceesed vertices
        }

        if (count != n) // No. of processed nodes != No. of nodes
        {
            return false; // Graph is not a DAG
        }

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Make adjancency list
        for (int i = 0; i < n; ++i)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1; // STEP-1
        }

        // Kahn's alogorithm
        vector<int> ans;
        if (kahnsAlgo(adj, numCourses, indegree, ans))
            return ans;

        // Print topological order
        // for (int i = 0; i < ans.size(); i++)
        // cout << ans[i] << " ";
        // cout << endl;

        vector<int> empty;
        return empty;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> edges =
        {
            {5, 0}, {4, 0}, {5, 3}, {3, 0}, {3, 2}, {2, 1}, {4, 1}

        };

    vector<int> ans = s.findOrder(6, edges);

    // Print topological order
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}