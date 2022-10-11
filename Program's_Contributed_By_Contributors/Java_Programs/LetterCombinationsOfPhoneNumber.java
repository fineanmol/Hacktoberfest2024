//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
package com.sharan;

import java.util.ArrayList;
import java.util.List;

// Revisit
// Asked in google
// Solution (https://www.youtube.com/watch?v=9ByWqPzfXDU&ab_channel=KunalKushwaha)
// Time Stamp 16:41 to 20:41
// 33% Faster
public class LetterCombinationsOfPhoneNumber {
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return new ArrayList<>();
        ArrayList<String> ans = new ArrayList<>();
        ans = padRet("", digits);
        return ans;
    }
    static ArrayList<String> padRet(String p, String up) {
        if (up.isEmpty()) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }
        ArrayList<String> list = new ArrayList<>();
        int digit = up.charAt(0) - '1';
        if (digit == 8){
            for (int i = (digit - 1) * 3; i <= digit * 3; i++) {
                char ch = (char) ('a' + i + 1);
                list.addAll(padRet(p + ch, up.substring(1)));
            }
        }
        else if (digit == 7){
            for (int i = (digit - 1) * 3; i < digit * 3; i++) {
                char ch = (char) ('a' + i + 1);
                list.addAll(padRet(p + ch, up.substring(1)));
            }
        }
        else if (digit == 6){
            for (int i = (digit - 1) * 3; i <= digit * 3; i++) {
                char ch = (char) ('a' + i);
                list.addAll(padRet(p + ch, up.substring(1)));
            }
        }
        else {
            for (int i = (digit - 1) * 3; i < digit * 3; i++) {
                char ch = (char) ('a' + i );
                list.addAll(padRet(p + ch, up.substring(1)));
            }
        }
        return list;
    }
}
