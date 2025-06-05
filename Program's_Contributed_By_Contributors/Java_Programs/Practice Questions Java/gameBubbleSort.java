package eteQuestionBank;
import java.util.*;
public class gameBubbleSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        n = sc.nextInt();

        int arr[] = new int[n];

        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        bubbleSort(arr);

        for(int i = 0; i<n; i++){
            System.out.print(arr[i] + " ");
        }
    }

    static void bubbleSort(int[] arr){
        for(int i = 0; i<arr.length; i++){
            for(int j = 1; j<arr.length-i; j++){
                if(arr[j]<arr[j-1]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
    }

}
