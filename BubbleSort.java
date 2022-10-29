import java.util.Arrays;

class BubbleSort {
    void bubbleSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }

        }
    }
 
    public static void main(String args[])
    {
        BubbleSort ob = new BubbleSort();
        int arr[] = { 27, 84, 89, 71, 99, 35, 50 };
        ob.bubbleSort(arr);
        System.out.println("Sorted array =>");
        System.out.println(Arrays.toString(arr));
    }
}
