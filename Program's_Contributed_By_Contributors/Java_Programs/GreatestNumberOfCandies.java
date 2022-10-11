// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
package com.sharan;

import java.util.ArrayList;
import java.util.List;

public class GreatestNumberOfCandies {
        public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
            ArrayList<Boolean> boolList = new ArrayList<Boolean>(candies.length);
            int start = 0;
            int max = candies[start];
            for(int i = 0; i < candies.length; i++){
                if(candies[i] > max){
                    max = candies[i];
                }
            }
            for(int j = 0; j < candies.length; j++){
                if(candies[j] + extraCandies >= max){
                    boolList.add(true);
                }
                else{
                    boolList.add(false);
                }
            }
            return boolList;
        }

}
