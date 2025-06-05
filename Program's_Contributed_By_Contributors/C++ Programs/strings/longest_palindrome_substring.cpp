
string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0)return "";
    int i = 0;
    int maxi = 0;
    string ans = "";
    int lef, rig;

    while (i < n) {
        //odd case
        lef = i; rig = i;
        while (lef >= 0 && rig <= n - 1 && s[lef] == s[rig]) {
            if (maxi < rig - lef + 1) {
                string t(s.begin() + lef, s.begin() + rig + 1);
                ans = t;
                maxi = rig - lef + 1;
            }
            lef--;
            rig++;
        }
        //even case
        lef = i; rig = i + 1;
        while (lef >= 0 && rig <= n - 1 && s[lef] == s[rig]) {
            if (maxi < rig - lef + 1) {
                string t(s.begin() + lef, s.begin() + rig + 1);
                ans = t;
                maxi = rig - lef + 1;
            }
            lef--;
            rig++;
        }
        i++;
    }
    return ans;
}
