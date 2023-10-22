import java.util.*;
public class LargestElement{
    public static int getLargest(int numbers[]){
        int largest = Integer.MIN_VALUE;
        int smallest = Integer.MAX_VALUE;

        for(int i=0; i<numbers.length;i++){
            if(numbers[i] > largest){
                largest = numbers[i];
            }
            if(numbers[i] < smallest){
                smallest = numbers[i];
            }
        }
        System.out.println("Smallest value is: " +smallest);
        return largest;
    }
    public static void main(String args[]){
        int numbers[] = {1,2,3,6,9,4};
        System.out.println("Largest number: "+getLargest(numbers));
    }
}