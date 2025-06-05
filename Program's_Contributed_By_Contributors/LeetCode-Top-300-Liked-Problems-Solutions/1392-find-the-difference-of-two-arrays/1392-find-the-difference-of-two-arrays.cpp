class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for(int num : nums1)
            s1.insert(num);
        for(int num : nums2)
            s2.insert(num);
        
        vector<vector<int>> ans;
        vector<int> temp1;

        for(int num : s1){
            if(s2.find(num) == s2.end())
                temp1.push_back(num);
        }
        //sort(temp1.begin(), temp1.end());
        ans.push_back(temp1);

        vector<int> temp2;
        for(int num : s2){
            if(s1.find(num) == s1.end())
                temp2.push_back(num);
        }
        //sort(temp2.begin(), temp2.end());
        ans.push_back(temp2);

        return ans;
        
    }
};