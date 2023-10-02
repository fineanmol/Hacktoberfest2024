#include<bits/stdc++.h>
using namespace std;

int without_repeat(vector<int> &a) {
    int n = a.size();
    int lo=0, hi=n-1;
    while(hi-lo>-1) {
        int mid = lo + (hi-lo) / 2;
        // cout << mid << "-";
        if(a[mid-1]>a[mid] && a[mid]<a[mid+1]) return n-mid;
        if(a[lo]>a[mid]) {hi = mid-1;}
        else lo = mid+1;
    }
    return 0;
}

int with_repeat(vector<int> &a) {
    int n = a.size(), ans = 0;
    int lo=0, hi=n-1;
    while(hi-lo>-1) {
        int mid = lo + (hi-lo) / 2;
        // cout << mid << "-";
        if(a[mid-1]>a[mid] && a[mid]<=a[mid+1]) {
            ans = n-mid;
            hi = mid-1;
            continue;
        }
        if(a[mid]>a[hi]) {lo = mid+1;}
        else hi = mid-1;
    }
    return ans;
}

void SHINE() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << with_repeat(a) << "\n";
}

int main() {
    SHINE();
    return 0;
}