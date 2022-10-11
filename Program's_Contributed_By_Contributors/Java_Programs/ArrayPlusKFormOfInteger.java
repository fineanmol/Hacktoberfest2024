// https://leetcode.com/problems/add-to-array-form-of-integer/
package com.sharan;
// Number exceeding int & long capacity(exceptions), incomplete.
import java.util.ArrayList;
import java.util.Collections;

public class ArrayPlusKFormOfInteger {
    public static void main(String[] args) {
        int[] arr = {1,2,6,3,0,7,1,7,1,9,7,5,6,6,4,4,0,0,6,3};
        int k = 516;
        System.out.println(sum(arr,k));
    }
    static ArrayList<Integer> sum(int[] arr, int k) {
        ArrayList<Integer> list = new ArrayList<Integer>(arr.length + k);
        long j = 1;
        int i = arr.length - 1;
        long sum = 0;
        while (i >= 0) {
            sum += arr[i] * j;
            System.out.println(sum);
            i--;
            j = j * 10;
        }
        sum+= k;
        if (sum == 0){
            list.add(0);
            return list;
        }
        while(sum >= 0){
            long a = sum % 10;
            sum = sum / 10;
            list.add((int)a);
        }
        Collections.reverse(list);
        return list;
    }
}
