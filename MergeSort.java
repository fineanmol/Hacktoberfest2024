public class MergSort {
   
    public static void mergeSort(int arr[], int si, int ei) { // Time C = O(nlogn)
        // Base class                                         // Space C = O(n)
        if(si >= ei) {
            return;
        }
        // doing work
        int mid = si + (ei - si)/2;
        mergeSort(arr, si, mid); // left
        mergeSort(arr, mid+1, ei); // right
        // last step to merg the left and right sorted arr
        merge(arr, si, mid, ei);
    }

    public static void merge(int arr[], int si, int mid, int ei) { // function for merge
        // we make a temp array of size ei-si+1
        int temp[] = new int[ei-si+1];
        
        int i = si; // initialzing with si - iterator for left part
        int j = mid+1; // initialzing with mid+1 - iterator for right part
        int k = 0; // initialzing with 0 - iterator for temp arr

        while( i <= mid && j <= ei) {
            if(arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
                //k++;
            } else {
                temp[k] = arr[j];
                j++;
                //k++
            }
            k++;
        }
        while(i <= mid) { // if any element left in the left part
            temp[k++] = arr[i++];
        }
        while(j <= ei) { // if any element left in the right part
            temp[k++] = arr[j++];
        }
        // now copy tem to my original arr
        for(k=0, i=si; k < temp.length; k++, i++) {
            arr[i] = temp[k];
        }
    }

    public static void printArr(int arr[]) { // for printing our original and sorted arr
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int arr[] = { 6, 3, 9, 5, 2, 8 };
        mergeSort(arr, 0, arr.length-1);
        printArr(arr);

    }

}
