class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, jumps = 0, current = 0;
        // i => left pointer & farthest => right most pointer
        for(int i = 0; i < nums.size() - 1; i++)
        {
            
            farthest = max(farthest, i + nums[i]);

            if(i == current)
            {
                current = farthest;
                jumps += 1;
            }
        }
        return jumps;
    }
};