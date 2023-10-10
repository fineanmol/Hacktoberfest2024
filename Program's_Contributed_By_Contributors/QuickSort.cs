using System;

class QuickSort
{
    public static void Sort(int[] arr)
    {
        QuickSortRecursive(arr, 0, arr.Length - 1);
    }

    private static void QuickSortRecursive(int[] arr, int left, int right)
    {
        if (left < right)
        {
            int pivotIndex = Partition(arr, left, right);
            QuickSortRecursive(arr, left, pivotIndex - 1);
            QuickSortRecursive(arr, pivotIndex + 1, right);
        }
    }

    private static int Partition(int[] arr, int left, int right)
    {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                Swap(arr, i, j);
            }
        }

        Swap(arr, i + 1, right);
        return i + 1;
    }

    private static void Swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void Main(string[] args)
    {
        int[] arr = { 12, 4, 5, 6, 7, 3, 1, 15 };

        Console.Write("Original Array: ");
        PrintArray(arr);

        Sort(arr);

        Console.Write("Sorted Array: ");
        PrintArray(arr);
    }

    private static void PrintArray(int[] arr)
    {
        foreach (var item in arr)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}
