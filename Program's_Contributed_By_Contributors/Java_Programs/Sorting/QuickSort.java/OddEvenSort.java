import java.util.Arrays;

public class OddEvenSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        oddEvenSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void oddEvenSort(int[] arr) {
        int n = arr.length;
        boolean sorted = false;

        while (!sorted) {
            sorted = true;

            // Odd phase (compare and swap elements at odd indices)
            for (int i = 1; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr, i, i + 1);
                    sorted = false;
                }
            }

            // Even phase (compare and swap elements at even indices)
            for (int i = 0; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr, i, i + 1);
                    sorted = false;
                }
            }
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
