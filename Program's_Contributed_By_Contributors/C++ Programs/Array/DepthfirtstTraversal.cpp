// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3

// Initialize direction vectors
int dRow[] = { 0, 1, 0, -1 };
int dCol[] = { -1, 0, 1, 0 };

// Function to check if mat[row][col]
// is unvisited and lies within the
// boundary of the given matrix
bool isValid(bool vis[][COL],
			int row, int col)
{
	// If cell is out of bounds
	if (row < 0 || col < 0
		|| row >= ROW || col >= COL)
		return false;

	// If the cell is already visited
	if (vis[row][col])
		return false;

	// Otherwise, it can be visited
	return true;
}

// Function to perform DFS
// Traversal on the matrix grid[]
void DFS(int row, int col,
		int grid[][COL],
		bool vis[][COL])
{
	// Initialize a stack of pairs and
	// push the starting cell into it
	stack<pair<int, int> > st;
	st.push({ row, col });

	// Iterate until the
	// stack is not empty
	while (!st.empty()) {
		// Pop the top pair
		pair<int, int> curr = st.top();
		st.pop();
		int row = curr.first;
		int col = curr.second;

		// Check if the current popped
		// cell is a valid cell or not
		if (!isValid(vis, row, col))
			continue;

		// Mark the current
		// cell as visited
		vis[row][col] = true;

		// Print the element at
		// the current top cell
		cout << grid[row][col] << " ";

		// Push all the adjacent cells
		for (int i = 0; i < 4; i++) {
			int adjx = row + dRow[i];
			int adjy = col + dCol[i];
			st.push({ adjx, adjy });
		}
	}
}

// Driver Code
int main()
{
	int grid[ROW][COL] = { { -1, 2, 3 },
						{ 0, 9, 8 },
						{ 1, 0, 1 } };

	// Stores whether the current
	// cell is visited or not
	bool vis[ROW][COL];
	memset(vis, false, sizeof vis);

	// Function call
	DFS(0, 0, grid, vis);

	return 0;
}
