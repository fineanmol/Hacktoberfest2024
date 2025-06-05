class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;
        int len = s.size(), i = 0;

        while(i < len && s[i] == ' ') i++;

        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true || negative == true ? i++ : i;

        double num = 0;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = 1LL * num * 10 + (s[i] - '0');
            i++;
        }
        num = (negative == true) ? -num : num;

        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;

        return (int)num;
        
    }
};
