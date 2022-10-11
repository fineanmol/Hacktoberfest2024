// https://leetcode.com/problems/add-to-array-form-of-integer/
package com.sharan;
// Slow solution + Space complexity != O(1).
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class AddArrayInteger {
    public static void main(String[] args) {
        int[] arr = {9, 9, 9};
        int k = 1;
        System.out.println(addToArrayForm(arr,k));
    }
    public static List<Integer> addToArrayForm(int[] arr, int k) {
        ArrayList<Integer> list = new ArrayList<>();
        StringBuilder answer = new StringBuilder();
        BigInteger b = BigInteger.valueOf(k);
        for (int value : arr) {
            answer.append(value);
        }
        BigInteger a = new BigInteger(answer.toString());
        a = a.add(b);
        answer = new StringBuilder(a.toString());
        for(int j = 0; j < answer.length(); j++){
            list.add(Integer.parseInt(String.valueOf(answer.charAt(j))));
        }
        return list;
    }
}