using System;

class SelectionSortExample
{
    public static void SelectionSort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void Main(string[] args)
    {
        int[] arr = { 64, 25, 12, 22, 11 };
        
        Console.WriteLine("Original array:");
        foreach (var item in arr)
        {
            Console.Write(item + " ");
        }
        
        SelectionSort(arr);
        
        Console.WriteLine("\nSorted array:");
        foreach (var item in arr)
        {
            Console.Write(item + " ");
        }
    }
}
