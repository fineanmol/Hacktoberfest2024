// https://leetcode.com/problems/longest-palindromic-substring/
package com.sharan;
// Time Limit Exceeded.
public class LongestPalindromicSubstring {
    public static String longestPalindrome(String s) {
        String ans = "";
        for(int i = 0; i < s.length(); i++){
            StringBuilder temp = new StringBuilder();
            temp.append(s.charAt(i));
            for(int j = i + 1; j < s.length(); j++){
                temp.append(s.charAt(j));
                String tempAns = temp.reverse().toString();
                temp.reverse();
                if(temp.toString().contains(tempAns)){
                    if(ans.length() < tempAns.length()){
                        ans = tempAns;
                    }
                }
            }
        }
        if(ans.length() == 0){
            return String.valueOf(s.charAt(0));
        }
        else return ans;
    }
}
