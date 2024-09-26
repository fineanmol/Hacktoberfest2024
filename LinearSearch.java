// Code for linearly searching x in arr[].
//If found returns the location.
//If not found returns -1.
public class LinearSearch {
    public static int search(int arr[], int x) {
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            if (arr[i] == x)
                return i;
        }
        return -1;
    }

    // Driver code
    public static void main(String args[]) {
        int arr[] = {11, 41, 47, 108, 490};
        int x = 14;

        // Function call
        int result = search(arr, x);
        if (result == -1)
            System.out.print("Element is not present in array");
        else
            System.out.print("Element is present at index " + result);
    }
}
