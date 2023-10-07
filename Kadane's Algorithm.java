import java.util.Scanner;

public class KadanesAlgo {
    
public static int kadanes(int numbers[]){
    int maximumSum = Integer.MIN_VALUE;  
    int currentSum = 0;  

    for(int i = 0; i < numbers.length; i++){
        currentSum = currentSum + numbers[i];
        if(currentSum < 0){
           currentSum = 0;
        }
        maximumSum = Math.max(currentSum ,maximumSum);
    }
    return maximumSum;
}

public static void main(String args[]){
    Scanner sc = new Scanner(System.in);

    int numbers[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  
    int maxSum = kadanes(numbers);
    System.out.println("Maximum Sum of Sub-Array is : " + maxSum);


    sc.close();
}
}


