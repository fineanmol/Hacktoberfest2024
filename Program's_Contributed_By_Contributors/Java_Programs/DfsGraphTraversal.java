import java.util.LinkedList;
import java.util.Stack;

class DfsGraphTraversal {
    private int V; // Number of vertices
    private LinkedList<Integer> adjList[]; // Adjacency list

    public DfsGraphTraversal(int v) {
        V = v;
        adjList = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    // Add an edge to the graph
    public void addEdge(int v, int w) {
        adjList[v].add(w);
    }

    // Depth-First Search (DFS) traversal
    public void DFS(int startVertex) {
        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();

        visited[startVertex] = true;
        stack.push(startVertex);

        while (!stack.isEmpty()) {
            startVertex = stack.pop();
            System.out.print(startVertex + " ");

            for (Integer neighbor : adjList[startVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }
}

