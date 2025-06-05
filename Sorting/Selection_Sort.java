//Selection Sort repeatedly finds the minimum element and moves it to the beginning of the list.
//Time Complexity: O(n²)

// Selection Sort algorithm:

// Divide the list into two parts:

// The sorted part (initially empty).
// The unsorted part (the entire array at first).
// Find the minimum element:

// From the unsorted part, identify the smallest element.
// Swap:

// Swap the smallest element with the first element of the unsorted part.
// Move boundary:

// The first element of the unsorted part becomes part of the sorted portion.
// Repeat:

// Repeat steps 2-4 for the remaining unsorted part until the entire array is sorted.
// The process continues until all elements are sorted in ascending order.

//Code
public class Selection_Sort {
    static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            // Swap the found minimum element with the first element
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};
        selectionSort(arr);
        System.out.println("Sorted array: ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
