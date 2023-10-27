// Equilibrium Point
// Find an equilibrium point such that sum of elements before it is equal to sum of elements after it.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
         cin>>v[i];

    int sum = accumulate(v.begin(), v.end(), 0);
    int left = 0;
    for(int i = 0; i < n; i++)
    {
        if(left == sum - v[i])
        {
            cout<<i<<" ";
            break;
        }
        left += v[i];
        sum-=v[i];
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
