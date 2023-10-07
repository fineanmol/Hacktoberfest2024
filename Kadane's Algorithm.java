import java.util.Scanner;

public class KadanesAlgo {
    
public static void kadanes(int numbers[]){
    int ms = Integer.MIN_VALUE;  // maximum sum
    int cs = 0;  // current sum

    for(int i = 0; i < numbers.length; i++){
        cs = cs + numbers[i];
        if(cs < 0){
            cs = 0;
        }
        ms = Math.max(cs , ms);
    }
    System.out.println("our max subarray sum is : " + ms);
}

public static void main(String args[]){
    Scanner sc = new Scanner(System.in);

    int numbers[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  
    kadanes(numbers);


    sc.close();
}
}

// time complexity O(n)
