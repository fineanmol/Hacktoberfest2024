#include<bits/stdc++.h>
using namespace std;

int first_occurrence(vector<int> &a, int x) {

    int lo=-1, hi=a.size(), ans=-1;
    while(hi-lo>1) {
        int mid = lo + (hi-lo) / 2;
        // if(a[mid] == x) ans = mid+1;
        if(x <= a[mid]) {
            hi = mid; 
            if(a[mid]==x) ans = mid+1;
        }
        else lo = mid;
    }
    return ans;
}

int last_occurrence(vector<int> &a, int x) {

    int lo=-1, hi=a.size(), ans=-1;
    while(hi-lo>1) {
        int mid = lo + (hi-lo) / 2;
        // if(a[mid] == x) ans = mid+1;
        if(x >= a[mid]) {
            lo = mid; 
            if(a[mid]==x) ans = mid+1;
        }
        else hi = mid;
    }
    return ans;
}

void SHINE() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int f = first_occurrence(a, k);
    int l = last_occurrence(a, k);
    cout << "count: " << l-f+1 << "\n";
}

int main() {
    SHINE();
    return 0;
}