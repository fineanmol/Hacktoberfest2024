#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a, int x) {
    int n = a.size();
    int lo=0, hi=n-1;

    while(hi-lo > -1) {
        int mid = lo + (hi - lo) / 2;
        if(a[mid] == x) return mid;

        // 1st half is sorted
        if(a[lo] <= a[mid]) {
            if(a[lo] <= x && x <= a[mid]) hi = mid-1;
            else lo = mid+1;
        }
        
        // 2nd half is sorted
        else {
            if(a[mid] <= x && x <= a[hi]) lo = mid+1;
            else hi = mid-1;
        }
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