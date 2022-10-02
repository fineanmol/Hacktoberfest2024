import java.util.Scanner;
import java.util.Random;

public class Rock_Paper {
    private static Scanner sc;

    public static void main(String[] args) {

        // 0 for Rock
        // 1 for Paper
        // 2 for Scissor

        int copwin=0,playwin=0,draw=0,c=0;
        Random random = new Random();
        sc = new Scanner(System.in);

        System.out.print("\n Enter number of matches:");
        int n=sc.nextInt();

        for (int i = 0; i < n; i++) {
            c++;
            System.out.printf("\n\n\t\t\t\t**********MATCH %d OF %d**********",i+1,n);
            System.out.print("\n\t\t Enter 0 for Rock\n\t\t Enter 1 for Paper\n\t\t Enter 2 for Scissor \n");
            int userInput = sc.nextInt();

            int computerInput = random.nextInt(3);

            if (userInput == computerInput) {
                System.out.println("Draw");
                draw++;
            } else if (userInput == 0 && computerInput == 2 || userInput == 1 && computerInput == 0
                    || userInput == 2 && computerInput == 1) {
                System.out.println("You Win!");
                playwin++;
            } else if (userInput>2){
                System.out.println("Invalid Input!!");
                c--;
                break;
            } else {
                System.out.println("Computer Win!");
                copwin++;
            }

            if (computerInput == 0) {
                 System.out.println("Computer choice: Rock");
             } else if (computerInput == 1) {
                 System.out.println("Computer choice: Paper");
             } else {
                 System.out.println("Computer choice: Scissors");
             }
        }
        System.out.println("\nNumber of matches played = "+c);
        System.out.printf("\n\t Your Win=%d \n\t Computer Win=%d \n\t Draw=%d",playwin,copwin,draw);
        if(playwin>copwin){
            System.out.printf("\n\t\t YOU WON THE TOURNAMENT BY %d POINTS!!!",playwin-copwin);
        }
        else if(copwin>playwin){
            System.out.printf("\n\t\t YOU LOST THE TOURNAMENT BY %d POINTS!!!",copwin-playwin);
        }
        else {
            System.out.printf("\n\t\t TOURNAMENT IS DRAW BY %d - %d POINTS!!!",playwin,copwin);
        }
        System.out.println("\n\n\t\t ***************PROGRAM BY VAIBHAV SRIVASTAVA***************");
    }
}
