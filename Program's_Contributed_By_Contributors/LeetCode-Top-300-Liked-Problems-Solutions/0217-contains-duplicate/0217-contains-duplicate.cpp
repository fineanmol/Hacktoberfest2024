class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> visited;
        for(auto i : nums){
            if(visited[i] > 0) 
                return true;
            visited[i]++;
        }
        return false;
    }
};