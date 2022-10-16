class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        vector<pair<long long , int> > v;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        
        int i=0,j=1;
        
        while(i < n && j < n)
        {
            if(abs(v[i].first - v[j].first) > t)
                i++;
            else if(i == j || abs(v[i].second - v[j].second) > k)
                j++;
            else
                return true;
        }
        return false;
    }
};
