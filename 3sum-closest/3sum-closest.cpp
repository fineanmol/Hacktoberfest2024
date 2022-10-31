class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int fix = 0 ;
        int tmp = nums[0]+nums[1]+nums[2] ;
        
        while( fix < nums.size() - 2 ){
            
            int left = fix + 1;
            int right = nums.size() - 1 ;
            
            while ( left < right ){
                
                int sum = nums[fix] + nums[left] + nums[right];
                if ( abs(sum-target) < abs(tmp-target) ) tmp = sum;
                if ( sum > target ) right -= 1;
                else if ( sum < target ) left += 1;
                else return target;
                
            }
            
            fix += 1;
            
        }
        return tmp;
    }
};