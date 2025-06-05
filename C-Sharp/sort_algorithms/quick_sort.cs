using System;

class QuickSort
{
    public static void Main(string[] args)
    {
        int[] arr = { 12, 11, 13, 5, 6, 7 };

        Console.WriteLine("Original Array:");
        PrintArray(arr);

        QuickSortAlgorithm(arr, 0, arr.Length - 1);

        Console.WriteLine("\nSorted Array:");
        PrintArray(arr);
    }

    public static void QuickSortAlgorithm(int[] arr, int low, int high)
    {
        if (low < high)
        {
            int partitionIndex = Partition(arr, low, high);

            QuickSortAlgorithm(arr, low, partitionIndex - 1);
            QuickSortAlgorithm(arr, partitionIndex + 1, high);
        }
    }

    public static int Partition(int[] arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                Swap(arr, i, j);
            }
        }

        Swap(arr, i + 1, high);
        return i + 1;
    }

    public static void Swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
