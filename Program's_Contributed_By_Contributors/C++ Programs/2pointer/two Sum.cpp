class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int>lookup ; 
        
        for(int i = 0 ; i < nums.size() ; i++){
            lookup[nums[i]] = i ; 
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if( (lookup[target - nums[i]])  && (lookup[target - nums[i]] != i) ){
                    return {i,lookup[target - nums[i]]};
            }
        }
        return {-1,-1};
    }
};
