class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans = arr;
        for(int i = 0; i < n; i++){
            ans[(i + k) % n] = arr[i];
        }
        arr = ans;
    }
};