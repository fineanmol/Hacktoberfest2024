import java.util.*;
public class SelectionSort{
    public static void sortSelection(int[] array){
        for(int i=0;i<array.length;i++){
            int num = Integer.MAX_VALUE, index = 0;
            for(int j=i;j<array.length;j++){
                if(array[j]<num){
                    num = array[j];
                    index = j;
                }
            }
            int temp = array[i];
            array[i] = num;
            array[index] = temp;
        }
    }
    public static void printArray(int[] arr) {
        System.out.println("The sorted array is: ");
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array: ");
        int n = sc.nextInt();
        System.out.println("Enter elements of array: ");
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        arr[i] = sc.nextInt();
        sortSelection(arr);
        printArray(arr);
        System.out.println();
        sc.close();
    }
}