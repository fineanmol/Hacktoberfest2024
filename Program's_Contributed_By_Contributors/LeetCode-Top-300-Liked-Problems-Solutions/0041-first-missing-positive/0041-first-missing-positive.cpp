class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool contains1 = false;


        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }      
        }

        if (!contains1) return 1;

        for (int i = 0; i < n; i++) {
            int value = abs(nums[i]);
            if (value == n) {
                nums[0] = - abs(nums[0]);
            } else {
                nums[value] = - abs(nums[value]);
            }       
        }

        // First positive in nums is smallest missing positive integer
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0)
                return i;
        }

        if (nums[0] > 0) {
            return n;
        }

        return n + 1;
    }
};