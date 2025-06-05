#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> anagram;
        if (s.length()!=t.length())
            return false;
        
        for (int i =0; i< s.length();i++){
            anagram[s[i]]++;
            anagram[t[i]]--;
        }       
        for (auto i:anagram){
            if (i.second!=0){
                return false;
            }
        }
        return true;
    }
};