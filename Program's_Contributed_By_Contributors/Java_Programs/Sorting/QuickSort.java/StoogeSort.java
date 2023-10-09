import java.util.Arrays;

public class StoogeSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        stoogeSort(arr, 0, arr.length - 1);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void stoogeSort(int[] arr, int l, int h) {
        if (l >= h) {
            return;
        }

        if (arr[l] > arr[h]) {
            int temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
        }

        if (h - l + 1 > 2) {
            int t = (h - l + 1) / 3;

            stoogeSort(arr, l, h - t);
            stoogeSort(arr, l + t, h);
            stoogeSort(arr, l, h - t);
        }
    }
}
