/*
    Author's Name: mayuri kolhe
    Date Modified: 01-10-2022
*/
#include <bits/stdc++.h>
using namespace std;

void printCircuit(vector< vector<int> > adj)
{
	unordered_map<int,int> edge_count;

	for (int i=0; i<adj.size(); i++)
	{
		edge_count[i] = adj[i].size();
	}

	if (!adj.size())
		return; //empty graph

	stack<int> curr_path;

	vector<int> circuit;

	curr_path.push(0);
	int curr_v = 0; // Current vertex

	while (!curr_path.empty())
	{
		// If there's remaining edge
		if (edge_count[curr_v])
		{
			curr_path.push(curr_v);

			int next_v = adj[curr_v].back();

			edge_count[curr_v]--;
			adj[curr_v].pop_back();

			curr_v = next_v;
		}

		else
		{
			circuit.push_back(curr_v);

			curr_v = curr_path.top();
			curr_path.pop();
		}
	}

	for (int i=circuit.size()-1; i>=0; i--)
	{
		cout << circuit[i];
		if (i)
		cout<<" -> ";
	}
}

int main()
{
	vector< vector<int> > adj1, adj2;

	// Input Graph 1
	adj1.resize(3);

	// Build the edges
	adj1[0].push_back(1);
	adj1[1].push_back(2);
	adj1[2].push_back(0);
	printCircuit(adj1);
	cout << endl;

	adj2.resize(7);
	adj2[0].push_back(1);
	adj2[0].push_back(6);
	adj2[1].push_back(2);
	adj2[2].push_back(0);
	adj2[2].push_back(3);
	adj2[3].push_back(4);
	adj2[4].push_back(2);
	adj2[4].push_back(5);
	adj2[5].push_back(0);
	adj2[6].push_back(4);
	printCircuit(adj2);

	return 0;
}
