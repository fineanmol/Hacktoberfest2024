class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int cycle = 2 * numRows - 2;
        string result = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += cycle) {
                result += s[j];

                int k = j + cycle - 2 * i;
                if (i != 0 && i != numRows - 1 && k < s.size()) {
                    result += s[k];
                }
            }
        }

        return result;
    }
};
