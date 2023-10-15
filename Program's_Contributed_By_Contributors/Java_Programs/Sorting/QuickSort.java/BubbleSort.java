public class BubbleSort {
    public static void main(String[] args){
        System.out.println("Bubble Sort");
        int[] arr = new int[]{20, 90, 15, 19, 84, 51, 36, 2, 40, 7};
        int[] sorted_arr;
        sorted_arr = bubbleSort(arr);
        for (int j : sorted_arr) {
            System.out.println(j + " ");
        }
        System.out.println("Program End!");
    }
    public static int[] bubbleSort(int[] array){
        for(int i = 0; i < array.length - 1; i++){
            for(int j = 0; j < array.length - i - 1; j++){
                if(array[j] < array[j+1]){
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
        return array;
    }
}
