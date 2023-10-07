#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        queue<int> q; // Create a queue for BFS

        visited[startVertex] = true; // Mark the start vertex as visited
        q.push(startVertex); // Enqueue the start vertex

        while (!q.empty()) {
            int currentVertex = q.front(); // Get the front of the queue
            cout << currentVertex << " "; // Print the current vertex
            q.pop(); // Dequeue the current vertex

            // Visit all adjacent vertices of the current vertex
            for (const int& neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark the neighbor as visited
                    q.push(neighbor); // Enqueue the neighbor
                }
            }
        }
    }
};

int main() {
    // Create a graph
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Breadth-First Traversal (starting from vertex 0): ";
    g.BFS(0);

    return 0;
}
