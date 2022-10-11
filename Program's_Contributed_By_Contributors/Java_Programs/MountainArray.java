package com.sharan;

public class MountainArray {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int ans1 = rightSearch(arr);
        int ans2 = leftSearch(arr);
        System.out.println(arr[ans1] > arr[ans2] ? ans1 : ans2);
        System.out.println(arr[ans1]);
        System.out.println(arr[ans2]);
    }
    static public int rightSearch(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int target1 = 0;
        while (start <= end){
            int mid = start + (end - start) / 2 ;
            target1 = mid;
            if ( mid + 1 <= arr.length - 1 && arr[mid] <= arr[mid + 1]){
                target1 = mid + 1;
                start = target1;
            }
            else return target1;
        }
        return -1;
    }
    static public int leftSearch(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int target2 = 0;
        while (start <= end){
            int mid = start + (end - start) / 2 ;
            target2 = mid;
            if (mid - 1 >= 0 && arr[mid -1] >= arr[mid]){
                target2 = mid - 1;
                end = target2;
            }
            else if (mid + 1 <= arr.length -1 && arr[mid] <= arr[mid + 1]){
                target2 = mid + 1;
                start = target2;
            }
            else return target2;
        }
        return -1;
    }
}
