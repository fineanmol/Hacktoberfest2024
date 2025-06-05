class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int cnt = 0;

        for(int i = 0; i < s.size(); i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt += (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
            }
        }

        return cnt;
    }
};