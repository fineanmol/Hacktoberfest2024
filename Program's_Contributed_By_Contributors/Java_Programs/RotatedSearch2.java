package com.sharan;

public class RotatedSearch2 {
    public static boolean search(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        int targets = arr[0];
        int pivot = recursiveBinarySearch(arr,start,end,targets);
        if(target == arr[pivot]){
            return true;
        }
        else if(target > arr[pivot]){
            return false;
        }
        else if(target > start && target < arr[pivot]){
            return binarySearch(arr,target,start,pivot-1);
        }
        else{
            return binarySearch(arr,target,pivot+1,end);
        }
    }
    public static int recursiveBinarySearch(int[] arr,int start, int end, int target){
        if(arr.length == 1) return arr[0];
        if(arr[start] < arr[end]) return arr[start];
        if(start > end){
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (arr[mid] == target || start == end) {
            return mid;
        }
        if (arr[mid] > target){
            return recursiveBinarySearch(arr,mid,end,arr[mid]);
        }
        return recursiveBinarySearch(arr,start,mid,arr[mid]);
    }
    static boolean binarySearch(int[] arr, int target, int start, int end) {
        while (start <= end){
            int mid = start + (end-start)/2;
            if (target > arr[mid]){
                start = mid+1;
            }
            else if (target < arr[mid]){
                end = mid - 1;
            }
            else return true;
        }
        return false;
    }
}
