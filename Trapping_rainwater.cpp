#include <bits/stdc++.h>
using namespace std;
#define For(j, i, f) for (int j = i; j <= f; j++)
#define ForDec(j, i, s) for (int j = i; j >= s; j--)
#define lli long long int
#define endl "\n"
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

// Optimal solution ,but with greater space complexity.
// time complexity=O(N)
// space complexity=O(N)
// For each block,the rainwater stored above it is determined by subtracting the water level above it and block height.
// Water level can be found by using higher blocks in left and right sides for each block.
int trappedRainwater(int blocks[], int n) {
  int maxLeft[n], maxRight[n];
  int maxR = 0, maxL = 0;
  int trappedWater = 0;
  For(i, 0, n - 1) {
    maxL = max(maxL, blocks[i]);
    maxLeft[i] = maxL;
  }
  ForDec(i, n - 1, 0) {
    maxR = max(maxR, blocks[i]);
    maxRight[i] = maxR;
  }
  For(i, 0, n - 1) {
    trappedWater += min(maxLeft[i], maxRight[i]) - blocks[i];
  }
  return trappedWater;
}

// 2-pointer approach
// Most optimal solution for this problem
// time complexity=O(N)
// space complexity=O(1)

int trappedRainwaterOptim(int blocks[], int n) {
  int trappedWater = 0;
  int l = 0, r = n - 1;
  int leftMax = 0, rightMax = 0;
  while (l < r) {
    leftMax = max(leftMax, blocks[l]);
    rightMax = max(rightMax, blocks[r]);
    if (leftMax < rightMax) {
      trappedWater += leftMax - blocks[l];
      l++;
    } else {
      trappedWater += rightMax - blocks[r];
      r--;
    }
  }
  return trappedWater;
}

int main() {
  int n = 7;
  int blocks[] = {4, 2, 0, 6, 2, 3, 5};
  cout << trappedRainwater(blocks, n) << endl;
  cout << trappedRainwaterOptim(blocks, n) << endl;
  return 0;
}