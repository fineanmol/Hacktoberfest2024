
/**
 * 
 * @author Aryan Srivastava (https://github.com/Aryan-Srivastava)
 * Time Complexity - O(n^2)
 * Space Complexity - O(logn)
 * 
 * Resource
 * https://www.geeksforgeeks.org/quick-sort/
 * 
 */
import java.util.Arrays;

public class quickSort {

    public static void main(String[] args) {
        int[] arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        System.out.println("Before sort\n" + Arrays.toString(arr));
        sort(arr, 0, arr.length - 1);
        System.out.println("After sort\n" + Arrays.toString(arr));
    }

    private static void sort(int[] arr, int start, int end) {
        if (start >= end)
            return;
        int pivot = partition(arr, start, end);
        sort(arr, start, pivot - 1);
        sort(arr, pivot + 1, end);
    }

    private static int partition(int[] arr, int start, int end) {
        int pivot = arr[start];
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }
        int pivotIndex = start + count;
        arr[start] = arr[pivotIndex];
        arr[pivotIndex] = pivot;

        int j = start, k = end;
        while (j < pivotIndex && k > pivotIndex) {
            if (arr[j] <= pivot)
                j++;
            else if (arr[k] > pivot)
                k--;
            else {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
                j++;
                k--;
            }
        }
        return pivotIndex;
    }
}
