class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int positiveElementIndex = 0, negativeElementIndex = 1;

        for(auto num : nums)
        {
            if(num > 0){
                ans[positiveElementIndex] = num;
                positiveElementIndex += 2;
            }
            else{
                ans[negativeElementIndex] = num;
                negativeElementIndex += 2;
            }
        }
        return ans;
    }
};