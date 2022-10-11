// https://leetcode.com/problems/palindromic-substrings/

package com.sharan;
// 6.01 % 653ms runtime done without dp.

public class PalindromicSubstrings {
    public static int countSubstrings(String s) {
        int ans = s.length();
        for(int i = 0; i < s.length(); i++){
            StringBuilder temp = new StringBuilder();
            temp.append(s.charAt(i));
            for(int j = i + 1; j < s.length(); j++){
                temp.append(s.charAt(j));
                String tempAns = temp.reverse().toString();
                temp.reverse();
                if(temp.toString().contains(tempAns)){
                    ans+=1;
                }
            }
        }
        return ans;
    }
}
