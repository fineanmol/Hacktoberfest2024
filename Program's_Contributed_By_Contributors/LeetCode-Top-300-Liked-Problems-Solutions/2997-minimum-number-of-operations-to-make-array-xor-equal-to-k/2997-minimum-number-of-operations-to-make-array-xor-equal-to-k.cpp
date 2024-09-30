class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for (int n : nums) {
            finalXor = finalXor ^ n;
        }
        
        return __builtin_popcount(finalXor ^ k);
    }
};