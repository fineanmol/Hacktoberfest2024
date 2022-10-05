

#include <bits/stdc++.h>

using namespace std;

const int V = 4;

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex numbers a
	// nd enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

	// Run while there are vertices in queue (Similar to
	// BFS)
	while (!q.empty()) {
		// Dequeue a vertex from queue ( Refer
		// http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1)
			return false;

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v) {
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1) {
				// Assign alternate color to this
				// adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can
	// be colored with alternate color
	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(int G[][V])
{

	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// This code is to handle disconnected graph
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
				return false;

	return true;
}

// Driver code
int main()
{
	int G[][V] = { { 0, 1, 0, 1 },
				{ 1, 0, 1, 0 },
				{ 0, 1, 0, 1 },
				{ 1, 0, 1, 0 } };

	isBipartite(G) ? cout << "Yes" : cout << "No";
	return 0;
}