class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        ans[0] = 1;
        for(int i = 1; i < n; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
            // cout << "Left sum -> ans[" << i << "] = " << ans[i] << endl;
        }

        int right = 1;

        for(int i = n - 1; i >= 0; i--){
            ans[i] *= right;
            // cout << "ans[" << i << "] = " << ans[i] << endl;
            right *= nums[i];
            // cout << "right = " << right << endl;
        }

        // for(int n : nums){
        //     cout << n << ", ";
        // }
        
        // cout << endl;

        // for(int n : ans){
        //     cout << n << ", ";
        // }

        return ans;
    }
};