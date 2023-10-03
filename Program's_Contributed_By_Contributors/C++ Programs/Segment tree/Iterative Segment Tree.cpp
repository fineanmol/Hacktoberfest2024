#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

class SegTree {
public:
    vector<long long> segs;
    long long size = 0;
    long long ID = -INF; // change this
 
    SegTree(long long sz) {
        segs.assign(2 * sz, ID);
        size = sz;  
    }   
   
    long long comb(long long a, long long b) { // change this
        return max(a, b);  
    }
 
    void upd(long long idx, long long val) {
        segs[idx += size] = val;
        for(idx >>= 1; idx; idx >>= 1) segs[idx] = comb(segs[idx<<1], segs[idx<<1 | 1]);
    }
 
    long long query(long long l, long long r) {
        long long lans = ID, rans = ID;
        for(l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lans = comb(lans, segs[l++]);
            if(r & 1) rans = comb(segs[--r], rans);
        }
        return comb(lans, rans);
    }
};