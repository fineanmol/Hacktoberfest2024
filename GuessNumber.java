import java.util.*;
class GuessGame {
    int random_number, user_input;
    static int noofGuesses = 0;
    GuessGame() {
        random_number =  (int)(Math.random()*(100-0+1) + 0);
    }
    public void takeUserInput(int n) {
        user_input = n;
        if(user_input>100 || user_input<1) {
            System.out.println("Please choose valid number between 1 to 100");
            System.exit(0);
        }
    }
    public int isCorrectNumber() {
        if(user_input == random_number) {
            return noofGuesses++;
        } else if(user_input > random_number) {
            noofGuesses++;
            System.out.println("\nYour entered number is Greater than the Random Number.\n");
            return 1;
        } else {
            noofGuesses++;
            System.out.println("\nYour entered number is Less than the Random Number.\n");
            return 1;
        }
    }
}
public class GuessNumber {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int u, key;
        System.out.println("***********Hello and Welcome to Number Guessing Game***********");
        System.out.println("Created by Alankrit Agarwal!!!");
        System.out.println("Enjoy the Game and mantain the HighScore!!!!");
        System.out.println("Enjoy the Game and Maintain the HighScore!!!!");
        System.out.println("Please Enter 1 to Continue!!!");
        key = sc.nextInt();
        if(key==1) {
            System.out.println("Enter a Number between 1 to 100: ");
            u = sc.nextInt();
            GuessGame user = new GuessGame();
            user.takeUserInput(u);
            int i = user.isCorrectNumber();
            while(i==1) {
                u = sc.nextInt();
                user.takeUserInput(u);
                i = user.isCorrectNumber();
        }
        System.out.print("\nNo of Guesses: " + (i+1));
        System.out.print("\nYour Score: " + (i+1));
        }
    }
}
