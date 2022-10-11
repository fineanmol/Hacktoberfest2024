// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

package com.sharan;

// Could have used binary search ;_;

public class CountNegativeNumbersInSorted2DMatrix {
    public int countNegatives(int[][] grid) {
        int count = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] < 0){
                    count++;
                }
            }
        }
        return count;
    }

}
