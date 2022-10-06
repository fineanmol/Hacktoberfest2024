public class InsertionSort{
    public void insertionSort(int [] arr){
        for (int i = 1 ; i<arr.length ; i++){
            int j = i-1;
            int x = arr[i];
            while(j>=0 && arr[j]>x){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = x;
        }
    }
}
