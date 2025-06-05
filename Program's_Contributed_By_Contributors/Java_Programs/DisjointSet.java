public class DisjointSet {
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();

    public DisjointSet(int n) {
        for (int i = 0; i <= n; i++) {
            parent.add(i);
            size.add(1);
        }
    }

    public void unionBySize(int u , int v){
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);

        if(size.get(ult_u) < size.get(ult_v)){
            parent.set(ult_u, ult_v);
            size.set(parent.get(u), size.get(ult_u) + size.get(ult_v));
        }
        else{
            parent.set(ult_v, ult_u);
            size.set(parent.get(v), size.get(ult_u) + size.get(ult_v));
        }
    }

    public int findUltParent(int node) {
        if(node == parent.get(node)) {
            return node;
        }
        int ulp = findUltParent(parent.get(node));
        parent.set(node, ulp);
        return parent.get(node);
    }
}
