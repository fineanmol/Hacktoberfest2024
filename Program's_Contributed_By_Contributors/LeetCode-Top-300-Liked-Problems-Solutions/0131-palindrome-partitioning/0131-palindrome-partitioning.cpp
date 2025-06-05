class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector <vector<string>> res;
        vector <string> part;
        generate(0, s, part, res);
        return res;
    }
private: 
    void generate(int index, string s, vector <string> &part, vector <vector<string>> &res)
    {
        int n = s.size();
            if(index == n)
            {
                res.push_back(part); // when partition reaches the end, push the substring array back
                return;
            }

            for(int i = index; i < n; i++)
            {
                if(isPalindrome(s, index, i)) // if the left part of the partition is a palindrome, then continue with the right side as a new string 
                {
                    part.push_back(s.substr(index, i - index + 1));
                    generate(i+1, s, part, res); // continuing the same process for the remaining part of the string until the partition reaches the end
                    part.pop_back(); // removing the parent node of partition 
                }
            }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};