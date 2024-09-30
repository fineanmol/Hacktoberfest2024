class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 1, n = nums.size() - 1;
        while(left < right && right <= n){
            if(nums[left] == 0){
                while(nums[right] == 0 && right < n)
                    right++;
                swap(nums[left++], nums[right++]);
            }else{
                left++, right++;
            }
        }
    }
};