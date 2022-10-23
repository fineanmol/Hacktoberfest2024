class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(auto x: nums)
            mp[x]++;
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            
           if(!mp.count(nums[i]-1)){ // starting point of one of my sequence
               
               int cnt=1,num = nums[i];
               while(mp.count(num+1)){
                   cnt++,num++;
               }
               ans = max(ans,cnt);
           }        
        }   
        return ans;
    }
};
