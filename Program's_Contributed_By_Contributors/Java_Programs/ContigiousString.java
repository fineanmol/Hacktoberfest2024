// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
package com.sharan;

public class ContigiousString {
    public static void main(String[] args) {
        String s = "1101";
        System.out.println(checkZeroOnes(s));
    }
    public static boolean checkZeroOnes(String s) {
        int ones = checkOne(s);
        int zeros = checkZero(s);
        return ones > zeros;
    }
    public static int checkOne(String s){
        int ans = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '1'){
                count++;
                if(count > ans){
                    ans = count;
                }
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
    public static int checkZero(String s){
        int ans = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '0'){
                count++;
                if(count > ans){
                    ans = count;
                }
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
}
