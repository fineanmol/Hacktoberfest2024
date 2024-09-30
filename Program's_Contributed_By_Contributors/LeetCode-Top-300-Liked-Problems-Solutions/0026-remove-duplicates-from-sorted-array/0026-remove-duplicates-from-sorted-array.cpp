class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] != nums[i]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};