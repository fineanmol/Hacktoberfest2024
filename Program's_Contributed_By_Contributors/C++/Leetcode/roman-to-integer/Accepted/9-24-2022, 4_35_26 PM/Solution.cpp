// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int count = 0;
        for (int i = 0;i<s.size();i++){
            
            if (s.substr(i,2)=="IV"){
                count+=4;
                i++;
            } else if (s.substr(i,2)=="IX"){
                count+=9;
                i++;
            } else if (s.substr(i,2)=="XL"){
                count+=40;
                i++;
            } else if (s.substr(i,2)=="XC"){
                count+=90;
                i++;
            } else if (s.substr(i,2)=="CD"){
                count+=400;
                i++;
            } else if (s.substr(i,2)=="CM"){
                count+=900;
                i++;
            } else {
                count+=map[s[i]];
            }
            
            
            
        }
        return count;
    }
};