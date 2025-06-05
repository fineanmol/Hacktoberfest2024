using System;

class BinarySearch
{
    static int BinarySearchRecursive(int[] arr, int target, int left, int right)
    {
        if (left <= right)
        {
            // Calculate the middle index of the current search range.
            int mid = left + (right - left) / 2;

            // Check if the middle element is the target.
            if (arr[mid] == target)
            {
                return mid;  // Found the target, return its index.
            }

            if (arr[mid] < target)
            {
                // If the middle element is smaller than the target, search the right half.
                return BinarySearchRecursive(arr, target, mid + 1, right);
            }
            else
            {
                // If the middle element is larger than the target, search the left half.
                return BinarySearchRecursive(arr, target, left, mid - 1);
            }
        }

        // If the loop terminates without finding the target, return -1 to indicate not found.
        return -1;
    }

    static int BinarySearch(int[] arr, int target)
    {
        return BinarySearchRecursive(arr, target, 0, arr.Length - 1);
    }

    static void Main(string[] args)
    {
        int[] arr = { 1, 3, 5, 7, 9, 11, 13, 15 };
        int target = 7;
        int result = BinarySearch(arr, target);

        if (result != -1)
        {
            Console.WriteLine($"Target {target} found at index {result}");
        }
        else
        {
            Console.WriteLine($"Target {target} not found in the array.");
        }
    }
}
