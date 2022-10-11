// Infosys questions
package com.sharan;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class InfosysQuestions {
    public static void main(String[] args) {
        System.out.println(characterRepeat("statistics"));
        System.out.println(shiftCards(new String[] {"red", "blue", "green", "yellow"}, 1, "yellow"));
        System.out.println(processorTime(new int[] {8, 10}, new int[] {3, 1, 8, 7, 4, 2, 5, 2}));
        System.out.println(beautifulSubsequence("dsaddd"));
    }
    // 1
    public static int characterRepeat(String s){
        for (int i = 0; i < s.length(); i++) {
            int count = 1;
            for (int j = 0; j < s.length(); j++) {
                if (i != j) {
                    if (s.charAt(i) == s.charAt(j)) {
                        count++;
                    }
                }
            }
            if (count == 1) return i+1;
        }
        return -1;
    }
    // 2
    public static int shiftCards(String[] arr, int start, String target) {
        String s = arr[start];
        int innerStart = start;
        int left = 0;
        int right = 0;
        //  Right traverse
        while (!s.equals(target)) {
            if (innerStart == arr.length) {
                innerStart = 0;
            }
            if (!arr[innerStart].equals(target)) {
                innerStart++;
                right++;
            }
            else {
                s = target;
            }
        }
        innerStart = start;
        s = arr[start];
        // Left traverse
        while (!s.equals(target)) {
            if (innerStart < 0) {
                innerStart = arr.length - 1;
            }
            if (!arr[innerStart].equals(target)) {
                innerStart--;
                left++;
            }
            else {
                s = target;
            }
        }
        return Math.min(right, left);
    }
    // 3
    public static int processorTime(int[] p, int[] t) {
        Arrays.sort(p);
        Arrays.sort(t);
        int innerFor = t.length - 1;
        int max = 0;
        int calcMax = 0;
        for (int i = 0; i < p.length; i++) {
            int count = 0;
            for (int j = innerFor; j >= 0 ; j--) {
                calcMax = Math.max(calcMax, p[i] + t[j]);
                count++;
                if (count == 4) {
                    innerFor = j - 1;
                    break;
                }

            }
        }
        return Math.max(max, calcMax);
    }
    // 4
    public static int beautifulSubsequence (String s) {
        Set<String> ans = new HashSet<>();
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            j++;
            if (j + 1 > s.length()) {
                j = 0;
                String temp2 = s.substring(j+1 , i);
                ans.add(temp2);
                return ans.size();
            }
            String temp = s.substring(0 , i) + s.substring(j + 1);
            if (!temp.isEmpty()) {
                ans.add(temp);
            }
            temp = "";
        }
        System.out.println(ans);
        return ans.size();
    }
}