#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n-1; i>=0;i--){
            if (digits[i]<9){
                digits[i]++;
                return digits;
            }
            // Changes last digit to 0 and adds 1 to next digit
            digits[i]=0;
        }
        // For cases like 999 where result will be 1000
        vector<int> result(n+1,0);  
        result[0]=1;
        return result;
    }
};