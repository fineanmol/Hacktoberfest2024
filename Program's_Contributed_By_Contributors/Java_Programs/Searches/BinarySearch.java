'''
Binary Search in Java
Author: Rishabh Rathore
'''
public class BinarySearch {
    public static void main(String[] args) {
        int[] arr ={-18,-10,-7,-2,0,4,45,55,65,75,79,99};
        int target = 4;
        int ans = binarySearch(arr,target ) ;
        System.out.println(ans);

    }
    static int binarySearch(int[] arr,int target){
        int start = 0;
        int end = arr.length - 1;
        while(start <= end){
            //int mid = (start + end) /2;
            int mid = start + (end - start) /2;
            if(target < arr[mid]){
                end = mid - 1;
            }
            else if (target > arr[mid]){
                start = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
}
