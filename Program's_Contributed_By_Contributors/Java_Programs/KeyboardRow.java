// https://leetcode.com/problems/keyboard-row/
package com.sharan;
import java.util.ArrayList;
import java.util.Arrays;

// O(N^3) can be done in O(n) time using hashmap

public class KeyboardRow {
    public static void main(String[] args) {
        String[] arr = {"adsdf","sfd"};
        System.out.println(Arrays.toString(findWords(arr)));
    }
    public static String[] findWords(String[] words) {
        ArrayList<String> answer = new ArrayList();
        StringBuilder ans = new StringBuilder();
        String[] rows = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        for (String row : rows) {
            for (String word : words) {
                for (int k = 0; k < word.length(); k++) {
                    if (row.contains(Character.toString(word.toLowerCase().charAt(k)))) ans.append(word.charAt(k));
                    else break;
                }
                if (word.equals(ans.toString())) answer.add(ans.toString());
                ans = new StringBuilder();
            }
        }
        String[] arr = new String[answer.size()];
        for (int l = 0; l < answer.size(); l++){
            arr[l] = answer.get(l);
            final char y = Character.toUpperCase(arr[l].charAt(0));
            if(Character.compare(arr[l].charAt(0), y) == 0) {
                arr[l] = y + arr[l].substring(1);
            }
        }
        return arr;
    }
}
