#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a, int x) {

    int lo=-1, hi=a.size();
    while(hi-lo>1) {
        int mid = lo + (hi-lo) / 2;
        if(a[mid] == x) return mid+1;
        else if(a[mid] > x) hi = mid;
        else lo = mid;
    }
    return -1;
}

void SHINE() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << binary_search(a, k) << "\n";
}

int main() {
    SHINE();
    return 0;
}
