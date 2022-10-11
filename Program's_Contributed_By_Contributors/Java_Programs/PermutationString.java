package com.sharan;

import java.io.OutputStream;

public class PermutationString {
    public static void main(String[] args) {
        String s = "abc";
        permutationString("",s);
        int[] arr = {1,2,3,4,5,6,7,8,9};
    }
    public static void permutationString(String p, String up){
        if (up.isEmpty()){
            System.out.println(p);
            return;
        }
        char ch = up.charAt(0);
        for (int i = 0; i <= p.length(); i++) {
            String s = p.substring(0,i);
            String q = p.substring(i,p.length());
            permutationString(s + ch + q, up.substring(1));
        }
    }
}
