// https://leetcode.com/problems/find-unique-binary-string/
package com.sharan;
// 100.00% Faster O(n)
public class FindUniqueBinaryString {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < nums.length; i++){
            if(nums[i].charAt(i) == '1'){
                ans.append("0");
            }
            else{
                ans.append("1");
            }
        }
        return ans.toString();
    }
}