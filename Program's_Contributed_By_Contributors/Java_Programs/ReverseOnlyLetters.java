// https://leetcode.com/problems/reverse-only-letters/
package com.sharan;
// 72.95% Faster
public class ReverseOnlyLetters {
    public String reverseOnlyLetters(String s) {
        char[] ans = s.toCharArray();
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            if (Character.isLetter(s.charAt(start)) && Character.isLetter(s.charAt(end))){
                swap(ans,start,end);
                start++;
                end--;
            }
            else if (Character.isLetter(s.charAt(start)) && !Character.isLetter(s.charAt(end))){
                end--;
            }
            else if (!Character.isLetter(s.charAt(start)) && Character.isLetter(s.charAt(end))){
                start++;
            }
            else {
                start++;
                end--;
            }
        }
        return String.valueOf(ans);
    }
    void swap(char[] arr,int i,int j){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

