import java.sql.SQLOutput;
import java.util.Scanner;
import java.util.SplittableRandom;

public class TicTacToe {
    private Player player1, player2;
    private Board board;

    public void startGame() {
        // Take Player input
        Scanner s = new Scanner(System.in);
        player1 = takePlayerInput(1);
        player2 = takePlayerInput(2);

        while(player1.getSymbol()== player2.getSymbol()) {
            System.out.println("Symbol already taken | Select another symbol: ");
            player2.setSymbol(s.next().charAt(0));
        }

        // Create Board
        board = new Board(player1.getSymbol(), player2.getSymbol());

        // Start the game
        boolean player1Turn = true;
        int status = Board.INCOMPLETE;
        while(status==Board.INCOMPLETE||status==Board.INVALID) {
            if(player1Turn) {
                System.out.println("Player 1 - " + player1.getName() + "'s turn");
                System.out.println("Enter x y: ");
                int x = s.nextInt();
                int y = s.nextInt();
                status = board.move(player1.getSymbol(), x ,y);
                // 1 p1 won -- 2 p2 won -- 3 draw -- 4 incomplete -- 5 invalid
                if(status==Board.INVALID) {
                    System.out.println("Move invalid - Try Again :) ");
                } else {
                    board.print();
                    player1Turn = false;
                }
            } else {
                System.out.println("Player 2 - " + player2.getName() + "'s turn");
                System.out.println("Enter x y: ");
                int x = s.nextInt();
                int y = s.nextInt();
                status = board.move(player2.getSymbol(), x ,y);
                // 1 p1 won -- 2 p2 won -- 3 draw -- 4 incomplete -- 5 invalid
                if(status==Board.INVALID) {
                    System.out.println("Move invalid - Try Again :) ");
                } else {
                    board.print();
                    player1Turn = true;
                }
            }
        }
        if(status==Board.PLAYER_1_WINS) {
            System.out.println("Player 1 "+player1.getName()+" won! 🔥");
        } else if (status==Board.PLAYER_2_WINS) {
            System.out.println("Player 2 "+player2.getName()+" won! 🔥");
        } else {
            System.out.println("DRAW! 🎨");
        }

    }

    private Player takePlayerInput(int num) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter Player "+num+" name: ");
        String name = s.nextLine();
        System.out.println("Enter Player "+num+" Symbol: ");
        char symbol = s.next().charAt(0);
        return new Player(name, symbol);
    }
}
