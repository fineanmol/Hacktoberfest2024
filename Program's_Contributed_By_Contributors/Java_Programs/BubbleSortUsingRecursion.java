// https://www.geeksforgeeks.org/recursive-insertion-sort/
package com.sharan;
// BubbleSort using recursion.
import java.util.Arrays;

public class BubbleSortUsingRecursion {
    public static void main(String[] args) {
        int[] arr = {-1,20,-2,-34,-678,235,23,1,0};
        int j = arr.length;
        System.out.println(Arrays.toString(recursiveInsertion(arr,j)));
    }
    public static int[] recursiveInsertion(int[] arr,int j ){
        if(j < 0){
            return arr;
        }
        for (int i = 1; i < j; i++) {
            if(arr[i-1] > arr[i]){
                swap(arr,i-1,i);
            }
        }
        return recursiveInsertion(arr,j-1);
    }
    public static void swap(int[] arr, int c, int b){
        int a = arr[b];
        arr[b] = arr[c];
        arr[c] = a;
    }
}
