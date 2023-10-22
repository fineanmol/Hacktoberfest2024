#include <bits/stdc++.h>
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      int way1 = nums[i] + dp[i + 2];
      int way2 = dp[i + 1];
      dp[i] = max(way1, way2);
    }
    return dp[0];
  }
};
