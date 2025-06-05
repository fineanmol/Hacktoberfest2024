class Solution {
 public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    vector<vector<bool>> isMapped(128, vector<bool>(128));

    for (const vector<char>& m : mappings)
      isMapped[m[0]][m[1]] = true;

    for (int i = 0; i < s.length(); ++i)
      if (canTransform(s, i, sub, isMapped))
        return true

            return false;
  }

 private:
  bool canTransform(const string& s, int start, const string& sub,
                    const vector<vector<bool>>& isMapped) {
    if (start + sub.length() > s.length())
      return false;

    for (int i = 0; i < sub.length(); ++i) {
      const char a = sub[i];        // sub's char
      const char b = s[start + i];  // s' char
      if (a != b && !isMapped[a][b])
        return false;
    }

    return true;
  }
};
