// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
package com.sharan;
// 99.40% Faster.
import java.util.Arrays;
public class MeanArrayAfterRemovingElements {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int a = 5 * arr.length / 100;
        double ans = 0;
        for(int i = a; i < arr.length - a; i++){
            ans += arr[i];
        }
        return ans / (arr.length - (2 *a));
    }
}
