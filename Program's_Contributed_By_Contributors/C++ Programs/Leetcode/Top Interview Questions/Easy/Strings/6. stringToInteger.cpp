#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int MAX= INT_MAX, MIN=INT_MIN;
        long result =0;

        if (s.length()==0) return 0;
        int i=0;

        while (i<s.size() && s[i]==' ')
            i++;

        s = s.substr(i);

        if (s[0]=='-')
            sign = -1;
        
        i = (s[0]=='+'||s[0]=='-')?1:0;

        while (i<s.length()){
            if (s[0]==' ' || !isdigit(s[i])) break;

            result = result * 10 + s[i]-'0';
            if (sign ==-1 && result*sign<MIN) return MIN;
            if (sign == 1 && result>MAX) return MAX;

            i++;
        } 

        return (int)(result*sign);
    }
};