class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int num : arr)
            mp[num]++;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : mp){
            pq.push(it.second);
        }

        while(k){
            int top = pq.top();
            if(k >= top){
                k -= top;
                pq.pop();
            }else
                break;
        }
        return pq.size();
    }
};