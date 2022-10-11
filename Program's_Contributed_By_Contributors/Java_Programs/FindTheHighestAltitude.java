// https://leetcode.com/problems/find-the-highest-altitude/
package com.sharan;

public class FindTheHighestAltitude {
    public int largestAltitude(int[] gain) {
        int highestAltitude = 0;
        int start = 0;
        for(int i = 0; i < gain.length; i++){
            start += gain[i];
            if(start > highestAltitude){
                highestAltitude = start;
            }
        }
        return highestAltitude;
    }
}
