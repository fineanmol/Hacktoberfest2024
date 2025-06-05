using System;

public class LinearSearchExample
{
    public static int LinearSearch(int[] arr, int target)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] == target)
                return i; // Element found at index i
        }
        return -1; // Element not found
    }

    public static void Main()
    {
        int[] arr = { 10, 25, 5, 15, 30, 20, 35 };
        int target = 15;

        int result = LinearSearch(arr, target);

        if (result != -1)
            Console.WriteLine("Element found at index " + result);
        else
            Console.WriteLine("Element not found in the array.");
    }
}
