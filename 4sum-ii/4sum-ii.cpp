class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> ump;
        int count=0;
        
        for(auto &x : nums1){
            for(auto &y: nums2){
                ump[x+y]++;
            }
        }
        
        for(auto &x : nums3){
            for(auto &y: nums4){
                int sum = (x+y)*-1;
                if(ump.find(sum) != ump.end()) count+=ump[sum];
            }
        }
        
       return count;
    }
};