// Insertion Sort builds a sorted list one element at a time by comparing and inserting elements in their correct positions.
// Time Complexity: O(n²)

// Insertion Sort:
// Start with the second element:

// Treat the first element as a sorted sublist of one element.
// Compare the second element with the first one and place it in the correct position.
// Move to the next element:

// Pick the next element from the unsorted part and compare it with elements in the sorted part.
// Shift elements if necessary:

// If the new element is smaller than elements in the sorted part, shift the larger elements one position to the right to make space for the new element.
// Insert the element:

// Place the element in its correct position in the sorted sublist.
// Repeat:

// Repeat the process for each element in the unsorted part until the entire array is sorted.


//Code
public class InsertionSort {
    static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            
            // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6};
        insertionSort(arr);
        System.out.println("Sorted array: ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
