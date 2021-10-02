// Code for Binary Search in Java
// Assume array is sorted
// Array is divided into two parts
// Based on the position of mid
// If element is found returns the index
// Else returns -1
class BinarySearch{
    int bSearch(int arr[], int left, int right, int element)
    {
        if (right >= left) {
            int mid = left + (right - left) / 2;

            // If the element is present at mid
            if (arr[mid] == element)
                return mid;

            // If element is smaller than mid
            // search in left subarray
            if (arr[mid] > element)
                return bSearch(arr, left, mid - 1, element);

            // If element is greater than mid
            // search in right subarray
            return bSearch(arr, mid + 1, right, element);
        }

        // If not found, return -1
        return -1;
    }

    // Driver code to test
    public static void main(String args[])
    {
        BinarySearch elt = new BinarySearch();
        int arr[] = { 5, 10, 70, 100, 499 };
        int size = arr.length;
        int x = 5;
        int result = elt.bSearch(arr, 0, size - 1, x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index " + result);
    }
}
