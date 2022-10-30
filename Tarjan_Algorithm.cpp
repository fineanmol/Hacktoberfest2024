#include<iostream>
#include <list>
#include <stack>
#define NIL -1
using namespace std;

class Graph
{
	int V;
	list<int> *adj;

	void Util(int u, int disc[], int low[],
				stack<int> *st, bool stackMember[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void Code();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


void Graph::Util(int u, int disc[], int low[], stack<int> *st,
					bool stackMember[])
{

	static int time = 0;
	disc[u] = low[u] = ++time;
	st->push(u);
	stackMember[u] = true;
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;
		if (disc[v] == -1)
		{
			Util(v, disc, low, st, stackMember);

			low[u] = min(low[u], low[v]);
    }
    
		else if (stackMember[v] == true)
			low[u] = min(low[u], disc[v]);
	}
  
  
	int w = 0;
	if (low[u] == disc[u])
	{
		while (st->top() != u)
		{
			w = (int) st->top();
			cout << w << " ";
			stackMember[w] = false;
			st->pop();
		}
		w = (int) st->top();
		cout << w << "\n";
		stackMember[w] = false;
		st->pop();
	}
}

void Graph::Code()
{
	int *disc = new int[V];
	int *low = new int[V];
	bool *stackMember = new bool[V];
	stack<int> *st = new stack<int>();

	for (int i = 0; i < V; i++)
	{
		disc[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

  
	for (int i = 0; i < V; i++)
		if (disc[i] == NIL)
			Util(i, disc, low, st, stackMember);
}

int main()
{
	cout << "\n First graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.Code();

	cout << "\n Second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.Code();

	cout << "\n Third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.Code();

	Graph g4(11);
	g4.addEdge(0,1);g4.addEdge(0,3);
	g4.addEdge(1,2);g4.addEdge(1,4);
	g4.addEdge(2,0);g4.addEdge(2,6);
	g4.addEdge(3,2);
	g5.addEdge(2,3);
	g5.addEdge(2,4);
	g5.addEdge(3,0);
	g5.addEdge(4,2);
	g5.Code();

	return 0;
}

	g4.addEdge(4,5);g4.addEdge(4,6);
	g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
	g4.addEdge(6,4);
	g4.addEdge(7,9);
	g4.addEdge(8,9);
	g4.addEdge(9,8);
	g4.Code();

	cout << "\n Fifth graph \n";
	Graph g5(5);
	g5.addEdge(0,1);
	g5.addEdge(1,2);
