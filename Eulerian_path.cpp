
#include<iostream>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	Graph(int V) {this->V = V; adj = new list<int>[V]; }
	~Graph() { delete [] adj; } // To avoid memory leak

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Method to check if this graph is Eulerian or not
	int isEulerian();

	// Method to check if all non-zero degree vertices are connected
	bool isConnected();

	// Function to do DFS starting from v. Used in isConnected();
	void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

bool Graph::isConnected()
{

	bool visited[V];
	int i;
	for (i = 0; i < V; i++)
		visited[i] = false;


	for (i = 0; i < V; i++)
		if (adj[i].size() != 0)
			break;

	if (i == V)
		return true;

	
	DFSUtil(i, visited);

	for (i = 0; i < V; i++)
	if (visited[i] == false && adj[i].size() > 0)
			return false;

	return true;
}


int Graph::isEulerian()
{
	// Check if all non-zero degree vertices are connected
	if (isConnected() == false)
		return 0;

	// Count vertices with odd degree
	int odd = 0;
	for (int i = 0; i < V; i++)
		if (adj[i].size() & 1)
			odd++;

	
	if (odd > 2)
		return 0;

	
	return (odd)? 1 : 2;
}

// Function to run test cases
void test(Graph &g)
{
	int res = g.isEulerian();
	if (res == 0)
		cout << "graph is not Eulerian\n";
	else if (res == 1)
		cout << "graph has a Euler path\n";
	else
		cout << "graph has a Euler cycle\n";
}

// Driver program to test above function
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	test(g1);

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(4, 0);
	test(g2);

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(1, 3);
	test(g3);

	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(1, 2);
	g4.addEdge(2, 0);
	test(g4);


	Graph g5(3);
	test(g5);

	return 0;
}
