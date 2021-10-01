/*
 *  BFS for graphs.
 */

import java.io.*; 
import java.util.*; 

class BFS 
{ 
	private int V;     // No. of vertices 
	private LinkedList<Integer> adj[];     //Adjacency Lists 

	BFS(int v) 
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	} 

	void addEdge(int v,int w) 
	{ 
		adj[v].add(w); 
	} 

	void traverse(int s) 
	{ 
		boolean visited[] = new boolean[V]; 

		LinkedList<Integer> queue = new LinkedList<Integer>(); 
		visited[s]=true; 
		queue.add(s); 

		while (queue.size() != 0) 
		{ 
			s = queue.poll(); 
			System.out.print(s+" "); 

			Iterator<Integer> i = adj[s].listIterator(); 
			while (i.hasNext()) 
			{ 
				int n = i.next(); 
				if (!visited[n]) 
				{ 
					visited[n] = true; 
					queue.add(n); 
				} 
			} 
		} 
	} 

	public static void main(String args[]) 
	{ 
	        System.out.print('\f');
	        Scanner s= new Scanner(System.in);
	        int v,n,x,y;
	        System.out.print("Enter no. of vertices: ");
	        v=s.nextInt();
	        System.out.print("Enter no. of edges: ");
	        n= s.nextInt();
		BFS g = new BFS(v); 
		
		System.out.println("Enter Edges: ");
		for(int i=0; i<n; i++)
		{
		    System.out.print("Enter x: ");
		    x=s.nextInt();
		    System.out.print("Enter y: ");
		    y=s.nextInt();
		    System.out.println();
		    g.addEdge(x,y);
		}
		System.out.print("Enter starting point: ");
		int st=s.nextInt();
		System.out.println("Following is Breadth First Traversal (starting from vertex "+st+" )"); 
		g.traverse(st); 
	} 
} 
