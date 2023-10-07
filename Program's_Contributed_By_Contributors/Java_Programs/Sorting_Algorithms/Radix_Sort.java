import java.util.Scanner;

public class Radix_Sort 
{
    /** Radix Sort function **/
    public static void sort( int[] a)
    {
        int i, m = a[0], exp = 1, n = a.length;
        int[] b = new int[n];
        for (i = 1; i < n; i++)
            if (a[i] > m)
                m = a[i];
        while (m / exp > 0)
        {
            int[] bucket = new int[10];
 
            for (i = 0; i < n; i++)
                bucket[(a[i] / exp) % 10]++;
            for (i = 1; i < 10; i++)
                bucket[i] += bucket[i - 1];
            for (i = n - 1; i >= 0; i--)
                b[--bucket[(a[i] / exp) % 10]] = a[i];
            for (i = 0; i < n; i++)
                a[i] = b[i];
            exp *= 10;        
        }
    }    
    public static void main(String[] args) 
    {
        try (Scanner scan = new Scanner( System.in )) {
            System.out.println("Radix Sort Test\n");
            int n, i;
            /** Accept number of elements **/
            System.out.println("Enter number of integer elements");
            n = scan.nextInt();
            /** Create integer array on n elements **/
            int arr[] = new int[ n ];
            /** Accept elements **/
            System.out.println("\nEnter "+ n +" integer elements");
            for (i = 0; i < n; i++)
                arr[i] = scan.nextInt();
            /** Call method sort **/
            sort(arr);
            /** Print sorted Array **/
            System.out.println("\nElements after sorting ");        
            for (i = 0; i < n; i++)
                System.out.print(arr[i]+" ");
        }        
        System.out.println();                     
    }    
}
