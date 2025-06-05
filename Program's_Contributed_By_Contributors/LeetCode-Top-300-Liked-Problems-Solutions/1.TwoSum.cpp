class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map <int,int> mpp;
       int n = nums.size();
       for(int i = 0; i < n; i++)
       {
           int needed = target - nums[i];
           if(mpp.find(needed) != mpp.end()){ // check if the remaining needed value is found in hash table
               return {mpp[needed], i};
           }
           mpp[nums[i]] = i; // mapping array values with their index. For ex [5, 6, 3] => Mapping as (5,0)
       }
       return {-1, -1};
    }
};
