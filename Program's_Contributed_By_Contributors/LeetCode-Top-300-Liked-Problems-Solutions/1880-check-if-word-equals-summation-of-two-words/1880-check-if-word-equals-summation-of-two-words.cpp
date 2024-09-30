class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        int num1 = 0, num2 = 0, target = 0;

        for(int i = 0; i < f.size(); i++){
            num1 = (f[i] - 'a') + num1 * 10;
        }

        for(int i = 0; i < s.size(); i++){
            num2 = (s[i] - 'a')+ num2 * 10;
        }

        for(int i = 0; i < t.size(); i++){
            target = (t[i] - 'a')+ target * 10;
        }

        return (num1 + num2 == target);
    }
};