// https://leetcode.com/problems/replace-words/
package com.sharan;
// 42.37% Faster 95.71% Less memory
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ReplaceWords {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        String s = "the cattle was rattled by the battery";
        list.add("cat");
        list.add("bat");
        list.add("rat");
        System.out.println(replaceWords(list, s));
    }
    public static String replaceWords(List<String> dictionary, String sentence) {
        StringBuilder ans = new StringBuilder();
        dictionary.sort(Comparator.comparingInt(String::length));
        String[] arr = sentence.split(" ");
        for (String s : dictionary) {
            for (int j = 0; j < arr.length; j++) {
                if (arr[j].startsWith(s)) {
                    arr[j] = s;
                }
            }
        }
        for (int k = 0; k < arr.length; k++) {
            if (k != arr.length -1) {
                ans.append(arr[k]).append(" ");
            }
            else {
                ans.append(arr[k]);
            }
        }
        return ans.toString();
    }
}
