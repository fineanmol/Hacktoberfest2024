package com.binarysearch;

public class SmallestLetter {
    public static void main(String[] args) {
        Character[] Arr = {'c', 'f', 'j'};
        Character target = 'z';
        System.out.println(SmallLetter(Arr, target));
    }

    static Character SmallLetter(Character[] Arr, Character target) {
        int start = 0;
        int end = Arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (Arr[mid] < target) {
                start = mid + 1;
            } else{
                end = mid - 1;
            }
            if (Arr[mid] >= Arr.length){
                return Arr[0];
            }
        }
        return Arr[start];
    }

}
