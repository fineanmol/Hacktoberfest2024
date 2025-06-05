class Solution {
public:
    // // Approach - 1 - From Longest Increasing Subsequence (TLE)
    // bool increasingTriplet(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n < 3) return false;

    //     vector<int> dp(n, 1);

    //     for (int i = 1; i < n; ++i) {
    //         for (int j = 0; j < i; ++j) {
    //             if (nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //                 if (dp[i] >= 3) return true;
    //             }
    //         }
    //     }

    //     return false;
    // }
    // // Approach - 2
    // /* Intution:
    // We need not find a triplet such that a[i] < a[j] < a[k]. We could just find two smaller numbers
    // such that a[i] < a[j] and a[j] < a[k]. If we get a number greater than these two, triplet subsequence is found 
    // */
    bool increasingTriplet(vector<int>& nums) {
        int firstSmallest = INT_MAX, secondSmallest = INT_MAX;

        for(auto &num : nums){
            if(num <= firstSmallest)
                firstSmallest = num;
            else if(num <= secondSmallest)
                secondSmallest = num;
            else 
                return true;
        }

        return false;
    }
};