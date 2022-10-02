import java.util.Arrays;
import java.util.Scanner;

class MergeSort
{
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int [n1];
        int R[] = new int [n2];

        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];

        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergesort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2;

            mergesort(arr, l, m);
            mergesort(arr , m+1, r);

            merge(arr, l, m, r);
        }
    }

    public static void main(String args[])
    {
       Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of the array :");
       int size = sc.nextInt();
       int arr[] = new int[size];
        System.out.println("Enter elements into the array: ");
        for(int i= 0;i<size;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Array Before sorting : ");
        System.out.println(Arrays.toString(arr));

        MergeSort ob = new MergeSort();
        ob.mergesort(arr, 0, arr.length-1);

        System.out.println("Array After Sorting: ");
        System.out.println(Arrays.toString(arr));
    }
}