#include <bits/stdc++.h>
using namespace std;

int rankOfElement[11];
int parent[11];
int n = 10;

void makeSet(){
    for(int i = 1; i <= n; i++) {
        rankOfElement[i] = 0;
        parent[i] = i;
    }
}

int findPar(int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}

void unionOfSet(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if(rankOfElement[u] < rankOfElement[v]) {
        parent[u] = v;
    }
    else if(rankOfElement[v] < rankOfElement[u]) {
        parent[v] = u;
    }
    else {
        parent[u] = v;
        rankOfElement[v]++;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    makeSet();
    int m;
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        unionOfSet(u, v);
    }

    if(findPar(1) != findPar(4)) {
        cout << "Different component" << "\n";
    }
    else{
        cout << "1 and 4 are in same component." << "\n";
    }

    if(findPar(1) == findPar(5)){
        cout << "Same component." << "\n";
    }
    else{
        cout << "1 and 5 are in different component." << "\n";
    }
}
