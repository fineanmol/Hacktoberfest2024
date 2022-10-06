	class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> a;
        for(auto &x:nums)
        {
            a[x]++;
        }
        
        for(auto &z:a)
        {
            if(z.second>=2)
                return true;
        }
        
        return false;
        
    }
};
