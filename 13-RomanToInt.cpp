/*
https://leetcode.com/problems/roman-to-integer/

*/

class Solution {
public:
    int romanToInt(string s) {
        int n= s.size(), ans=0, i=0, num;
        map<char, int> mp;
        mp['I']=1 ;mp['V']=5 ;mp['X']=10 ;mp['L']=50 ;mp['C']=100 ;mp['D']=500 ;mp['M']=1000 ;
        while(i<n){
            if(i==n-1 || (mp[s[i]]>=mp[s[i+1]])){
                num = mp[s[i]];
                i++;
            }
            else{
                num = mp[s[i+1]] - mp[s[i]];
                i += 2;
            }         
            ans += num;
        }
        return ans;
    }
};

//31ms
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int end = s.size()-1, num =0;
        int last=0;
        int curr;
        while(end>=0){
            curr = m[s[end]];
            if(last > curr)
                num-=curr;
            else{
                num+=curr; last = curr;
            }
            --end;
        }
        return num;
    }
};

//19ms
class Solution {
public:
    int convert(char i){
        switch(i){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L' : return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return -1;
    }
    int romanToInt(string s) {
        int end = s.size()-1, num =0;
        int last=0;
        int curr;
        while(end>=0){
            curr = convert(s[end]);
            if(last > curr)
                num-=curr;
            else{
                num+=curr; last = curr;
            }
            --end;
        }
        return num;
    }
};


//4ms
class Solution {
public:
    int convert(char i){
            if( i == 'I') return 1;
            else if(i=='V') return 5;
            else if(i=='X') return 10;
            else if(i== 'L') return 50;
            else if(i=='C') return 100;
            else if(i=='D') return 500;
            else return 1000;
    }
    int romanToInt(string s) {
        int end = s.size()-1, num =0;
        int last=0;
        int curr;
        while(end>=0){
            curr = convert(s[end]);
            if(last > curr)
                num-=curr;
            else{
                num+=curr; last = curr;
            }
            --end;
        }
        return num;
    }
};