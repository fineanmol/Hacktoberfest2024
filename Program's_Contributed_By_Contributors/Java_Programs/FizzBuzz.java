// https://leetcode.com/problems/fizz-buzz/
package com.sharan;

import java.util.ArrayList;
import java.util.List;
// 99.65 % O(n) Solution.
public class FizzBuzz {
    public List<String> fizzBuzz(int n) {
        ArrayList<String> ans = new ArrayList();
        for(int i = 1; i <= n; i++){
            if(i % 3 == 0 && i % 5 == 0){
                ans.add("FizzBuzz");
            }
            else if(i % 3 == 0){
                ans.add("Fizz");
            }
            else if(i % 5 == 0){
                ans.add("Buzz");
            }
            else{
                ans.add(String.valueOf(i));
            }
        }
        return ans;
    }
}
