import java.util.*;

public class InfiniteSortedArray {
    public static void main(String[] args) {
        int[] arr = { 3, 5, 7, 9, 10, 13, 27, 90, 200, 300 };
        int target = 10;

        System.out.println(ans(arr, target));
    }

    static int ans(int[] arr, int target) {
        // first find the box
        // first start with a box of size 2
        int start = 0;
        int end = 1;

        // condition for the target to lie in the range
        while (target > arr[end]) {
            int newstart = end + 1;
            end = end + (end - start + 1) * 2;
            start = newstart;

        }
        return binarysearch(arr, target, start, end);
    }

    static int binarysearch(int[] arr, int target, int start, int end) {
        while (start <= end) {
            // finding the middle element
            // int mid = (start + end) / 2 not using this because mmight be the integer
            // exceeds the java capacity
            int mid = start + (end - start) / 2;
            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                // answer found
                return mid;
            }
        }
        return -1;
    }
}
