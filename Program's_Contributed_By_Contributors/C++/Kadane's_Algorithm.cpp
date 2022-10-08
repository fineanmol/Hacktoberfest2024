class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int c=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<0)
                c++;
        if(c==nums.size())
        {
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
            
        }
        
        
        int cursum=0;
        int maxsum=0;
        for(int i=0;i<nums.size();i++)
        {
            cursum=cursum+nums[i];
            if(cursum>maxsum)
                maxsum=cursum;
            if(cursum<0)
                cursum=0;
            
        }
        return maxsum;
    }
};
