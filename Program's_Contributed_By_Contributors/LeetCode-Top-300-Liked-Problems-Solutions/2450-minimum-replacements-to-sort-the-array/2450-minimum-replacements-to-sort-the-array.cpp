class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();

        // Start from the second last element, as the last one is always sorted.
        for (int i = n - 2; i >= 0; i--) {
            // No need to break if they are already in order.
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            // Count how many elements are made from breaking nums[i].
            long long numElements = ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]));

            // It requires numElements - 1 replacement operations.
            answer += numElements - 1;

            // Maximize nums[i] after replacement.
            nums[i] = nums[i] / numElements;
        }

        return answer;
    }
};