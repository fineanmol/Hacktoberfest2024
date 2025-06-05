class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int el1 = -1, el2 = -1, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 && el2 != nums[i]){
                el1 = nums[i];
                cnt1 = 1;
            }else if(cnt2 == 0 && el1 != nums[i]){
                el2 = nums[i];
                cnt2 = 1;
            }else if(nums[i] == el1){
                cnt1++;
            }else if(nums[i] == el2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        int size = nums.size() / 3 + 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }
        if(cnt1 >= size) ans.push_back(el1);
        if(cnt2 >= size) ans.push_back(el2);
        return ans;
    }
};