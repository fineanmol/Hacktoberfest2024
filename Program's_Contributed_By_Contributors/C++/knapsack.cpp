//Username- kajolkhairnar
//Description- Knapsack problem is the most important problem in list of greedy approch problems.
#include <iostream>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}
int knapSack(int W, int w[], int v[], int n) {
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   return K[n][W];
}
int main() {
   cout << "Enter the number of items in a Knapsack:";
   int n, W;
   cin >> n;
   int v[n], w[n];
   for (int i = 0; i < n; i++) {
      cout << "Enter value and weight for item " << i << ":";
      cin >> v[i];
      cin >> w[i];
   }
   cout << "Enter the capacity of knapsack";
   cin >> W;
   cout << knapSack(W, w, v, n);
   return 0;
}
