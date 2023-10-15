using System;

class Program
{
    public static void Main(string[] args)
    {
        int[] arr = { 12, 11, 13, 5, 6, 7 };

        Console.WriteLine("Original Array:");
        PrintArray(arr);

        MergeSort(arr);

        Console.WriteLine("\nSorted Array:");
        PrintArray(arr);
    }

    public static void MergeSort(int[] arr)
    {
        if (arr.Length <= 1) return;

        int middle = arr.Length / 2;
        int[] left = new int[middle];
        int[] right = new int[arr.Length - middle];

        for (int i = 0; i < middle; i++)
        {
            left[i] = arr[i];
        }

        for (int i = middle; i < arr.Length; i++)
        {
            right[i - middle] = arr[i];
        }

        MergeSort(left);
        MergeSort(right);
        Merge(left, right, arr);
    }

    public static void Merge(int[] left, int[] right, int[] arr)
    {
        int leftLength = left.Length;
        int rightLength = right.Length;
        int i = 0, j = 0, k = 0;

        while (i < leftLength && j < rightLength)
        {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        while (i < leftLength)
            arr[k++] = left[i++];

        while (j < rightLength)
            arr[k++] = right[j++];
    }

    public static void PrintArray(int[] arr)
    {
        foreach (var num in arr)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }
}
