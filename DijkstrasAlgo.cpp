#include <bits/stdc++.h>
#define infinity 1000
#define MAX 100

using namespace std;

class Graph
{

    int G[MAX][MAX];
    int n;

public:
    Graph()
    {
        n = 0;
    }
    void readgraph();
    void printgraph();
    void dijkstra(int start);
};

void Graph::readgraph()
{

    int i, j, v_source, v_dest, no_of_edges, weight;
    cout << "\nEnter no of vertices: ";
    cin >> n;

    for (i = 0; i < n; i++)
    { // Initialize the adjacency matrix
        for (j = i+1; j < n; j++)
        {
            G[i][j] = 0;
        }
        cout << "\nEnter no of edges: ";
        cin >> no_of_edges;
        cout << "\nEnter the list of edges: ";

        for (i = 0; i < no_of_edges; i++)
        {

            cout << "\nEnter an edge (source,destination,weight): ";
            cin >> v_source >> v_dest >> weight;
            G[v_source][v_dest] = G[v_dest][v_source] = weight;
        }
    }
}

void Graph::printgraph()
{
    int i, j;
    cout << "\nList of edges in the spanning tree: ";
    // Scan the upper triangle of the adjacency matrix
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (G[i][j] != 0)
                cout << "\n(source,destination,weight) = (" << i << "," << j << "," << G[i][j] << ")";
}

void Graph::dijkstra(int start)
{

    int cost[MAX][MAX];
    int min_distance, distance[MAX], from[MAX];
    int visited[MAX], i, j, cnt = 0, next_Node;

    // create cost [][] matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {

            if (G[i][j] == 0)
                cost[i][j] = infinity;

            else
                cost[i][j] = G[i][j];
        }

    // initialise visited[],distance[] and from[]
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        from[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    cnt = 1;
    // no.of vertices to be visited
    while (cnt <= n - 1)
    {
        // find the vertex at minimum distance from the tree
        min_distance = infinity;
        for (i = 0; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                next_Node = i;
                min_distance = distance[i];
            }
        visited[next_Node] = 1;
        // update the distance[] array
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 && (min_distance + cost[next_Node][i] < distance[i]))
            {
                distance[i] = cost[next_Node][i] + min_distance;
                from[i] = next_Node;
            }
        }
        cnt++;
    }
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            cout << "\n Distance of " << i << " is : " << distance[i];
            cout << "\t path = " << i;
            j = i;
            do
            {
                j = from[j];
                cout << "<-" << j;
            } while (j != start);
        }
    }
}

int main()
{
    Graph g;
    int start;
    g.readgraph();
    cout << "\n graph is:\n";
    g.printgraph();
    cout << "\nEnter the start vertex: \n";
    cin >> start;
    g.dijkstra(start);

    return 0;
}