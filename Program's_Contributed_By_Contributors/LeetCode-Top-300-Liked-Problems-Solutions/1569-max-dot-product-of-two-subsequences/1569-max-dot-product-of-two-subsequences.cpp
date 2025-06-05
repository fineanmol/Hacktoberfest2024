class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

        int m = nums2.size() + 1;
        vector<int> dp(m, 0);
        vector<int> prevDp(m, 0);
        
        for (int i = nums1.size() - 1; i >= 0; i--) {
            dp = vector(m, 0);
            for (int j = nums2.size() - 1; j >= 0; j--) {
                int use = nums1[i] * nums2[j] + prevDp[j + 1];
                dp[j] = max(use, max(prevDp[j], dp[j + 1]));
            }
            
            prevDp = dp;
        }
        
        return dp[0];
    }
};