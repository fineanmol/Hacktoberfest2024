import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ShortestPathDFS {
    public static List<String> findShortestPathDFS(Map<String, List<String>> graph, String start, String end) {
        List<String> shortestPath = new ArrayList<>();
        List<String> currentPath = new ArrayList<>();
        currentPath.add(start);

        findShortestPathDFSHelper(graph, start, end, currentPath, shortestPath);

        return shortestPath;
    }

    private static void findShortestPathDFSHelper(Map<String, List<String>> graph, String current, String end, List<String> currentPath, List<String> shortestPath) {
        if (current.equals(end)) {
            if (shortestPath.isEmpty() || currentPath.size() < shortestPath.size()) {
                shortestPath.clear();
                shortestPath.addAll(currentPath);
            }
        } else {
            for (String neighbor : graph.get(current)) {
                if (!currentPath.contains(neighbor)) {
                    currentPath.add(neighbor);
                    findShortestPathDFSHelper(graph, neighbor, end, currentPath, shortestPath);
                    currentPath.remove(currentPath.size() - 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", List.of("B", "D"));
        graph.put("B", List.of("A" , "D"));
        graph.put("C", List.of("A", "B", "D"));
        graph.put("D", List.of("A", "B", "C"));

        String start = "A";
        String end = "C";

        List<String> shortestPath = findShortestPathDFS(graph, start, end);

        System.out.println("Shortest Path from " + start + " to " + end + ": " + shortestPath);
    }
}
