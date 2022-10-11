// https://leetcode.com/problems/delete-characters-to-make-fancy-string/
package com.sharan;

public class FancyString {
    public static void main(String[] args) {
        String s = "leeetcode";
        System.out.println(makeFancyString(s));
    }
    public static String makeFancyString(String s) {
        char[] arr = s.toCharArray();
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < arr.length - 2; i++) {
            if(arr[i] == arr[i+1] && arr[i+1] == arr[i+2]){
                arr[i] = 0;
            }
        }
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] != 0){
                answer.append(arr[i]);
            }
        }
        return answer.toString();
    }
}
