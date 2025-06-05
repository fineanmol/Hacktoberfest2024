class Solution {
//function to determine whether the substring [l...r] of a string is a palindrome (to handle the middle part of the picture) 
    bool pal_substr(string &s, int l, int r) {
        while(l<=r) {
            if (s[l] != s[r]) return false; 
            l++; r--;
        }
        return true; 
    }
public:
    vector<vector<int>> palindromePairs(vector<string> w) {
        unordered_map <string, int> straight;  //dictionary where key is a string from words, and value is it's index
        unordered_map <string, int> rev;  //same but with reversed words 
        for (int i = 0; i < w.size(); i++) {
            straight[w[i]] = i;
            string u = w[i]; reverse(u.begin(), u.end());
            rev[u] = i;
        }
        set <vector<int>> ans;    //keep found pairs in a set to ensure they are unique
        for (int i = 0; i < w.size(); i++) {
            string t = ""; 
			// lets go from the beginning of string w[i], adding each character to string t. if dictionary rev contains t, and if t is not the same as w[i], and if the remaining part of w[i] is a palindrome (see picture), we've found a suitable pair of indices 
            if (rev.find(t) != rev.end()) if (rev[t] != i) if (pal_substr(w[i], 0, w[i].size()-1)) ans.insert({i, rev[t]}); 
            for (int j = 0; j < w[i].size(); j++) {
                t += w[i][j];
                if (rev.find(t) != rev.end()) if (rev[t] != i) if (pal_substr(w[i], j+1, w[i].size()-1)) ans.insert({i, rev[t]}); 
            }
            t = "";
			// same but another way around 
            if (straight.find(t) != straight.end()) if (straight[t] != i) if (pal_substr(w[i], 0, w[i].size()-1)) ans.insert({straight[t], i});
            for (int j = w[i].size()-1; j >= 0; j--) {
                t += w[i][j];
                if (straight.find(t) != straight.end()) if (straight[t] != i) if (pal_substr(w[i], 0, j-1)) ans.insert({straight[t], i}); 
            }
        }
		//convert set to vector 
        return vector<vector<int>>(ans.begin(), ans.end()); 
    }
};