class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        
        long m1 = LONG_MIN;
        long m2 = LONG_MIN;
        long m3 = LONG_MIN;

        for(int i:nums)
        {
            if(i == m1 || i == m2 || i == m3)
                continue;
            
            if(m1 < i)
            {
                m3 = m2;
                m2 = m1;
                m1 = i;
            }
            
            else if(m2 < i)
            {
                m3 = m2;
                m2 = i;
            }
            
            else if(m3 < i)
                m3 = i;
        }
        
        if(m3 == LONG_MIN)
            return (int)m1;
        return (int)m3;
    }
};
