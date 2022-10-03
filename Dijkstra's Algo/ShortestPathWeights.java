// Problem

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

/*
1. You are given a graph and a source vertex. The vertices represent cities and the edges represent

    distance in kms.

2. You are required to find the shortest path to each city (in terms of kms) from the source city along

    with the total distance on path from source to destinations.



Note -> For output, check the sample output and question video.
Constraints

None
Format
Input

Input has been managed for you
Output

Check the sample output
Example

Sample Input

7
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0
Sample Output

0 via 0 @ 0

1 via 01 @ 10

2 via 012 @ 20

5 via 0125 @ 25

4 via 01254 @ 28

6 via 01256 @ 28

3 via 012543 @ 30
 */
public class ShortestPathWeights {

    static class Edge {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    static class pair implements Comparable<pair>{
        int vrtx;
        String psf;
        int weight;
        pair(int v , String s , int w){
            this.vrtx = v;
            this.psf = s;
            this.weight = w;

        }
        public int compareTo(pair o1){
            return this.weight-o1.weight;
        }

    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList<>();
        }

        int edges = Integer.parseInt(br.readLine());
        for (int i = 0; i < edges; i++) {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            int wt = Integer.parseInt(parts[2]);
            graph[v1].add(new Edge(v1, v2, wt));
            graph[v2].add(new Edge(v2, v1, wt));
        }

        int src = Integer.parseInt(br.readLine());
        // write your code here

        smallPath(graph , src );

    }
    static void smallPath(ArrayList<Edge>[] graph , int src){

        boolean[] visited = new boolean[graph.length];

        PriorityQueue<pair> Q = new PriorityQueue<>();

        Q.add(new pair(src , ""+src , 0));

        while(Q.size() !=0){
            pair rn = Q.remove();

            if(!visited[rn.vrtx]){
                visited[rn.vrtx] = true;
                System.out.println(rn.vrtx+" via " + rn.psf + " @ "+rn.weight);
                for(Edge e : graph[rn.vrtx]){
                    if(!visited[e.nbr]){
                        Q.add(new pair(e.nbr , rn.psf+e.nbr , rn.weight+e.wt));
                    }
                }
            }
        }

    }
}
