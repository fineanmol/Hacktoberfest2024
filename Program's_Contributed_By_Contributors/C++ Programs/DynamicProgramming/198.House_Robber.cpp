class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &nums , int i,int n){
       //Base Case
        if(i>=n) 
          return 0;
      
        //if answer to the sub-problem already exist
        if(dp[i]!=-1) 
          return dp[i];

      //robbing this house
      int pick = nums[i]+ solve(nums,i+2,n);
      
      //not robbing this house
      int notPick = solve(nums,i+1,n);

      //Memoize and return the maximum
        return  dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
      //Initialize Dp vector
        dp = vector<int> (nums.size()+1,-1);
      
        return solve(nums,0,nums.size());
    }
};
