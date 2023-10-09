import java.util.ArrayList;
import java.util.List;
public class mcoloringproblem {
    

    public static boolean graphColoring(List<Integer>[] graph, int[] colors, int node, int numColors) {
        int n = graph.length;
        if (solve(node, graph, colors, n, numColors)) {
            return true;
        }
        return false;
    }

    private static boolean isSafe(int node, List<Integer>[] graph, int[] colors, int n, int color) {
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    private static boolean solve(int node, List<Integer>[] graph, int[] colors, int n, int numColors) {
        if (node == n) {
            return true;
        }

        for (int color = 1; color <= numColors; color++) {
            if (isSafe(node, graph, colors, n, color)) {
                colors[node] = color;
                if (solve(node + 1, graph, colors, n, numColors)) {
                    return true;
                }
                colors[node] = 0; // Backtrack
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int numNodes = 4, numColors = 3;
        List<Integer>[] graph = new ArrayList[numNodes];
        for (int i = 0; i < numNodes; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(1);
        graph[1].add(0);
        graph[1].add(2);
        graph[2].add(1);
        graph[2].add(3);
        graph[3].add(2);
        graph[3].add(0);
        graph[0].add(3);
        graph[0].add(2);

        int[] colors = new int[numNodes];
        boolean result = graphColoring(graph, colors, 0, numColors);
        if (result) {
            System.out.println("Graph can be colored with " + numColors + " colors.");
        } else {
            System.out.println("Graph cannot be colored with " + numColors + " colors.");
        }
    }

}
