class Solution {
public:
    string toBinary(int num){
        string b = "";
        while(num){
            b += (num % 2) + '0';
            num /= 2;
        }
        reverse(b.begin(), b.end());
        cout << b << endl;
        return b;
    }
    string convertDateToBinary(string s) {
        int n = s.size(), num = 0;
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '-'){
                num = num * 10 + (s[i] - '0');
            }else{
                ans += toBinary(num) + s[i];
                num = 0;
            }
        }
        ans += toBinary(num);
        return ans;
    }
};