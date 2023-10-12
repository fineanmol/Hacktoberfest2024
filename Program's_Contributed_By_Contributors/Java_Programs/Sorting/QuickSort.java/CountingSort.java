import java.util.Arrays; // Add this import statement

public class CountingSort {

    public static void main(String[] args) {
        int[] arr = {4, 2, 2, 8, 3, 3, 1};
        
        System.out.println("Original Array:");
        printArray(arr);

        countingSort(arr);

        System.out.println("Sorted Array:");
        printArray(arr);
    }

    public static void countingSort(int[] arr) {
        int n = arr.length;
        if (n <= 0) return;

        int max = Arrays.stream(arr).max().getAsInt();
        int min = Arrays.stream(arr).min().getAsInt();
        int range = max - min + 1;

        int[] count = new int[range];
        int[] output = new int[n];

        for (int i = 0; i < n; i++) {
            count[arr[i] - min]++;
        }

        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        System.arraycopy(output, 0, arr, 0, n);
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
