class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length() - 1;
        int l = 0, r = n;
        while(l <= r){
            if(s[l] == '1')
                l++;
            if(s[r] == '0')
                r--;
            if(l <= r && s[l] == '0' && s[r] == '1'){
                swap(s[l], s[r]);
            } 
        }
        s[l - 1] = '0';
        s[n] = '1';
        return s;
    }
};