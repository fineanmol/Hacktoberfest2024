class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n=nums.size();
        vector<int>nums2(n);
        int idx=0;
        int idx2=n/2;
        
        for(int i=0; i<n; i++){
            if(i%2==1){
                nums2[i]=nums[idx];
                idx++;
            }
            else{
                nums2[i]=nums[idx2];
                idx2++;
            }
        }

        nums=nums2;
    }
};