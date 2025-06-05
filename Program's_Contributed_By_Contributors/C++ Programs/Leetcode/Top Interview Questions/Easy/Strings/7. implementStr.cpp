#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if (needle.size()==0)
//             return 0;

//         for (int i=0;i<haystack.size()-needle.size()+1;i++){
//             for (int j=0;j<needle.size();j++){
//                 if (haystack[i+j]!=needle[j]){
//                     break;
//                 }
//                 if (j==needle.size()-1)
//                     return i;
//             }
//         } 
//         return -1;       
//     }
// };

int strStr(string haystack, string needle) {
        if (needle.size()==0)
            return 0;

        for (int i=0;i<haystack.size()-needle.size()+1;i++){
            for (int j=0;j<needle.size();j++){
                if (haystack[i+j]!=needle[j]){
                    break;
                }
                if (j==needle.size()-1)
                    return i;
            }
        } 
        return -1;       
}


int main(){
    cout<<strStr("abaaa","abb");
}