class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size(), x = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int temp = nums[i] + nums[l] + nums[r];
                if (abs(temp - target) < x)
                    x = abs(temp - target), ans = temp;
                if (temp < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};