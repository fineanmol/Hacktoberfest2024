// Find the Duplicate Number
// link: https://leetcode.com/problems/find-the-duplicate-number/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq;
        freq.resize(nums.size()+1);
	int  i;
	for(i=0;i<=nums.size()+1;++i){
		freq[nums[i]]++;
		if(freq[nums[i]]==2){
			break;
		}
	}
        
    return nums[i];
    }
};