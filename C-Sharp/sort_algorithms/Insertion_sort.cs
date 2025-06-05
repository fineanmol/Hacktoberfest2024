using System;

class InsertionSort
{
    static void Main()
    {
        int[] arr = { 12, 11, 13, 5, 6 };
        
        Console.WriteLine("Original Array:");
        PrintArray(arr);

        InsertionSortAlgorithm(arr);

        Console.WriteLine("\nSorted Array:");
        PrintArray(arr);
    }

    static void InsertionSortAlgorithm(int[] arr)
    {
        int n = arr.Length;
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    static void PrintArray(int[] arr)
    {
        foreach (var num in arr)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }
}
