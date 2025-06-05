class Solution {
public:
    string decodeString(string s) {
        stack<string> str; // to keep track of our computed string
        stack<int> cnt; // to keep track of digits
        string ans = "";

        int num = 0, n = s.length();

        for(int i = 0; i < n; i++){
            if(isdigit(s[i]))
                num = num * 10 + s[i] - '0';
            else if(s[i] == '['){
                str.push(ans); // store the current main string
                ans = "";
                cnt.push(num); // store the current count
                num = 0;
            }
            else if(s[i] == ']'){
                string t = ans; // store current string
                ans = str.top(); // retrieve the previous main string
                str.pop();
                int freq = cnt.top(); // retrieve the cur string count
                cnt.pop();

                while(freq--)
                    ans += t; // concatenate the prev main string with current string
            }
            else
                ans += s[i];
        }
        return ans;
    }
};