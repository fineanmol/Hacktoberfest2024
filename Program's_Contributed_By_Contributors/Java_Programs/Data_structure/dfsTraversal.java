import java.util.ArrayList;

public class traversalByDfs {
    public static void main(String[] args) {
        
    }

    public void dfs (int node,boolean vis[],ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> storeDfs)
    {
        storeDfs.add(node);
        vis[node]=true;
        for (Integer it : adj.get(node)) {
            if(vis[it]==false)
            {
                dfs(it, vis, adj, storeDfs);
            }
        }
    }

    public ArrayList<Integer> dfsOfGraph(int v,ArrayList<ArrayList<Integer>> adj )
    {
        ArrayList <Integer> storeDfs = new ArrayList<>();
        boolean vis[] = new boolean[v+1];
        for(int i=1;i<=v;i++)
        {
            if(vis[i] == false)
            {
                dfs(i, vis, adj, storeDfs);
            }
        }
    }
}
