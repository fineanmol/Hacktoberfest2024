using System;

class Program
{
    // Binary search function
    public static int BinarySearch(int[] arr, int target)
    {
        int left = 0;
        int right = arr.Length - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return mid; // Element found
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1; // Element not found
    }

    static void Main(string[] args)
    {
        int[] sortedArray = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
        int target = 12;

        int result = BinarySearch(sortedArray, target);

        if (result != -1)
        {
            Console.WriteLine($"Element {target} found at index {result}.");
        }
        else
        {
            Console.WriteLine($"Element {target} not found in the array.");
        }
    }
}
