import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

class Entry implements Comparable<Entry> {
    int x;
    int y;
    int val;
    public Entry(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }
    public int compareTo(Entry other) {
        return val - other.val;
    }
}

public class Solution {

static int[][] buildSparseTable(int[] arr) {
        int pow = 1;
        while ((1 << pow) < arr.length) pow++;
        int[][] result = new int[arr.length][pow];
        for (int i = 0; i < arr.length; i++) result[i][0] = arr[i];
        for (int j = 1; j <= pow; j++) {
            for (int i = 0; i + (1 << j) <= arr.length; i++) {
                result[i][j] = Math.min(result[i][j-1],
                                        result[i + (1 << (j-1))][j-1]);
            }
        }
        return result;
    }    /*
     * Complete the treeCoordinates function below.
     */
static int treeCoordinates(int n, int[][] edges, int[][] points) {
        ArrayList<Integer>[] nodes = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) nodes[i] = new ArrayList<Integer>();
        for (int[] edge : edges) {
            nodes[edge[0]].add(edge[1]);
            nodes[edge[1]].add(edge[0]);
        }

        // Find diameter (two BFS)
        int root = 0;
        int tail = 0;
        {
            class Entry {
                int node;
                int dist;
                public Entry(int node, int dist) {
                    this.node = node;
                    this.dist = dist;
                }
            }
            LinkedList<Entry> Q = new LinkedList<Entry>();
            boolean[] visited = new boolean[n + 1];
            visited[1] = true;
            Q.offer(new Entry(1, 0));
            int maxDist = 0;
            int farNode = 1;
            while (Q.size() > 0) {
                Entry cur = Q.poll();
                if (cur.dist > maxDist) {
                    maxDist = cur.dist;
                    farNode = cur.node;
                }
                for (int neighbor : nodes[cur.node]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    Q.offer(new Entry(neighbor, cur.dist + 1));
                }
            }
            root = farNode;
            
            Q = new LinkedList<Entry>();
            visited = new boolean[n + 1];
            visited[root] = true;
            Q.offer(new Entry(root, 0));
            maxDist = 0;
            farNode = root;
            while (Q.size() > 0) {
                Entry cur = Q.poll();
                if (cur.dist > maxDist) {
                    maxDist = cur.dist;
                    farNode = cur.node;
                }
                for (int neighbor : nodes[cur.node]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    Q.offer(new Entry(neighbor, cur.dist + 1));
                }
            }
            tail = farNode;
        }
        //System.out.println("root = " + root + ", tail = " + tail);

        // Euler tour
        int[] eulerTour = new int[2*n - 1];
        final int[] depth = new int[n + 1];
        int[] eulerLevels = new int[2*n - 1];
        int[] eulerIndex = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        
        int[] S = new int[n];
        int spos = 0;
        S[0] = root;
        int pos = 0;
        int[] neighborCount = new int[n + 1];
        while (spos > -1) {
            int cur = S[spos--];
            if (!visited[cur]) {
                depth[cur] = spos + 1;
                eulerIndex[cur] = pos;
                visited[cur] = true;
            }
            eulerLevels[pos] = spos + 1;
            eulerTour[pos] = cur;
            pos++;
            while (neighborCount[cur] < nodes[cur].size()) {
                if (visited[nodes[cur].get(neighborCount[cur])]) {
                    neighborCount[cur]++;
                    continue;
                }
                int next = nodes[cur].get(neighborCount[cur]);
                //parent[next] = cur;
                S[++spos] = cur;
                S[++spos] = next;
                neighborCount[cur]++;
                break;
            }
        }

        int[][] lookup = buildSparseTable(eulerLevels);

        List<Entry> list1 = new ArrayList<Entry>(points.length);
        List<Entry> list2 = new ArrayList<Entry>(points.length);
        List<Entry> list3 = new ArrayList<Entry>(points.length);
        List<Entry> list4 = new ArrayList<Entry>(points.length);

        for (int i = 0; i < points.length; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int xLcaLevel;
            {
                int start = Math.min(eulerIndex[x], eulerIndex[tail]);
                int end = Math.max(eulerIndex[x], eulerIndex[tail]);
                int pow = 0;
                while (1 << (pow + 1) <= (end - start)) pow++;
                xLcaLevel = Math.min(lookup[start][pow],   
                                     lookup[end + 1 - (1<<pow)][pow]);
            }
            int yLcaLevel;
            {
                int start = Math.min(eulerIndex[y], eulerIndex[tail]);
                int end = Math.max(eulerIndex[y], eulerIndex[tail]);
                int pow = 0;
                while (1 << (pow + 1) <= (end - start)) pow++;
                yLcaLevel = Math.min(lookup[start][pow],   
                                     lookup[end + 1 - (1<<pow)][pow]);
            }
            int val1 = depth[x] + depth[y];
            list1.add(new Entry(x, y, val1));
            int val2 = -depth[x] - depth[y] + 2*xLcaLevel + 2*yLcaLevel;
            list2.add(new Entry(x, y, val2));
            int val3 = depth[x] + depth[y] - 2*xLcaLevel;
            list3.add(new Entry(x, y, val3));
            int val4 = -depth[x] - depth[y] + 2*yLcaLevel;
            list4.add(new Entry(x, y, val4));
        }
        Collections.sort(list1, Collections.reverseOrder());
        Collections.sort(list2);
        Collections.sort(list3, Collections.reverseOrder());
        Collections.sort(list4);

        int maxDist = 0;

        for (int i = 0; i < points.length; i++) {
            boolean shouldContinue = false;
            for (int j = 0; j <= i; j++) {
                Entry e1 = list1.get(i-j);
                Entry e2 = list2.get(j);
                int potential12 = e1.val - e2.val;
                if (potential12 > maxDist) {
                    shouldContinue = true;
                    int x1 = e1.x;
                    int y1 = e1.y;
                    int x2 = e2.x;
                    int y2 = e2.y;
                    int xLcaLevel;
                    {
                        int start = Math.min(eulerIndex[x1], eulerIndex[x2]);
                        int end = Math.max(eulerIndex[x1], eulerIndex[x2]);
                        int pow = 0;
                        while (1 << (pow + 1) <= (end - start)) pow++;
                        xLcaLevel = Math.min(lookup[start][pow],   
                                             lookup[end + 1 - (1<<pow)][pow]);
                    }
                    int yLcaLevel;
                    {
                        int start = Math.min(eulerIndex[y1], eulerIndex[y2]);
                        int end = Math.max(eulerIndex[y1], eulerIndex[y2]);
                        int pow = 0;
                        while (1 << (pow + 1) <= (end - start)) pow++;
                        yLcaLevel = Math.min(lookup[start][pow],   
                                             lookup[end + 1 - (1<<pow)][pow]);
                    }
                    int actual12 = depth[x1] + depth[x2] - 2*xLcaLevel
                                   + depth[y1] + depth[y2] - 2*yLcaLevel;
                    maxDist = Math.max(maxDist, actual12);
                }
                Entry e3 = list3.get(i-j);
                Entry e4 = list4.get(j);
                int potential34 = e3.val - e4.val;
                if (potential34 > maxDist) {
                    shouldContinue = true;
                    int x3 = e3.x;
                    int y3 = e3.y;
                    int x4 = e4.x;
                    int y4 = e4.y;
                    int xLcaLevel;
                    {
                        int start = Math.min(eulerIndex[x3], eulerIndex[x4]);
                        int end = Math.max(eulerIndex[x3], eulerIndex[x4]);
                        int pow = 0;
                        while (1 << (pow + 1) <= (end - start)) pow++;
                        xLcaLevel = Math.min(lookup[start][pow],   
                                             lookup[end + 1 - (1<<pow)][pow]);
                    }
                    int yLcaLevel;
                    {
                        int start = Math.min(eulerIndex[y3], eulerIndex[y4]);
                        int end = Math.max(eulerIndex[y3], eulerIndex[y4]);
                        int pow = 0;
                        while (1 << (pow + 1) <= (end - start)) pow++;
                        yLcaLevel = Math.min(lookup[start][pow],   
                                             lookup[end + 1 - (1<<pow)][pow]);
                    }
                    int actual34 = depth[x3] + depth[x4] - 2*xLcaLevel
                                   + depth[y3] + depth[y4] - 2*yLcaLevel;
                    maxDist = Math.max(maxDist, actual34);
                }
            }
            if (!shouldContinue) break;
        }

        return maxDist;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0].trim());

        int m = Integer.parseInt(nm[1].trim());

        int[][] edges = new int[n-1][2];

        for (int edgesRowItr = 0; edgesRowItr < n-1; edgesRowItr++) {
            String[] edgesRowItems = scanner.nextLine().split(" ");

            for (int edgesColumnItr = 0; edgesColumnItr < 2; edgesColumnItr++) {
                int edgesItem = Integer.parseInt(edgesRowItems[edgesColumnItr].trim());
                edges[edgesRowItr][edgesColumnItr] = edgesItem;
            }
        }

        int[][] points = new int[m][2];

        for (int pointsRowItr = 0; pointsRowItr < m; pointsRowItr++) {
            String[] pointsRowItems = scanner.nextLine().split(" ");

            for (int pointsColumnItr = 0; pointsColumnItr < 2; pointsColumnItr++) {
                int pointsItem = Integer.parseInt(pointsRowItems[pointsColumnItr].trim());
                points[pointsRowItr][pointsColumnItr] = pointsItem;
            }
        }

        int result = treeCoordinates(n, edges, points);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
