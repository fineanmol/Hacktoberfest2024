// https://leetcode.com/problems/string-to-integer-atoi

#include <ctype.h>
#include <string.h>
class Solution {
public:
    int myAtoi(string s) {
        int si = 0;
        int sign = 0;
        while (s[si]==' '){
            si++;
        }
        
        if (s[si] == '-'){
            sign=1;
        }
        
        if (s[si] == '+' || s[si] == '-'){
            si++;
        }
        
        long no=0;
        
        while (isdigit(s[si])){
            no=no*10+(int)(s[si++]-'0');
            if (no>INT_MAX){
                if (sign){
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            }
        }
        
        
        return pow(-1,sign)*no;
    }
};