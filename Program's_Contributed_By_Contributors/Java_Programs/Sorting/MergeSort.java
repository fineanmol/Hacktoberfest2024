// merge sort in java
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// Stable: Yes
// In-Place: No
class Solution{
    public static void main(String[] args){
        int[] arr = {5, 4, 3, 2, 1};
        mergeSort(arr, 0, arr.length - 1);
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
    public static void mergeSort(int[] arr, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }
    public static void merge(int[] arr, int start, int mid, int end){
        int[] temp = new int[end - start + 1];
        int i = start;
        int j = mid + 1;
        int k = 0;
        while(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
            }
            else{
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i <= mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j <= end){
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(int l = 0; l < temp.length; l++){
            arr[start + l] = temp[l];
        }
    }
}
