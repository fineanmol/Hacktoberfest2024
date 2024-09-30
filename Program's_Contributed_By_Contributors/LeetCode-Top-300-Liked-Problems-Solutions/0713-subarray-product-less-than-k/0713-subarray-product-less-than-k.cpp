class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int cnt = 0, prod = 1;
        int left = 0, right = 0;
        while(left <= right && right < nums.size()){
            prod = prod * nums[right];

            while(prod >= k){
                prod /= nums[left++];
            }

            cnt += (right - left + 1);
            right += 1;
        }
        return cnt;
    }
};