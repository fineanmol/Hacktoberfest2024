class Solution {
public:
    int minimumOperations(vector<int>& nums) {
    unordered_set<int> s;
    for(auto i:nums) if(i!=0) s.insert(i);
    return s.size();
    }
};