// Contributed by sahilkoundal98

import java.util.Random;
import java.util.Scanner;

class Game{
    private int number;

    public Game() {
        Random random = new Random();
        this.number = random.nextInt(101);;
    }

    public int getNumber() {
        return number;
    }

    public int takeUserNumber(){
        System.out.print("Enter your Guessed Number: ");
        Scanner sc = new Scanner(System.in);
        int unumber = sc.nextInt();
        sc.close();
        return unumber;
    }

    public boolean isCorrectNumber(int n){
        if (n == number){
            return true;
        } else if (n>number) {
            System.out.println("Guessed Number is large. Pls try smaller number!!!!");
            return false;
        } else if (n<number) {
            System.out.println("Guessed Number is small. Pls try larger number!!!!");
            return false;
        }
        throw new IllegalArgumentException("Something went wrong");
    }
}
public class GuessTheNumber {
    public static void main(String[] args) {

        System.out.println("Welcome to the Guess the number Game");
        System.out.println("Rules:\n1.You will get five chances\n2.Best of Luck\n");
        int play = 1;
        Game gm = new Game();
        boolean isCorrectNumber = false;

        while (play<=5){
            int usernum = gm.takeUserNumber();
            isCorrectNumber = gm.isCorrectNumber(usernum);
            if (isCorrectNumber){
                System.out.println("CONGRATULATION YOU GUESS THE NUMBER\nGAME OVER");
                break;
            }
            System.out.println("--------------------------------------------------------------");
            play++;
        }
        if (play >= 5){
            System.out.println("YOU LOST\nGAME OVER");
            System.out.println("The Number is: "+gm.getNumber());
        }

    }
}
