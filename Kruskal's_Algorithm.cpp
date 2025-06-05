#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int wt;
    node(int a, int b, int weight){
        u = a;
        v = b;
        wt = weight;
    }
};

bool comp(node a, node b){
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent){
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int> &rank){
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else if(rank[v] > rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int N = 5;
    int m = 6;
    vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	
    vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}
