// https://leetcode.com/problems/reverse-words-in-a-string-iii/
package com.sharan;

public class ReverseWordsString {
    public static void main(String[] args) {
        String s = "Let's take LeetCode contest";
        String[] b = s.split(" ");
        System.out.println(reverseWords(s));
    }
    public static String reverseWords(String s) {
        StringBuilder answer = new StringBuilder();
        String[] arr = s.split(" ");
        for(int i = 0; i < arr.length ; i++){
            for (int j = arr[i].length() - 1; j >= 0; j--) {
                answer.append(arr[i].charAt(j));
            }
            answer.append(" ");
        }
        return String.valueOf(answer).strip();
    }
}
