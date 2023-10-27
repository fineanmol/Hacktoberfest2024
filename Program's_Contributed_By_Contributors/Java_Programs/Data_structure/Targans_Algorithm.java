import java.io.*; 
import java.util.*; 

class Graph{ 

private int V; 

private LinkedList<Integer> adj[]; 
private int Time; 

@SuppressWarnings("unchecked") 
Graph(int v) 
{ 
	V = v; 
	adj = new LinkedList[v]; 
	
	for(int i = 0; i < v; ++i) 
		adj[i] = new LinkedList(); 
		
	Time = 0; 
} 

void addEdge(int v,int w) 
{ 
	adj[v].add(w); 
} 

void SCCUtil(int u, int low[], int disc[], boolean stackMember[], Stack<Integer> st) 
{ 
	disc[u] = Time; 
	low[u] = Time; 
	Time += 1; 
	stackMember[u] = true; 
	st.push(u); 

	int n; 
	
	Iterator<Integer> i = adj[u].iterator(); 
	
	while (i.hasNext()) 
	{ 
		n = i.next(); 
		
		if (disc[n] == -1) 
		{ 
			SCCUtil(n, low, disc, stackMember, st); 
			
		
			low[u] = Math.min(low[u], low[n]); 
		} 
		else if (stackMember[n] == true) 
		{ 
	
			low[u] = Math.min(low[u], disc[n]); 
		} 
	} 

	int w = -1; 
	if (low[u] == disc[u]) 
	{ 
		while (w != u) 
		{ 
			w = (int)st.pop(); 
			System.out.print(w + " "); 
			stackMember[w] = false; 
		} 
		System.out.println(); 
	} 
} 

void SCC() 
{ 
	
	int disc[] = new int[V]; 
	int low[] = new int[V]; 
	for(int i = 0;i < V; i++) 
	{ 
		disc[i] = -1; 
		low[i] = -1; 
	} 
	
	boolean stackMember[] = new boolean[V]; 
	Stack<Integer> st = new Stack<Integer>(); 

	for(int i = 0; i < V; i++) 
	{ 
		if (disc[i] == -1) 
			SCCUtil(i, low, disc, stackMember, st); 
	} 
} 
