#include <conio.h>
#include <cstring>
#include <iostream>
using namespace std;
#define V 7
int a[V][V] = {
	{ 0, 28, 0,0, 0 ,10,0 },
	{ 28, 0, 16, 0, 0 ,0,14 },
	{ 0, 16, 0, 12, 0 ,0,0 },
	{ 0, 0, 12, 0,22 ,0,18 },
	{ 0, 0, 0, 22, 0 ,25,24 },
	{ 10, 0, 0, 0, 25,0,0 },
	{ 0, 14, 0, 18, 24 ,0,0 } };
int parent[V];

int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}
int kruskalMST(int cost[][V])
{
	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = 0, a = -1, b = -1;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				
				if (find(i) != find(j) && min == 0 && cost[i][j] != 0)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
				if (find(i) != find(j) && cost[i][j] < min && cost[i][j] != 0)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		cout << a + 1 << " - " << b + 1 << " cost: " << min << endl;
		edge_count++;
		mincost += min;
	}
	return mincost;
}
int main()
{
	int cost;
	cout << "KRUSKALS ALGORITHM" << endl;
	cost = kruskalMST(a);
	cout << endl << "cost =" << cost;
	_getch();
	return 0;
}
#include <conio.h>
#include <cstring>
#include <iostream>
#define V 7

using namespace std;
int a[V][V] = {
	{ 0, 28, 0,0, 0 ,10,0 },
	{ 28, 0, 16, 0, 0 ,0,14 },
	{ 0, 16, 0, 12, 0 ,0,0 },
	{ 0, 0, 12, 0,22 ,0,18 },
	{ 0, 0, 0, 22, 0 ,25,24 },
	{ 10, 0, 0, 0, 25,0,0 },
	{ 0, 14, 0, 18, 24 ,0,0 } };
int parent[V];

int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}
int kruskalMST(int cost[][V])
{
	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = 0, a = -1, b = -1;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				
				if (find(i) != find(j) && min == 0 && cost[i][j] != 0)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
				if (find(i) != find(j) && cost[i][j] < min && cost[i][j] != 0)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		cout << a + 1 << " - " << b + 1 << " cost: " << min << endl;
		edge_count++;
		mincost += min;
	}
	return mincost;
}
int main()
{
	int cost;
	cout << "KRUSKALS ALGORITHM" << endl;
	cost = kruskalMST(a);
	cout << endl << "cost =" << cost;
	_getch();
	return 0;
}
