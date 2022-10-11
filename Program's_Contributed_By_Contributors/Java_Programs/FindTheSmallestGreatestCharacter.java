// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
package com.sharan;

public class FindTheSmallestGreatestCharacter {
    public char nextGreatestLetter(char[] letters, char target) {
        int start = 0;
        int end = letters.length - 1;
        if(target >= letters[letters.length - 1]){
            return letters[start];
        }
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(target >= letters[mid]){
                start = mid + 1;
            }
            else if(target < letters[mid]){
                end = mid - 1;
            }
        }
        return letters[start];
    }
}
