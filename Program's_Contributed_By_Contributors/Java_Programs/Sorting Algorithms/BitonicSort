import java.util.Arrays;

public class BitonicSort {
    public static void bitonicSort(int[] arr) {
        bitonicSort(arr, 0, arr.length, true);
    }

    public static void bitonicSort(int[] arr, int start, int length, boolean order) {
        if (length > 1) {
            int middle = length / 2;
            bitonicSort(arr, start, middle, true);
            bitonicSort(arr, start + middle, middle, false);
            bitonicMerge(arr, start, length, order);
        }
    }

    public static void bitonicMerge(int[] arr, int start, int length, boolean order) {
        if (length > 1) {
            int k = length / 2;
            for (int i = start; i < start + k; i++) {
                if ((arr[i] > arr[i + k]) == order) {
                    int temp = arr[i];
                    arr[i] = arr[i + k];
                    arr[i + k] = temp;
                }
            }
            bitonicMerge(arr, start, k, order);
            bitonicMerge(arr, start + k, k, order);
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        bitonicSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
