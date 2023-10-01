import java.util.Arrays;
import java.util.Collections;

public class IntroSort {
    public static void introSort(int[] arr) {
        int maxDepth = (int) (Math.log(arr.length) * 2);
        introSort(arr, 0, arr.length - 1, maxDepth);
    }

    public static void introSort(int[] arr, int low, int high, int maxDepth) {
        if (high - low > 16) {
            if (maxDepth == 0) {
                heapSort(arr, low, high);
                return;
            }
            maxDepth--;

            int pivot = partition(arr, low, high);
            introSort(arr, low, pivot, maxDepth);
            introSort(arr, pivot + 1, high, maxDepth);
        } else {
            insertionSort(arr, low, high);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;

        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);

            if (i >= j) {
                return j;
            }

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    public static void heapSort(int[] arr, int low, int high) {
        Arrays.sort(arr, low, high + 1);
    }

    public static void insertionSort(int[] arr, int low, int high) {
        for (int i = low + 1; i <= high; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        introSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
