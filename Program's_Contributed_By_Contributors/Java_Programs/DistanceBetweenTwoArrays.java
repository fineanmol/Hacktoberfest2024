// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/submissions/
package com.sharan;
// 82.92% Faster O(n^2)
public class DistanceBetweenTwoArrays {
    public static void main(String[] args) {
        int[] arr1 = {2,1,100,3};
        int[] arr2 = {-5,-2,10,-3,7};
        int d = 6;
        System.out.println(findTheDistanceValue(arr1,arr2,d));
    }
    public static int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int ans = 0;
        for(int i = 0; i < arr1.length; i++){
            int count = 0;
            for(int j = 0; j < arr2.length; j++){
                if(Math.max(arr1[i],arr2[j]) - Math.min(arr1[i],arr2[j]) > d){
                    count++;
                    if(count == arr2.length){
                        ans+=1;
                        break;
                    }
                }
                 else{
                     break;
                 }
            }
        }
        return ans;
    }
}
