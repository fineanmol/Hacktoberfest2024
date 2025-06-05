class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        for(int i = 0; i < n; i++){
            if(leftSum == sum - nums[i])
                return i;
            leftSum += nums[i]; // including that num in leftSum
            sum -= nums[i]; // excluding that num in righSum
        }
        return -1;
    }
};