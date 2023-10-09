import java.util.Arrays;

public class BitonicSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        bitonicSort(arr, 0, arr.length, true);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void bitonicSort(int[] arr, int low, int count, boolean ascending) {
        if (count > 1) {
            int k = count / 2;
            bitonicSort(arr, low, k, true);
            bitonicSort(arr, low + k, k, false);
            bitonicMerge(arr, low, count, ascending);
        }
    }

    public static void bitonicMerge(int[] arr, int low, int count, boolean ascending) {
        if (count > 1) {
            int k = count / 2;
            for (int i = low; i < low + k; i++) {
                compareAndSwap(arr, i, i + k, ascending);
            }
            bitonicMerge(arr, low, k, ascending);
            bitonicMerge(arr, low + k, k, ascending);
        }
    }

    public static void compareAndSwap(int[] arr, int i, int j, boolean ascending) {
        if ((arr[i] > arr[j] && ascending) || (arr[i] < arr[j] && !ascending)) {
            // Swap elements arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
