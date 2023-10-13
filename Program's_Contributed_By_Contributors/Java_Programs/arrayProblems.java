import java.util.*;

public class array Problems {
    //program for array rotation
    static void rot(int arr[], int num){
        int array[] = new int[arr.length];
        int k=0;
        for(int i=num;i<arr.length;i++){
            array[k] = arr[i];
            k++;
        }

        for(int i=0;i<num;i++){
            array[k] = arr[i];
            //System.out.println(array[k]);
            k++;
        }

        for(int i=0;i<arr.length;i++){
            arr[i] = array[i];
        }
    }

    //Program for array rotation method 2
    static void rotat(int[]arr,int num){
        int rep =1;
        while (rep<=num){
            int temp = arr[0];
            for(int i=0;i<arr.length-1;i++){
                arr[i] = arr[i+1];
            }
            arr[arr.length-1] = temp;
            rep++;
        }
    }

    // program for reversal algorithm array rotation 
    static void leftRotate(int arr[],int num ){
        int n = arr.length;
        int num2 = num;
        num2 = num2%n;
        revArr(arr, 0, num2-1);
        revArr(arr, num2, n-1);
        revArr(arr, 0 , n-1);
    }
    
    static void revArr(int arr[], int start, int end){
        int temp; 
        while(start<end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    

    //Printing the array
    static void arrayPrint(int arr[]){
        for (int i=0;i<arr.length;i++){
            System.out.println(arr[i]);
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7,8,9};
        leftRotate(arr, 3);
        arrayPrint(arr);

        // rot(arr,2);
        // arrayPrint(arr);
        // int[] arr1 = {1,2,3,4,5};
        // rotat(arr1,4);
        // arrayPrint(arr1);

    }
}
