package eteQuestionBank;
import java.util.*;

public class zeroSumSubarray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] str = sc.nextLine().split(" ");
        int[] arr = new int[str.length];

        for(int i = 0; i< arr.length; i++){
            arr[i] = Integer.parseInt(str[i]);
        }

        zeroSubArray(arr);
    }

    static void print(int[] arr, int s, int e){
        for(int i = s; i<=e; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static void zeroSubArray(int[] arr){
        for(int i = 0; i<arr.length; i++){
            int sum = 0;
            for(int j = i; j< arr.length; j++){
                sum = sum + arr[j];
                if(sum==0){
                    print(arr, i, j);
                }
            }
        }
    }


















//    static void findZeroSumSubarrays(int[] arr) {
//        for (int i = 0; i < arr.length; i++) {
//            int sum = 0;
//            for (int j = i; j < arr.length; j++) {
//                sum += arr[j];
//                if (sum == 0) {
//                    printSubarray(arr, i, j);
//                }
//            }
//        }
//    }
//
//    public static void printSubarray(int[] arr, int i, int j) {
//        for (int start = i; start <= j; start++) {
//            System.out.print(arr[start] + " ");
//        }
//        System.out.println();
//    }
//
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        String[] input = sc.nextLine().split(" ");
//        int[] in = new int[input.length];
//        for (int i = 0; i < in.length; i++) {
//            in[i] = Integer.parseInt(input[i]);
//        }
//        findZeroSumSubarrays(in);
//    }
}
