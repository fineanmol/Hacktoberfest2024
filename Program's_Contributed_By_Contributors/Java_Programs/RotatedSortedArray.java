// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
package com.sharan;

// recursive binary search.

class RotatedSortedArray {
    public static void main(String[] args) {
        int[] arr = {4,5,6,7,0,1,2};
        System.out.println(findMin(arr));
    }
    public static int findMin(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int target = arr[0];
        return recursiveBinarySearch(arr,start,end,target);
    }
    public static int recursiveBinarySearch(int[] arr,int start, int end, int target){
        if(arr.length == 1) return arr[0];
        if(arr[start] < arr[end]) return arr[start];
        if(start > end){
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (arr[mid] == target || start == end) {
            return arr[mid+1];
        }
        if (arr[mid] > target){
            return recursiveBinarySearch(arr,mid,end,arr[mid]);
        }
        return recursiveBinarySearch(arr,start,mid,arr[mid]);

    }
}
