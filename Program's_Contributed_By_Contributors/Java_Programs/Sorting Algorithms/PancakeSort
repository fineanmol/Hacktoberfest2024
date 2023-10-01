import java.util.Arrays;

public class PancakeSort {
    public static void pancakeSort(int[] arr) {
        int n = arr.length;
        for (int i = n; i > 1; i--) {
            int maxIndex = findMaxIndex(arr, i);
            if (maxIndex != i - 1) {
                flip(arr, maxIndex);
                flip(arr, i - 1);
            }
        }
    }

    public static int findMaxIndex(int[] arr, int n) {
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public static void flip(int[] arr, int index) {
        int start = 0;
        while (start < index) {
            int temp = arr[start];
            arr[start] = arr[index];
            arr[index] = temp;
            start++;
            index--;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        pancakeSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
