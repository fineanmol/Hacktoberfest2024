//https://leetcode.com/problems/reverse-string/
package com.sharan;

public class RecursionStringReverse {
    public void reverseString(char[] s) {
        int i = 0;
        int j = s.length - 1;
        reverse(s,i,j);
    }
    public static void reverse(char[] s, int i, int j){
        if(i<=j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
            reverse(s,i,j);
        }
    }
}
