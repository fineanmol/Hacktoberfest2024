// https://leetcode.com/problems/isomorphic-strings/?envType=study-plan&id=level-1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapST, mapTS;

        for (int i=0;i<s.length();i++){
            char c1 = s[i];
            char c2 = t[i];

            if (
                mapST.find(c1)!=mapST.end() && mapST[c1]!=c2 ||
                mapTS.find(c2)!=mapTS.end() && mapTS[c2]!=c1
            )   return false;
            mapST[c1]=c2;
            mapTS[c2]=c1;
        }
        return true;
    }
};