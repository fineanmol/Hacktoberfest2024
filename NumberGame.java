import java.util.*;

public class NumberGame{
    public static void main (String args[]){

        int round = 0;
        int attempt = 0 ;
        boolean hasGuessed = false;

        // logic to generate random number between 1 to 100
        
        Random random = new Random();
        int rn = random.nextInt(100)+1;

        // logic for guessing the number

        Scanner sc = new Scanner(System.in);
        System.out.println("Number of rounds = 2\nNumber of attempts per round = 3\n");
        
        for (int i = 0 ; i<2 ; i++){
            round++;
            for (int j = 0 ; j<3 ; j++){
                System.out.println("Guess a number\n");
                int number = sc.nextInt();
                attempt++;

                if(number > rn)
                   System.out.println("Guess is too high\n");
                else if (number < rn)
                   System.out.println("Guess is too low\n");
                else{
                    System.out.println("Guess is correct\n");
                    hasGuessed = true;
                    break;
                }   
            }
            if(hasGuessed){
               System.out.printf("Rounds = %d \n Number of attempts taken = %d \n",round,attempt);
               break;
            }
            else{
                System.out.printf("Round %d failed \n", round);
                attempt=0;
               continue;
            }
        }
        if(hasGuessed==false)
          System.out.printf("The number was %d",rn);

          sc.close();
    }
}
