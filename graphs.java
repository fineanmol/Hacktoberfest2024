package patternquestions;

import oops_java.acces.A;

import java.util.*;

public class graphs {
    static class edge{
        int src;
        int dest;
        int weight;
        public edge(int s,int d,int w){
            this.src=s;
            this.dest=d;
            this.weight=w;
        }
    }
    public static void creaategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<edge>();
        }
        graph[0].add(new edge(0,2,8));
        graph[1].add(new edge(1,2,6));
        graph[1].add(new edge(1,3,5));
        graph[2].add(new edge(2,3,4));
        graph[2].add(new edge(2,1,8));
        graph[2].add(new edge(2,0,3));
        graph[3].add(new edge(3,2,7));
        graph[3].add(new edge(3,1,9));

    }
    public static void main(String[] args){
        int V=4;

        ArrayList<edge> graph[]=new ArrayList[V];
        creaategraph(graph);
        for(int i=0;i<graph[2].size();i++){
            edge e=graph[2].get(i);
            System.out.println(e.dest+" ,"+e.weight);
        }


    }
}
//adjacent matrix if edge exist then1 else 0
//BFS Breadth first search
//got to there
//indirecct level order traversal

//create to arraylist one qeuy and other visted arraylist
//1.print(current),2.vis[curren]=t,current. node neighbor add in qey



class graphbfs {
    static class edge{
        int src;
        int dest;

        public edge(int s,int d){
            this.src=s;
            this.dest=d;
        }
    }
    public static void creaategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<edge>();
        }
        graph[0].add(new edge(0, 1));
        graph[0].add(new edge(0, 2));
        graph[1].add(new edge(1, 0));
        graph[1].add(new edge(1, 3));
        graph[2].add(new edge(2, 0));
        graph[2].add(new edge(2, 4));
        graph[3].add(new edge(3, 1));
        graph[3].add(new edge(3, 4));
        graph[3].add(new edge(3, 5));
        graph[4].add(new edge(4, 2));
        graph[4].add(new edge(4, 3));
        graph[4].add(new edge(4, 5));
        graph[5].add(new edge(5, 3));
        graph[5].add(new edge(5, 4));
        graph[5].add(new edge(5, 6));
        graph[5].add(new edge(6, 5));

    }
    public static void bfs(ArrayList<edge> graph[],int V){
        Queue<Integer> q=new LinkedList<>();
        boolean vis[]=new boolean[V];
        q.add(0);
        while (!q.isEmpty()){
            int curr=q.remove();
            if (vis[curr]==false){
                System.out.println(curr);
                vis[curr]=true;
                for(int i=0;i<graph[curr].size();i++){
                    edge e=graph[curr].get(i);
                    q.add(e.dest);
                }
            }
        }

    }
    public static void main(String[] args){
        int V=7;

        ArrayList<edge> graph[]=new ArrayList[V];
        creaategraph(graph);
        bfs(graph,V);
        System.out.println();



    }
}



//for non contionous graphy which sub entities of sub graph



class graph_distorted_bfs {
    static class edge{
        int src;
        int dest;

        public edge(int s,int d){
            this.src=s;
            this.dest=d;
        }
    }
    public static void creaategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<edge>();
        }
        graph[0].add(new edge(0, 1));
        graph[0].add(new edge(0, 2));
        graph[1].add(new edge(1, 0));
        graph[1].add(new edge(1, 3));
        graph[2].add(new edge(2, 0));
        graph[2].add(new edge(2, 4));
        graph[3].add(new edge(3, 1));
        graph[3].add(new edge(3, 4));
        graph[3].add(new edge(3, 5));
        graph[4].add(new edge(4, 2));
        graph[4].add(new edge(4, 3));
        graph[4].add(new edge(4, 5));
        graph[5].add(new edge(5, 3));
        graph[5].add(new edge(5, 4));
        graph[5].add(new edge(5, 6));
        graph[5].add(new edge(6, 5));

    }
    public static void bfs(ArrayList<edge> graph[],int V,boolean vis[],int start){
        Queue<Integer> q=new LinkedList<>();

        q.add(start);
        while (!q.isEmpty()){
            int curr=q.remove();
            if (vis[curr]==false){
                System.out.print(curr+" ");
                vis[curr]=true;
                for(int i=0;i<graph[curr].size();i++){
                    edge e=graph[curr].get(i);
                    q.add(e.dest);
                }
            }
        }

    }
    public static void main(String[] args){
        int V=7;

        ArrayList<edge> graph[]=new ArrayList[V];
        creaategraph(graph);
        boolean vis[]=new boolean[V];
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                bfs(graph,V,vis,i);
            }
        }

        System.out.println();



    }
}
//Dfs=depth  firsts search
//recursion
//
class DFS{
    static class edge{
        int src;
        int dest;

        public edge(int s, int d) {
            this.src=s;
            this.dest=d;
        }

    }
    public static void creategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,1));
        graph[0].add(new edge(0,2));
        graph[1].add(new edge(1, 0));
        graph[1].add(new edge(1, 3));
        graph[2].add(new edge(2, 0));
        graph[2].add(new edge(2, 4));
        graph[3].add(new edge(3, 1));
        graph[3].add(new edge(3, 4));
        graph[3].add(new edge(3, 5));
        graph[4].add(new edge(4, 2));
        graph[4].add(new edge(4, 3));
        graph[4].add(new edge(4, 5));
        graph[5].add(new edge(5, 3));
        graph[5].add(new edge(5, 4));
        graph[5].add(new edge(5, 6));
        graph[5].add(new edge(6, 5));


    }
    public static void DFS(ArrayList<edge> graph[],int curr,boolean vis[]){
        System.out.print(curr);
        vis[curr]=true;
        for (int i=0;i<graph[curr].size();i++){
            edge e=graph[curr].get(i);
            if(vis[e.dest]==false) {
                DFS(graph, e.dest, vis);
            }
        }

    }
    public static void main(String[] args){
        int V=7;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        boolean vis[]=new boolean[V];
        DFS(graph,0,vis);

    }
}

//ques print all points from 0 to 5  all ways
class Dfs_allpath{
    static class edge{
        int src;
        int dest;

        public edge(int s, int d) {
            this.src=s;
            this.dest=d;
        }

    }
    public static void creategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,1));
        graph[0].add(new edge(0,2));
        graph[1].add(new edge(1, 0));
        graph[1].add(new edge(1, 3));
        graph[2].add(new edge(2, 0));
        graph[2].add(new edge(2, 4));
        graph[3].add(new edge(3, 1));
        graph[3].add(new edge(3, 4));
        graph[3].add(new edge(3, 5));
        graph[4].add(new edge(4, 2));
        graph[4].add(new edge(4, 3));
        graph[4].add(new edge(4, 5));
        graph[5].add(new edge(5, 3));
        graph[5].add(new edge(5, 4));
        graph[5].add(new edge(5, 6));
        graph[5].add(new edge(6, 5));


    }
    public static void allpath(ArrayList<edge> graphs[],int curr,boolean vis[],int tar,String path){
        if(curr==tar){
            System.out.println(path);
            return;
        }

        for(int i=0;i<graphs[curr].size();i++){
            edge e=graphs[curr].get(i);
            if(!vis[e.dest]){
                vis[curr]=true;
                allpath(graphs, e.dest, vis,tar,path+ e.dest);
                vis[curr]=false;
            }
        }
    }
    public static boolean Cyclic_detection(ArrayList<edge> graphs[],int curr,boolean vis[],boolean rec[]){
        vis[curr]=true;
        rec[curr]=true;
        for(int i=0;i<graphs[curr].size();i++){
            edge e=graphs[curr].get(i);
            if(rec[e.dest]==true){
                return true;
            } else if (!vis[e.dest]) {
                if (Cyclic_detection(graphs,e.dest,vis,rec)){
                    return true;
                }


            }

        }
        rec[curr]=false;
        return false;
    }

    public static void main(String[] args){
        int V=7;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        int src=0;
        int tar=5;
        boolean vis[]=new boolean[V];
        boolean rec[]=new boolean[V];
        for(int i=0;i<V;i++){
            if(!vis[i]){
                boolean iscycle =Cyclic_detection(graph,0,vis,rec);
                if(iscycle){
                    System.out.println(iscycle);
                    break;
                }

            }
        }
//        allpath(graph,src,new boolean[V],tar,"0");
    }
}
//topological sorting can be perform only for DAG Directed acyclic graphs

class topology_sort{
    public static class edge{
        int src;
        int dest;
        public edge(int s,int d){
            this.src=s;
            this.dest=d;
        }
    }
    public static void creategraph(ArrayList<edge>[] graph){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<edge>();
        }
        graph[2].add(new edge(2,3));
        graph[2].add(new edge(3,1));
        graph[2].add(new edge(4,0));
        graph[2].add(new edge(5,0));
        graph[2].add(new edge(5,2));

    }
    public static void topsortutil(ArrayList<edge> graph[], int curr, boolean vis[], Stack<Integer> stack){
        vis[curr]=true;
        for (int i=0;i<graph[curr].size();i++){
            edge e= graph[curr].get(i);
            if(!vis[e.dest]){
                topsortutil(graph,e.dest,vis,stack);
            }
        }
        stack.push(curr);
    }
    public static void topSort(ArrayList<edge> graph[],int V){
        boolean vis[]=new boolean[V];
        Stack<Integer> stack=new Stack<>();
        for (int i=0;i<V;i++){
            if(!vis[i]){
                topsortutil(graph,i,vis,stack);
            }
        }
        while(!stack.isEmpty()){
            System.out.print(stack.pop()+" ");
        }
    }
    public static boolean undirected_cyclic(ArrayList<edge> graph[],boolean vis[],int curr,int par){
        vis[curr]=true;
        for(int i=0;i<graph[curr].size();i++){
            edge e=graph[curr].get(i);
            if(vis[e.dest] && par!= e.dest){
                return true;
            }
            else if(!vis[e.dest]){
                if(undirected_cyclic(graph,vis,e.dest,curr)){
                    return true;
                }
            }

        }
        return false;
    }
    public static void main(String[] args){
        int V=6;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
//        topSort(graph,V);
        System.out.println(undirected_cyclic(graph,new boolean[V],0,-1));
    }

}



//Shortest path algorithm
//Dijstra's Algorithm'
class Dijstras_algo{
    public static class edge{
        int src;
        int dest;
        int wt;
        public  edge(int s,int d,int w){
            this.src=s;
            this.dest=d;
            this.wt=w;
        }
    }
    public static void creategraph(ArrayList<edge> graph[]){
        for (int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<edge>();
        }
        graph[0].add(new edge(0,1,2));
        graph[0].add(new edge(0,2,4));
        graph[2].add(new edge(1,3,7));
        graph[2].add(new edge(1,2,1));
        graph[3].add(new edge(2,4,3));
        graph[3].add(new edge(2,5,1));
        graph[4].add(new edge(4,3,2));
        graph[4].add(new edge(4,5,5));

    }
    public static class Pair implements Comparable<Pair>{
        int node;
        int dist;
        public Pair(int n,int d){
            this.dist=d;
            this.node=n;
        }

        @Override
        public int compareTo(Pair p2) {
            return this.dist-p2.dist;
//            for ascending
//            return p2.dist-this.dist for descending
        }
    }
    public static void djistra_algo(ArrayList<edge> graph[],int V,int src){
        PriorityQueue<Pair> pq=new PriorityQueue<>();
        int dist[]=new int[V];
        for (int i=0;i<V;i++){
            if(i !=src){
                dist[i]=Integer.MAX_VALUE;
            }
        }
        boolean vis[]=new boolean[V];
        pq.add(new Pair(0,0));
        while(!pq.isEmpty()){
            Pair curr=pq.remove();
            if(!vis[curr.node]){
                vis[curr.node]=true;
                for(int i=0;i<graph[curr.node].size();i++){
                    edge e=graph[curr.node].get(i);
                    int u=e.src;
                    int v=e.src;
                    if(dist[u]+e.wt<dist[v]){
                        dist[v]=dist[u]+e.wt;
                        pq.add(new Pair(v,dist[v]));
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            System.out.print(dist[i]+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        int V=6;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        djistra_algo(graph,V,0);
    }

}


class Dijkstras {
    static class Edge {int src;
        int dest;
        int wt;
        public Edge(int s, int d, int w) {
            this.src = s;
            this.dest = d;
            this.wt = w;
        }
    }
    static void createGraph(ArrayList<Edge> graph[]) {
        for(int i=0; i<graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));
        graph[1].add(new Edge(1, 3, 7));
        graph[1].add(new Edge(1, 2, 1));
        graph[2].add(new Edge(2, 4, 3));
        graph[3].add(new Edge(3, 5, 1));
        graph[4].add(new Edge(4, 3, 2));
        graph[4].add(new Edge(4, 5, 5));
    }
    static class Pair implements Comparable<Pair> {
        int n;
        int path;
        public Pair(int n, int path) {
            this.n = n;
            this.path = path;
        }
        @Override
        public int compareTo(Pair p2) {
            return this.path - p2.path;
        }
    }public static int[] dijkstra(ArrayList<Edge> graph[], int src) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int dist[] = new int[graph.length];
        boolean vis[] = new boolean[graph.length];
        for(int i=0; i<dist.length; i++) {
            if(i != src) {
                dist[i] = Integer.MAX_VALUE;
            }
        }
        pq.add(new Pair(src, 0));
        while(!pq.isEmpty()) {
            Pair curr = pq.remove();
            if(!vis[curr.n]) {
                vis[curr.n] = true;
                for(int i=0; i<graph[curr.n].size(); i++) {
                    Edge e = graph[curr.n].get(i);
                    int u = e.src;
                    int v = e.dest;
                    if(!vis[v] && dist[u]+e.wt < dist[v]) {
                        dist[v] = dist[u] + e.wt;
                        pq.add(new Pair(v, dist[v]));
                    }
                }
            }
        }
        return dist;
    }
    public static void main(String args[]) {
        int V = 6;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        int src = 0;
        int dist[] = dijkstra(graph, src);
        for(int i=0; i<dist.length; i++) {
            System.out.print(dist[i]+" ");
        }
    }
}
class bellman_ford_algo{
    static class edge {
        int src;
        int dest;
        int wt;

        public edge(int s, int d, int w) {
            this.src = s;
            this.dest = d;
            this.wt = w;
        }
    }
    public static void creategraph(ArrayList<edge> graph[]){
        for (int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,1,2));
        graph[0].add(new edge(0,2,4));
        graph[1].add(new edge(1,2,-4));
        graph[2].add(new edge(2,3,2));
        graph[3].add(new edge(3,4,4));
        graph[4].add(new edge(4,1,-1));

    }
    public static void bellmanFord(ArrayList<edge> graph[],int src,int V){
        int dist[]=new int[V];
        for(int i=0;i<V;i++){
            if(i!=src){
                dist[i]=Integer.MAX_VALUE;
            }
        }
        for(int k=0;k<V-1;k++){
            for (int i=0;i<V;i++){
                for(int j=0;j<graph[i].size();j++){
                    edge e=graph[i].get(j);
                    int u=e.src;
                    int v=e.dest;
                    if(dist[u]!=Integer.MAX_VALUE && dist[u]+e.wt<dist[v]){
                        dist[v]=dist[u]+e.wt;
                    }
                }
            }
        }
        for(int i=0;i<dist.length;i++){
            System.out.print(dist[i]+" ");
        }
        System.out.println();
    }


    public static void main(String[] args){
        int V=5;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        bellmanFord(graph,0,V);
    }
}
class prims{
    public static class edge{
        int src;
        int dest;
        int wt;
        public edge(int s, int d, int w){
            this.src=s;
            this.dest=d;
            this.wt=w;
        }
    }
    public static void creategraph(ArrayList<edge> graph[]){
        for (int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,1,10));
        graph[0].add(new edge(0,2,15));
        graph[0].add(new edge(1,3,30));

        graph[1].add(new edge(1,0,10));
        graph[1].add(new edge(1,3,40));

        graph[2].add(new edge(2,0,15));
        graph[2].add(new edge(2,3,50));

        graph[3].add(new edge(3,1,40));
        graph[3].add(new edge(3,2,50));
    }
    public static class Pair implements Comparable<Pair> {
        int node;
        int cost;
        public Pair(int n,int c){
            this.cost=c;
            this.node=n;
        }
        @Override
        public int compareTo(Pair p2){
            return this.cost-p2.cost;
        }
    }
    public static void prims(ArrayList<edge> graph[],int V){
        PriorityQueue<Pair> pq=new PriorityQueue<Pair>();
        boolean vis[]=new boolean[V];
        pq.add(new Pair(0,0));
        int mscostt=0;
        while(!pq.isEmpty()){
            Pair curr=pq.remove();
            if(!vis[curr.node]){
                vis[curr.node]=true;
                mscostt += curr.cost;
                for(int i=0;i<graph[curr.node].size();i++){
                   edge e=graph[curr.node].get(i);
                   if(!vis[e.dest]){
                       pq.add(new Pair(e.dest, e.wt));
                   }
                }
            }
        }
        System.out.print("min cost of mst ="+mscostt);
    }
    public static void main(String[] args){
        int V=4;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        prims(graph,V);
    }
}

class kosaraju_algo{
    static class edge{
        int src;
        int dest;
        public edge(int s,int d){
            this.src=s;
            this.dest=d;
        }
    }
    public static void creategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,2));
        graph[0].add(new edge(0,3));
        graph[1].add(new edge(1,0));
        graph[2].add(new edge(2,1));
        graph[3].add(new edge(3,4));

    }
    public static void topSort(ArrayList<edge> graph[],int curr,boolean vis[],Stack<Integer> s){
        vis[curr]=true;
        for(int i=0;i<graph[curr].size();i++){
            edge e=graph[curr].get(i);
            if(!vis[e.dest]){
                topSort(graph, e.dest, vis,s);
            }
        }
        s.push(curr);
    }
    public static void dfs(ArrayList<edge> graph[],int curr,boolean vis[]){
        vis[curr]=true;
        System.out.print(curr+" ");
        for(int i=0;i<graph[curr].size();i++){
            edge e= graph[curr].get(i);
            if(!vis[e.dest]){
                dfs(graph,e.dest,vis);
            }
        }
    }
    public static void kosaraju(ArrayList<edge> graph[],int V){
//       step1
        Stack<Integer> s=new Stack<>();
        boolean vis[]=new boolean[V];
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topSort(graph,i,vis,s);
            }
        }

//        step2
        ArrayList<edge> transpose[]=new ArrayList[V];
        for(int i=0;i<transpose.length;i++){
            vis[i]=false;
            transpose[i]=new ArrayList<>();

        }
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                edge e=graph[i].get(j);
//                e.src-->e.dest
                transpose[e.dest].add(new edge(e.dest,e.src));
            }
        }
//        step3
        while(!s.isEmpty()){
            int curr=s.pop();
            if(!vis[curr]){
                dfs(transpose,curr,vis);
                System.out.println();
            }

        }

    }
    public static void main(String[] args){
        int V=5;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        kosaraju(graph,V);
    }
}

//bridges in graphs
// tarjan's algorithm
class Bridges{
    static class edge{
        int src;
        int dest;
        public edge(int s,int d){
            this.src=s;
            this.dest=d;
        }

    }
    public static void creategraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,1));
        graph[0].add(new edge(0,2));
        graph[0].add(new edge(0,3));

        graph[1].add(new edge(1,0));
        graph[1].add(new edge(1,2));

        graph[2].add(new edge(2,0));
        graph[2].add(new edge(2,1));

        graph[3].add(new edge(3,0));
        graph[3].add(new edge(3,4));
        graph[3].add(new edge(3,5));

        graph[4].add(new edge(4,3));
        graph[4].add(new edge(4,5));

        graph[5].add(new edge(5,3));
        graph[5].add(new edge(5,4));

    }
    public static void dfs(ArrayList<edge>graph[],int curr,boolean vis[],int dt[],int low[],int time,int par){
        vis[curr]=true;
        dt[curr]=low[curr]=++time;
        for(int i=0;i<graph[curr].size();i++){
            edge e=graph[curr].get(i);
            if(e.dest==par){
                continue;

            }
            else if(!vis[e.dest]){
                dfs(graph,e.dest,vis,dt,low,time,curr);
                low[curr]=Math.min(low[curr],low[e.dest]);
                if(dt[curr]<low[e.dest]){
                    System.out.println("bridge is :"+curr+"--->"+e.dest);
                }
            }
            else{
                low[curr]=Math.min(low[curr],low[e.dest]);

            }
        }
    }
    public static void getbridge(ArrayList<edge> graph[],int V){
        int dt[]=new int[V];
        int low[]=new int[V];
        int time=0;
        boolean vis[]=new boolean[V];
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(graph,i,vis,dt,low,time,-1);
            }
        }
    }
    public static void main(String[] args){
        int V=6;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        getbridge(graph,V);
    }
}

class point_auto {
    static class edge {
        int src;
        int dest;

        public edge(int s, int d) {
            this.src = s;
            this.dest = d;
        }
    }
    public static void creategraph(ArrayList<edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();

        }
        graph[0].add(new edge(0,1));
        graph[0].add(new edge(0,2));
        graph[0].add(new edge(0,3));

        graph[1].add(new edge(1,0));
        graph[1].add(new edge(1,2));

        graph[2].add((new edge(2,0)));
        graph[2].add((new edge(2,1)));

        graph[3].add(new edge(3,0));
        graph[3].add(new edge(3,4));

        graph[4].add((new edge(4,3)));

    }
    public static void dfs(ArrayList<edge> graph[],int curr,int par,int dt[],int low[],boolean vis[],int time,boolean ap[]){
        vis[curr]=true;
        dt[curr]=low[curr]=++time;
        int children=0;
        for(int i=0;i<graph[curr].size();i++){
            edge e=graph[curr].get(i);
            int neigh=e.dest;
            if(par==neigh){
                continue;
            }
            else if(vis[neigh]){
                low[curr]=Math.min(low[curr],dt[neigh]);

            }
            else{
                dfs(graph,neigh,curr,dt,low,vis,time,ap);
                low[curr]=Math.min(low[curr],low[neigh]);
                if(dt[curr]<=low[neigh] && par != -1){
                    ap[curr]=true;
                }
                children++;
            }
        }
        if (par==-1 && children >1){
            ap[curr]=true;
        }
    }
    public static void getAP(ArrayList<edge> graph[],int V){
        int dt[]=new int[V];
        int low[]=new int[V];
        boolean vis[]=new boolean[V];
        int time=0;
        boolean ap[]=new boolean[V];
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(graph,i,-1,dt,low,vis,time,ap);
            }
        }
        for(int i=0;i<V;i++){
            if(ap[i]){
                System.out.println("AP : "+i);
            }
        }
    }
    public static void main(String[] args){
        int V=5;
        ArrayList<edge> graph[]=new ArrayList[V];
        creategraph(graph);
        getAP(graph,V);

    }
//    o(v+e)
}

