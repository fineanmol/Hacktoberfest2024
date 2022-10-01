// Java program to find the transpose of a graph
import java.util.*;
import java.lang.*;
import java.io.*;

class Graph
{
	// Total number of vertices
	private static int vertices = 5;
	
	// Find transpose of graph represented by adj
	private static ArrayList<Integer>[] adj = new ArrayList[vertices];
	
	// Store the transpose of graph represented by tr
	private static ArrayList<Integer>[] tr = new ArrayList[vertices];

	// Function to add an edge from source vertex u to
	// destination vertex v, if choice is false the edge is added
	// to adj otherwise the edge is added to tr
	public static void addedge(int u, int v, boolean choice)
	{
		if(!choice)
			adj[u].add(v);
		else
			tr[u].add(v);
	}

	// Function to print the graph representation
	public static void printGraph()
	{
		for(int i = 0; i < vertices; i++)
		{
			System.out.print(i + "--> ");
			for(int j = 0; j < tr[i].size(); j++)
				System.out.print(tr[i].get(j) + " ");
			System.out.println();
		}
	}

	// Function to print the transpose of
	// the graph represented as adj and store it in tr
	public static void getTranspose()
	{

		// Traverse the graph and for each edge u, v
		// in graph add the edge v, u in transpose
		for(int i = 0; i < vertices; i++)
			for(int j = 0; j < adj[i].size(); j++)
				addedge(adj[i].get(j), i, true);
	}

	public static void main (String[] args) throws java.lang.Exception
	{
		for(int i = 0; i < vertices; i++)
		{
			adj[i] = new ArrayList<Integer>();
			tr[i] = new ArrayList<Integer>();
		}
		addedge(0, 1, false);
		addedge(0, 4, false);
		addedge(0, 3, false);
		addedge(2, 0, false);
		addedge(3, 2, false);
		addedge(4, 1, false);
		addedge(4, 3, false);
		
		// Finding transpose of the graph
		getTranspose();
		
		// Printing the graph representation
		printGraph();
	}
}

// This code is contributed by code_freak
