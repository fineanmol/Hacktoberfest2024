#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS Traversal of an undirected and unweighted graph.
void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); // do this because undirected graph
} // createAndAddEdge(vector <int> List[], int u, int v)

void RecursiveDFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  visitedVertex.at(source) = true;
  cout << source << " "; // Print Vertex
  for (vector<int>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
    if (!visitedVertex[*it])
      RecursiveDFS(adjList, visitedVertex, *it); // Go as far as possible by recursing.
} // DFS

int main (void){
  // Idea is to implement the adjacency list as an array of vectors:
  const int numVertices = 5; // 6 vertices (0,1,2,3,4,5)
  int source = 0;
  vector<int> adjList[numVertices]; // Create an array of vectors
  vector <bool> visitedVertex(numVertices, false); // have a visted vector initialized to false
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 3, 3); // Do this because no children!
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 2, 2);
  RecursiveDFS(adjList, visitedVertex, source); // Perform DFS given graph G and a source s
  cout << endl;
  //Should Print: 0 1 3 4 2

}
