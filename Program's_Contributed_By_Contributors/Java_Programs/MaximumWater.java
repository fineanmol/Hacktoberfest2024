// https://leetcode.com/problems/container-with-most-water/
package com.sharan;
// Asked in Google
public class MaximumWater {
    public int maxArea(int[] height) {
        int start = 0;
        int end = height.length - 1;
        int ans = 0;
        while(start < end){
            // (length * breadth) ,length can be calculated by subtraction the bigger with smaller hence,
            // end - start nad minimum of the height is chosen since smaller height can be compensated.
            int area = (end - start) * Math.min(height[start], height[end]);
            if(area > ans){
                ans = area;
            }
            if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
}
