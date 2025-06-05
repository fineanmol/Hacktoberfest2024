class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(int c : arr){
            mp[c]++;
        }
        set<int> st;
        for(auto it : mp){
            if(st.find(it.second) != st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};