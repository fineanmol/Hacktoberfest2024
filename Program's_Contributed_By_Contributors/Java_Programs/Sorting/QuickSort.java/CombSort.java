import java.util.Arrays;

public class CombSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        combSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void combSort(int[] arr) {
        int n = arr.length;
        int gap = n;
        boolean swapped = true;

        while (gap > 1 || swapped) {
            // Update the gap using the comb sequence
            gap = getNextGap(gap);

            // Initialize swapped as false to check if any element is swapped in this pass
            swapped = false;

            // Compare all elements with the current gap
            for (int i = 0; i < n - gap; i++) {
                if (arr[i] > arr[i + gap]) {
                    // Swap arr[i] and arr[i+gap]
                    int temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;

                    // Set swapped to true
                    swapped = true;
                }
            }
        }
    }

    private static int getNextGap(int gap) {
        // Reduce the gap by a shrink factor (e.g., 1.3)
        gap = (gap * 10) / 13;

        return (gap < 1) ? 1 : gap;
    }
}
