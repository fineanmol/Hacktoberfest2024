import java.util.Arrays;

public class TournamentSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        tournamentSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void tournamentSort(int[] arr) {
        int n = arr.length;
        int[] tree = new int[2 * n - 1];

        // Build the tournament tree
        buildTree(arr, tree, n);

        // Extract maximum elements and build the sorted array
        for (int i = 0; i < n; i++) {
            arr[i] = extractMax(arr, tree, n);
        }
    }

    public static void buildTree(int[] arr, int[] tree, int n) {
        // Initialize the leaf nodes with the array elements
        for (int i = 0; i < n; i++) {
            tree[n - 1 + i] = arr[i];
        }

        // Build the tree by finding maximum values in each pair of nodes
        for (int i = n - 2; i >= 0; i--) {
            tree[i] = Math.max(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    public static int extractMax(int[] arr, int[] tree, int n) {
        int max = tree[0];
        int index = 0;

        // Find the index of the maximum value in the tree
        while (index < n - 1) {
            if (max == tree[2 * index + 1]) {
                index = 2 * index + 1;
            } else {
                index = 2 * index + 2;
            }
        }

        // Replace the maximum value in the tree with negative infinity
        tree[index] = Integer.MIN_VALUE;

        // Return the maximum value (original array value) that was extracted
        return max;
    }
}
