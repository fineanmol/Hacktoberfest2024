#include <bits/stdc++.h>
int minDistanceFromVertix(std::vector<int> distanceFromSource, std::vector<bool> shortestPathSet, int V)
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (!shortestPathSet[v] && distanceFromSource[v] <= min)
			min = distanceFromSource[v], min_index = v;
	return min_index;
}
std::vector<std::vector<int>> dijkstra(std::vector<std::vector<int>> graph, int source, int V)
{
	std::vector<int> distanceFromSource(V, INT_MAX), predecessor(V, 0);
	std::vector<bool> shortestPathSet(V, false);
	distanceFromSource[source] = 0;
	for (int count = 0; count < V; count++)
	{
		int u = minDistanceFromVertix(distanceFromSource, shortestPathSet, V);
		shortestPathSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!shortestPathSet[v] && graph[u][v] && distanceFromSource[u] != INT_MAX && distanceFromSource[u] + graph[u][v] < distanceFromSource[v])
				distanceFromSource[v] = distanceFromSource[u] + graph[u][v], predecessor[v] = u;
	}
	return {distanceFromSource, predecessor};
}
int main()
{
	int source = 0, V = 8;
	std::vector<std::vector<int>> graph{
		{0, 2, 0, 0, 0, 0, 6, 0},
		{2, 0, 7, 0, 2, 0, 0, 0},
		{0, 7, 0, 3, 0, 3, 0, 0},
		{0, 0, 3, 0, 0, 0, 0, 2},
		{0, 2, 0, 0, 0, 2, 1, 0},
		{0, 0, 3, 0, 2, 0, 0, 2},
		{6, 0, 0, 0, 1, 0, 0, 4},
		{0, 0, 0, 2, 0, 2, 4, 0},
	},
		result = dijkstra(graph, source, V);
	std::cout << "Starting Vertex : " << (char)(source + (int)'A') << std::endl
			  << "Vertex\tDistance\tPath" << std::endl;
	for (int i = 0; i < V; i++)
	{
		std::cout << (char)(i + (int)'A') << "\t" << result[0][i] << "\t\t" << (char)(i + (int)'A');
		for (int j = result[1][i]; j != source; j = result[1][j])
			std::cout << " <- " << (char)(j + (int)'A');
		std::cout << " <- " << (char)(source + (int)'A') << std::endl;
	}
	return 0;
}