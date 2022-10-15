
public class SelectionSort {
    public static void SelectionSort(int input[]){

        for (int i=0; i<input.length-1; i++){ // 0 to n-2 (these are no. of rounds for selecting minimum element)
            int min = input[i];
            int minIndex = i;
            for (int j=i+1; j<input.length; j++){

                if (input[j] < min) {
                    min = input[j];
                    minIndex = j;
                }
            }
            // for swapping the elements
            if (minIndex != i){
                input[minIndex] = input[i];         // swap krenge min element aur ith element ko
                input[i] = min;        // min ki value update krenge aise
            }

        }
    }

    public static void main(String[] args) {

        int arr[] = {5,3,1,2,4};
        SelectionSort(arr);
        for (int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }

    }

}

    

