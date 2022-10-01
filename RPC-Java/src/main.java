import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;

public class rps {

    static String userName;
    static ArrayList<String> gameElements;
    static Scanner userInput = new Scanner(System.in);
    static int userPoints;
    static int compPoints;

    public static void main(String[] args) {

        gameElements = new ArrayList<String>();
        gameElements.add("rock");
        gameElements.add("paper");
        gameElements.add("scissor");

        System.out.println("Enter your name: ");
        userName = userInput.nextLine();

        System.out.println("Enter the number of rounds: ");
        int gameRounds = userInput.nextInt();

        for (int i=0; i < gameRounds; i++) {
            gameLogic();
        }

        System.out.println(userName + "'s points: " + userPoints);
        System.out.println("Computer's points: " + compPoints);

        if (userPoints > compPoints) {
            System.out.println(userName + " wins the game!");
        } else if (compPoints > userPoints) {
            System.out.println("Computer wins the game!");
        } else {
            System.out.println("It's a draw");
        }
    }

    public static void gameLogic() {
        Random random = new Random();
        int compMove = random.nextInt(3);
        System.out.println("Your move: ");
        String userMove = userInput.next();
        if (userMove.toLowerCase().equals(gameElements.get(compMove))) {
            System.out.println(userName + ": " + userMove);
            System.out.println("Computer: " + gameElements.get(compMove));
            System.out.println("It's a draw");
        } else if (
         userMove.toLowerCase().equals("rock") && gameElements.get(compMove).equals("paper")
         || userMove.toLowerCase().equals("paper") && gameElements.get(compMove).equals("scissor")
         || userMove.toLowerCase().equals("scissor") && gameElements.get(compMove).equals("rock")
        ) {
            System.out.println(userName + ": " + userMove);
            System.out.println("Computer: " + gameElements.get(compMove));
            System.out.println("Computer wins!");
            ++compPoints;
        } else if (
         userMove.toLowerCase().equals("paper") && gameElements.get(compMove).equals("rock")
         || userMove.toLowerCase().equals("rock") && gameElements.get(compMove).equals("scissor")
         || userMove.toLowerCase().equals("scissor") && gameElements.get(compMove).equals("paper")
        ) {
            System.out.println(userName + " :" + userMove);
            System.out.println("Computer: " + gameElements.get(compMove));
            System.out.println(userName + " wins!");
            ++userPoints;
        } else {
            System.out.println("Invalid Input");
        }
    }
}
