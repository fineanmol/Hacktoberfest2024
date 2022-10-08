class DSU{
    private:
    vector<int>parent,size;
    
    public:
    DSU(int n){
        for(int i = 0; i<n ;++i){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    void unionSize(int u,int v){
        int pu = parent[u];
        int pv = parent[v];
        
        if(pu==pv)return;
        
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
    
    int findPar(int node){
        if(parent[node]==node)return node;
        
        return parent[node] = findPar(parent[node]);
    }
    
};

void solve(){
    DSU dsu(n);
    
}
