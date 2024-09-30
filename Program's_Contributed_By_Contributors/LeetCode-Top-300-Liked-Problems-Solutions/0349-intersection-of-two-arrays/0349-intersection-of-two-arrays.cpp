class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for(int n : nums1){
            s1.insert(n);
        }
        for(int n : nums2){
            if(s1.find(n) != s1.end())
                s2.insert(n);
        }
        return vector<int>(s2.begin(), s2.end());
    }
};