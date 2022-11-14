class RemoveCycleGraph
{
    private int V;
    private LinkedList<Integer> adj[];
    int time = 0;
    static final int NIL = -1;
 
    RemoveCycleGraph(int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
            adj[i] = new LinkedList();
    }
 
    void addEdge(int v, int w)
    {
        adj[v].add(w);
        adj[w].add(v);
    }
 
    Boolean isBipartite(int u, int colorArr[])
    {
        colorArr[u] = 1;
 
        for (Integer v: adj[u])
        {
            if (colorArr[v]==NIL)
            {
                colorArr[v] = 1-colorArr[u];
 
                if (!isBipartite(v, colorArr))
                    return false;
