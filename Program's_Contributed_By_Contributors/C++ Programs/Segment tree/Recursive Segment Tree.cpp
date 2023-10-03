#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

class SegTree {
public:
    vector<long long> st;
    long long ID = 0; // change this
    int n = 0;
    SegTree(int s) {
        n = s;
        st.assign(4*n+5, ID);
    }

    void merge(long long& curr, long long& a, long long& b) { // change this
        curr = a + b;
    }

    void Build(int node, int L, int R, vector<long long>& arr) {
        if(L==R) {
            st[node] = arr[L];
            return;
        }
        int M = (L + R) / 2;
        Build(2*node, L, M, arr);
        Build(2*node+1, M+1, R, arr);
        merge(st[node], st[2*node], st[2*node+1]);
    }

    void pUpdate(int node, int L, int R, int pos, long long val) {
        if(L==R) {
            st[node] = val;
            return;
        }
        int M = (L + R) / 2;
        if(pos<=M) {
            pUpdate(2*node, L, M, pos, val);
        }
        else {
            pUpdate(2*node+1, M+1, R, pos, val);
        }
        merge(st[node], st[2*node], st[2*node+1]);
    }

    long long Query(int node, int L, int R, int lo, int hi) {
        if(R<lo || L>hi) {
            return ID;
        }
        if(lo<=L && R<=hi) {
            return st[node];
        }
        int M = (L + R) / 2;
        long long lft = Query(2*node, L, M, lo, hi);
        long long rght = Query(2*node+1, M+1, R, lo, hi);
        long long curr = ID;
        merge(curr, lft, rght);
        return curr;
    }

    long long pQuery(int node, int L, int R, int pos) {
        if(L==R) {
            return st[node];
        }
        int M = (L + R) / 2;
        if(pos<=M) {
            return pQuery(2*node, L, M, pos);
        }
        else {
            return pQuery(2*node+1, M+1, R, pos);
        }
    }

    void build(vector<long long>& arr) {
        Build(1, 1, n, arr);
    }

    void update(int pos, long long val) {
        pUpdate(1, 1, n, pos, val);
    }

    long long query(int lo, int hi) {
        return Query(1, 1, n, lo, hi);
    }

    long long query(int pos) {
        return pQuery(1, 1, n, pos);
    }
};