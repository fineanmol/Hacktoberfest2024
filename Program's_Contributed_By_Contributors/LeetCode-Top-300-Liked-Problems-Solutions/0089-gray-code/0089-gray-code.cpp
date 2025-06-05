class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < (1 << n); i++) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};