class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1; // It's impossible to make a sum equal to x.

        int left = 0, minOps = INT_MAX, currentSum = 0;

        for (int right = 0; right < n; right++) {
            currentSum += nums[right];

            while (currentSum > target) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == target) {
                minOps = min(minOps, n - (right - left + 1));
            }
        }

        return (minOps == INT_MAX) ? -1 : minOps;
    }
};