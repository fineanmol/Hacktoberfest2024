public class MergeSort {
    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6, 7};
        
        System.out.println("Original Array:");
        printArray(array);

        mergeSort(array, 0, array.length - 1);

        System.out.println("\nSorted Array:");
        printArray(array);
    }

    // Merge two subarrays of array[]
    // First subarray is array[l..m]
    // Second subarray is array[m+1..r]
    public static void merge(int array[], int l, int m, int r) {
        // Calculate the sizes of the two subarrays
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays
        int L[] = new int[n1];
        int R[] = new int[n2];

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++) {
            L[i] = array[l + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = array[m + 1 + j];
        }

        // Merge the two subarrays back into the original array
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if any
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if any
        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    // Main function that sorts array[l..r] using merge()
    public static void mergeSort(int array[], int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = (l + r) / 2;

            // Sort the first and second halves
            mergeSort(array, l, m);
            mergeSort(array, m + 1, r);

            // Merge the sorted halves
            merge(array, l, m, r);
        }
    }

    // Helper method to print an array
    public static void printArray(int array[]) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
