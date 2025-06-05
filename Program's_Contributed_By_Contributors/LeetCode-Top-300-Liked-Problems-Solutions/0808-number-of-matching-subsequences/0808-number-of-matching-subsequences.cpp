class Solution {
public:
    int isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;

        while(i < n && j < m){
            if(s[i] == t[j]) i++;
            j++;
        }

        return i == n;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(), cnt = 0;
        unordered_map<string, int> mp;

        for(string x : words){

            if(mp.find(x) != mp.end()){
                if(mp[x]) cnt += 1;
                continue;
            }

            mp[x] = isSubsequence(x, s);
            cnt += (mp[x]);
            
        }

        return cnt;
    }
};