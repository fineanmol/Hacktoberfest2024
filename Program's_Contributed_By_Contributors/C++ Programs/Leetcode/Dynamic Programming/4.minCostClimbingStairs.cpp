#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int step1 = 0, step2 = 0;
        for (int i = cost.size() - 1; i >= 0; i--)
        {
            int current_step = cost[i] + min(step1, step2);
            step1 = step2;
            step2 = current_step;
        }
        return min(step1, step2);
    }
};