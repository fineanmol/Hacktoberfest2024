// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
package com.sharan;
// 2Rs approach.
import java.util.ArrayList;
import java.util.Collections;

public class KthSmallestElementSortedMatrix {
    public static int kthSmallest(int[][] matrix, int k) {
        int count = 0;
        ArrayList<Integer> arr = new ArrayList();
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++){
                arr.add(matrix[i][j]);
            }
        }
        Collections.sort(arr);
        System.out.print(arr);
        return arr.get(k-1);
    }
}
