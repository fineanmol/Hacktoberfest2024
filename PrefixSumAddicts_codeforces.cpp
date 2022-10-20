// Problem: B. Prefix Sum Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define bits1 __builtin_popcountl
#define fio                        \
  ios_base::sync_with_stdio(NULL); \
  cin.tie(NULL);
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[k];
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }
    int l;

    l = (arr[0] / (n - k + 1));
    if ((arr[0] % (n - k + 1)) != 0 && arr[0] > 0) {
      l++;
    }
    int flag = 1;
    for (int i = 1; i < k; i++) {
      int a = arr[i] - arr[i - 1];
      if (a < l) {
        flag = 0;
        break;

      } else {
        l = a;
      }
    }
    if (flag) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
