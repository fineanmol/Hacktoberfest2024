import java.util.*;   
class Graph<T>   
{   
//creating an object of the Map class that stores the edges of the graph  
private Map<T, List<T> > map = new HashMap<>();   
//the method adds a new vertex to the graph  
public void addNewVertex(T s)   
{   
map.put(s, new LinkedList<T>());   
}   
//the method adds an edge between source and destination   
public void addNewEdge(T source, T destination, boolean bidirectional)   
{   
//      
if (!map.containsKey(source))   
addNewVertex(source);   
if (!map.containsKey(destination))   
addNewVertex(destination);   
map.get(source).add(destination);   
if (bidirectional == true)   
{   
map.get(destination).add(source);   
}   
}   
//the method counts the number of vertices  
public void countVertices()   
{   
System.out.println("Total number of vertices: "+ map.keySet().size());   
}   
//the method counts the number of edges  
public void countEdges(boolean bidirection)   
{   
//variable to store number of edges      
int count = 0;   
for (T v : map.keySet())   
{   
count = count + map.get(v).size();   
}   
if (bidirection == true)   
{   
count = count / 2;   
}   
System.out.println("Total number of edges: "+ count);   
}   
//checks a graph has vertex or not  
public void containsVertex(T s)   
{   
if (map.containsKey(s))   
{   
System.out.println("The graph contains "+ s + " as a vertex.");   
}   
else   
{   
System.out.println("The graph does not contain "+ s + " as a vertex.");   
}   
}   
//checks a graph has edge or not  
//where s and d are the two parameters that represent source(vertex) and destination (vertex)  
public void containsEdge(T s, T d)   
{   
if (map.get(s).contains(d))   
{   
System.out.println("The graph has an edge between "+ s + " and " + d + ".");   
}   
else   
{   
System.out.println("There is no edge between "+ s + " and " + d + ".");   
}   
}   
//prints the adjacencyS list of each vertex  
//here we have overridden the toString() method of the StringBuilder class  
@Override  
public String toString()   
{   
StringBuilder builder = new StringBuilder();   
//foreach loop that iterates over the keys  
for (T v : map.keySet())   
{   
builder.append(v.toString() + ": ");   
//foreach loop for getting the vertices  
for (T w : map.get(v))   
{   
builder.append(w.toString() + " ");   
}   
builder.append("\n");   
}   
return (builder.toString());   
}   
}   
//creating a class in which we have implemented the driver code  
public class GraphImplementation  
{   
public static void main(String args[])   
{   
//creating an object of the Graph class  
Graph graph=new Graph();  
//adding edges to the graph  
graph.addNewEdge(0, 1, true);   
graph.addNewEdge(0, 4, true);   
graph.addNewEdge(1, 2, true);   
graph.addNewEdge(1, 3, false);   
graph.addNewEdge(1, 4, true);   
graph.addNewEdge(2, 3, true);   
graph.addNewEdge(2, 4, true);   
graph.addNewEdge(3, 0, true);   
graph.addNewEdge(2, 0, true);   
//prints the adjacency matrix that represents the graph  
System.out.println("Adjacency List for the graph:\n"+ graph.toString());   
//counts the number of vertices in the graph   
graph.countVertices();   
//counts the number of edges in the graph   
graph.countEdges(true);   
//checks whether an edge is present or not between the two specified vertices  
graph.containsEdge(3, 4);   
graph.containsEdge(2, 4);   
//checks whether vertex is present or not   
graph.containsVertex(3);   
graph.containsVertex(5);   
}   
}  
