#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> memo(MAX, vector<int> (MAX, -1));
int solveEggDrop(int n, int k) {

    if(memo[n][k] != -1) { return memo[n][k];}

    if (k == 1 || k == 0)
      return k;

    if (n == 1)
      return k;

    int min = INT_MAX, x, res;

    for (x = 1; x <= k; x++) {
      res = max(
        solveEggDrop(n - 1, x - 1),
        solveEggDrop(n, k - x));
      if (res < min)
        min = res;
    }

    memo[n][k] = min+1;
    return min + 1;
  }

int main() {

    int n = 2, k = 36;
    cout<<solveEggDrop(n, k);
    return 0;
}
