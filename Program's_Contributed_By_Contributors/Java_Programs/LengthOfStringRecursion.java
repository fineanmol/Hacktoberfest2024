// https://www.geeksforgeeks.org/program-for-length-of-a-string-using-recursion/
package com.sharan;

public class LengthOfStringRecursion {
    public static void main(String[] args) {
        String s = "Sharan";
        System.out.println(length(s));
    }
    public static int length(String s){
        if (s.equals(""))
            return 0;
        else
            return length(s.substring(1)) + 1;
    }
}
