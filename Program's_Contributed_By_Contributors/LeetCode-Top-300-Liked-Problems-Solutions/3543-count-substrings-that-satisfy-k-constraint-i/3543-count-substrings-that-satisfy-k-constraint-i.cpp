class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l = 0, r = 0;
        int cnt0 = 0, cnt1 = 0;
        int totalCnt = 0;

        while(l <= r && r < s.size()){
            if(s[r] == '0') cnt0++;
            else cnt1++;

            while(cnt0 > k && cnt1 > k){
                if(s[l] == '0') cnt0--;
                else cnt1--;
                l++;
            } 
            totalCnt += (r - l + 1);
            r++;
        }
        return totalCnt;
    }
};