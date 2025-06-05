class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moree Voting Algorithm => T.C = O(2n), S.C = O(1)
        int cnt = 0, el;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el) cnt++;
            else cnt--;
        }

        int cnt1 = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == el) cnt1++;
        
        if(cnt1 > (nums.size() / 2))
            return el;
        
        return -1;
    }
};