// https://leetcode.com/problems/height-checker/
package com.sharan;

import java.util.Arrays;

public class HeightChecker {
  public int heightChecker(int[] heights) {
         int count = 0;
         int[] tempArr = Arrays.copyOf(heights,heights.length);
         Arrays.sort(heights);
         for(int i = 0; i < heights.length; i++){
               if(tempArr[i] != heights[i]){
                  count++;
             }
          }
       return count;
   }
}
