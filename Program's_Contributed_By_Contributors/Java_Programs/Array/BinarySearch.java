import java.util.*;

public class BinarySearch {
    public static int binarysearch(int numbers[], int key){
        int start = 0;
        int end = numbers.length-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(numbers[mid]==key){
                return mid;
            }
            if(numbers[mid]<key){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String args[]){
        int numbers[] = {1,2,5,3,8,6,9,10,33,66};
        int key = 10;
        System.out.println("Index of key is: "+ binarysearch(numbers, key));

    }
    
}
