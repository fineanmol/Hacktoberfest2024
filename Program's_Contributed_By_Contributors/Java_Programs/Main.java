package com.sharan;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	int[] arr = {1,2,3};
        System.out.println(Arrays.toString(minimumChocolates(arr)));
    }

    static int[] minimumChocolates(int[] arr) {
     int[] chocolates = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            chocolates[i] = 1;
        }
        for (int j = 0; j < chocolates.length; j++) {
           if (j != arr.length-1){
               if (arr[j] > arr[j+1]){
                   chocolates[j] += 1;
               }
               else if(arr[j] == arr[j+1]) {
                   System.out.println("Same");
               }
               else{
                   chocolates[j+1] += 1;
               }
           }
           if ( j+1 != arr.length && j-1!= -1 && chocolates[j] == chocolates[j-1] && arr[j] != arr[j+1] ){
               chocolates[j] += 1;
           }
        }
        return chocolates;
    }

}
