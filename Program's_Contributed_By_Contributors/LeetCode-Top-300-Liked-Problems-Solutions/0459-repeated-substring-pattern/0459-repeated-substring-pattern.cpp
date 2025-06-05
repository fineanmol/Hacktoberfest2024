class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= n / 2; i++){
            if(n % i == 0){
                string str = "";
                for(int j = 0; j < n / i; j++)
                    str += s.substr(0, i);
                
                if(str == s) return true;
            }
        }
        return false;
    }
};