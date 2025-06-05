// Insertion sort in Java
// LOGIC: INSERT AN ELEMENT FROM UNSORTED ARRAY TO ITS CORRECT POSITION IN SORTED ARRAY
import java.util.Arrays;
class InsertionSort {

    void insertionSort(int array[]) {
        int n = array.length; // n is the size of the array


        for (int i = 1; i < n; i++) {
            int key = array[i];
            int j = i - 1;

            // Compare key with each element on the left of it until an element smaller than
            // it is found.
            // For descending order, change key<array[j] to key>array[j].
            while (j >= 0 && key < array[j]) {
                array[j + 1] = array[j];
                --j;
            }

            // Place key at after the element just smaller than it.
            array[j + 1] = key;
        }
    }

    public static void main(String args[]) {
        int[] values = { 10, 4, 1, 2, 7, 9 };
        InsertionSort is = new InsertionSort();
        is.insertionSort(values);
        System.out.println("Sorted Array: ");
        System.out.println(Arrays.toString(values));
    }
}
