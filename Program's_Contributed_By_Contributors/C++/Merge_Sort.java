import java.lang.*;

class Algo{

    public void mergeSort(int arr[], int start, int end)
    {
        if(end <= start)
            return;
        
        int mid = (start + (end-start)/2);
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }

    public void merge(int arr[], int start, int mid, int end)
    {
        int[] mergedArray = new int[end-start+1];

        int i = start;
        int j = mid + 1;
        int k = 0;

        while(i<=mid && j<=end)
        {
            if(arr[i] < arr[j])
                mergedArray[k++] = arr[i++];
            else
                mergedArray[k++] = arr[j++];
        }

        while(i<=mid)
            mergedArray[k++] = arr[i++];
        

        while(j<=end)
            mergedArray[k++] = arr[j++];

        for(int p=0,q=start;p<mergedArray.length;p++,q++)
        {
            arr[q] = mergedArray[p];
        }
        
    }
}

public class Merge_Sort{
    public static void main(String args[])
    {
        int n[] = {9,8,7,6,5,4,3,2,1};

        System.out.print("Unsorted Array: ");
        for(int i=0;i<n.length;i++)
        {
            System.out.print(n[i]+" ");
        }

        Algo a = new Algo();

        a.mergeSort(n, 0, n.length-1);

        System.out.print("\nSorted Array: ");
        for(int i=0;i<n.length;i++)
        {
            System.out.print(n[i]+" ");
        }
    }
}