#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum time
int minimizeTime(vector<vector<int> >& graph)
{
	long long n = graph.size();

	// Create adjacency list from the given graph
	vector<vector<long long> > adj(n);

	for (int i = 0; i < n; i++) {
		for (auto j : graph[i]) {

			adj[i].push_back(j);
		}
	}

	// Final mask when all the node will be visited
	long long finalMask = (long long)(1 << n) - 1;

	// Initilize a queue for BFS which will store current
	// node id and mask of visited nodes.
	queue<pair<long long, long long> > q;

	// Initilize a visited array for keeping track
	// of all mask that are visited in the path
	vector<vector<bool> > visited(
		n, vector<bool>(finalMask + 1));

	// Push starting node for
	// all possible path with their mask
	for (int i = 0; i < n; i++) {
		q.push({ i, (long long)(1 << i) });
	}

	// For counting the minimum time
	// to visit all the nodes
	long long timeCount = 0;

	// Do while q.size > 0
	while (q.size() > 0) {
		int size = q.size();

		// Iterate over each level
		for (int i = 0; i < size; i++) {

			// Fetch and pop the current node
			auto curr = q.front();
			q.pop();

			// Check if the currrent node mask
			// is equal to finalMask
			if (curr.second == finalMask)
				return timeCount;

			// Explore all the child of current node
			for (auto child : adj[curr.first]) {

				// Make a new Mask for child
				long long newVisitedBit
					= curr.second | (1 << child);

				// If new Mask for child has
				// not been visited yet,
				// push child and new Mask in
				// the queue and mark visited
				// for child with newVisitedBit
				if (visited[child][newVisitedBit]
					== false) {

					q.push({ child, newVisitedBit });
					visited[child][newVisitedBit] = true;
				}
			}
		}

		// Increment the time Count after each level
		timeCount++;
	}

	// If all node can't be visited
	return -1;
}

// Driver code
int main()
{
	vector<vector<int> > graph = {
		{ 1, 2, 3 }, { 2, 0 }, { 0, 1 }, { 0, 4 }, { 3 }
	};

	// Function call
	int minTime = minimizeTime(graph);
	cout << minTime << endl;

	return 0;
}

