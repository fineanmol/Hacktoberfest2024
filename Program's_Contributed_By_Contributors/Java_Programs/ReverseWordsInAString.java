// https://leetcode.com/problems/reverse-words-in-a-string/
package com.sharan;
// 10ms 50% Faster
public class ReverseWordsInAString {
    public static void main(String[] args) {
        String str = "  Bob    Loves  Alice   ";
        String ans = "";
        String[] arr = str.replaceAll("( +)"," ").trim().split(" ");
        for (int i = 0; i < arr.length; i++) {
            ans += arr[i];
            ans += " ";
        }
        System.out.println(ans);
    }
}
