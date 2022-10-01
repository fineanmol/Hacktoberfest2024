// recursive solution
class Solution
{
public:
    int solve(vector<int> &nums, int t)
    {

        if (t < 0)
            return 0;
        if (t == 0)
            return 1;

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, t - nums[i]);
        }
        return ans;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        return solve(nums, target);
    }
};

// dp memo solution
class Solution
{
public:
    int solve(vector<int> &nums, int t, vector<int> &dp)
    {

        if (t < 0)
            return 0;
        if (t == 0)
            return 1;

        if (dp[t] != -1)
            return dp[t];

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, t - nums[i], dp);
        }

        dp[t] = ans;

        return dp[t];
    }

    int combinationSum4(vector<int> &nums, int target)
    {

        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};