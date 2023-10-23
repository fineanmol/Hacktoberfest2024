


import java.util.*;

public class rock_paper_scissor {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        while(true) {
            String [] availableMoves = {"Rock", "Paper", "Scissors"};
            String computerMove = availableMoves[new Random().nextInt(availableMoves.length)];

            System.out.println("Computer has chosen it's move.");
            System.out.println();
            System.out.println("Now it's your turn to choose. Good Luck!");
            System.out.println();


            String userMove;

            while(true) {
                System.out.println("Please choose your move from these available moves : 'Rock' 'Paper' 'Scissors' ");
                System.out.println("Enter the move you chose : ");
                userMove = scn.nextLine();

                if(userMove.equals("Rock") || userMove.equals("Paper") || userMove.equals("Scissors")){
                    System.out.println();
                    break;
                }

                System.out.println();
                System.out.println("Invalid Move!!");
                System.out.println("Please enter the move from the available moves only!");
                System.out.println();
            }


            System.out.println("Computer chose : " + computerMove);


            if(userMove.equals(computerMove)) {
                System.out.println("Its a tie!");
            }


            else if(userMove.equals("Rock")) {

                if(computerMove.equals("Paper")) {
                    System.out.println("Computer won!");
                    System.out.println("Better luck next time!");
                }
                else if(computerMove.equals("Scissors")) {
                    System.out.println("You won!");
                    System.out.println("Congratulations!");
                }
            }

            else if(userMove.equals("Paper")) {

                if(computerMove.equals("Rock")) {
                    System.out.println("You won!");
                    System.out.println("Congratulations!");
                }
                else if(computerMove.equals("Scissors")) {
                    System.out.println("Computer won!");
                    System.out.println("Better luck next time!");
                }
            }

            else if(userMove.equals("Scissors")) {

                if(computerMove.equals("Paper")) {
                    System.out.println("You won!");
                    System.out.println("Congratulations!");
                }
                else if(computerMove.equals("Rock")) {
                    System.out.println("Computer won!");
                    System.out.println("Better luck next time!");
                }
            }

            System.out.println();
            String playAgain;
            System.out.println("Do you want to play again? ");

            while(true) {

                System.out.println("Type 'yes' or 'no' ");
                playAgain = scn.nextLine();

                if(playAgain.equals("yes") || playAgain.equals("Yes") || playAgain.equals("no") || playAgain.equals("No")) {
                    System.out.println();
                    System.out.println("*****************************************************************************");
                    System.out.println();
                    break;
                }
                System.out.println();
                System.out.println("Invalid Input");
                System.out.println();
            }

            if(playAgain.equals("no") || playAgain.equals("No")) {
                break;
            }
        }
    }
}
