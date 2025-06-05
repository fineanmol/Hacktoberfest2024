// A union-find algorithm to detect cycle in a graph
#include <bits/stdc++.h>
using namespace std;

// a structure to represent an edge in graph
class Edge {
public:
	int src, dest;
};

// a structure to represent a graph
class Graph {
public:
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges
	Edge* edge;
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[graph->E * sizeof(Edge)];

	return graph;
}

// A utility function to find the subset of an element i
int find(int parent[], int i)
{
	if (parent[i] == i)
		return i;
	return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int parent[], int x, int y) { parent[x] = y; }

// The main function to check whether a given graph contains
// cycle or not
int isCycle(Graph* graph)
{
	// Allocate memory for creating V subsets
	int* parent = new int[graph->V * sizeof(int)];

	// Initialize all subsets as single element sets
	memset(parent, 0, sizeof(int) * graph->V);

	// Iterate through all edges of graph, find subset of
	// both vertices of every edge, if both subsets are
	// same, then there is cycle in graph.
	for (int i = 0; i < graph->E; ++i) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if (x == y)
			return 1;

		Union(parent, x, y);
	}
	return 0;
}

// Driver code
int main()
{
	/* Let us create the following graph
		0
		| \
		| \
		1---2 */
	int V = 3, E = 3;
	Graph* graph = createGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	// add edge 1-2
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	// add edge 0-2
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";

	return 0;
}

// This code is contributed by rathbhupendra

