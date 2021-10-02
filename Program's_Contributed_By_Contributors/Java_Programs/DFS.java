import java.io.*;
import java.util.*;

class Graph {
    private int V;
  
    private LinkedList<Integer> adj[];
  
    //Constructor
    @SuppressWarnings("unchecked") Graph(int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }
  
    //Function to add an edge into the graph
    void addEdge(int v, int w)
    {
        adj[v].add(w);
    }
  
    // A Function used by DFS
    void DFSUtil(int v, boolean visited[])
    {
        //Mark the current node as visited and print it
        visited[v] = true;
        System.out.print(v + " ");
  
        //Recur for all the vertices adjacent to this
        //Vertex
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) 
        {
            int n = i.next();
            if (!visited[n])
                DFSUtil(n, visited);
        }
    }
  
    void DFS(int v)
    {
        boolean visited[] = new boolean[V];
        DFSUtil(v, visited);
    }
  
    //Driver Code
    public static void main(String args[])
    {
        Graph g = new Graph(4);
  
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
  
        System.out.println(
            "Following is Depth First Traversal "
            + "(starting from vertex 2)");
  
        g.DFS(2);
    }
}
