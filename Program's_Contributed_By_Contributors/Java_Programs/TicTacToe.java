package prjts;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TicTacToe extends JFrame implements ActionListener {

    private JButton[][] buttons = new JButton[3][3];
    private boolean player1Turn = true;
    private JLabel message = new JLabel("Player 1's turn");
    private int player1Score = 0;
    private int player2Score = 0;
    private JLabel scoreLabel = new JLabel("Score: " + player1Score + " - " + player2Score);

    public TicTacToe() {
        super("Tic Tac Toe");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel gamePanel = new JPanel();
        gamePanel.setLayout(new GridLayout(3, 3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                buttons[row][col] = new JButton();
                buttons[row][col].addActionListener(this);
                buttons[row][col].setFont(new Font("Arial", Font.PLAIN, 80));
                gamePanel.add(buttons[row][col]);
            }
        }
        add(gamePanel, BorderLayout.CENTER);

        JPanel statusPanel = new JPanel();
        statusPanel.setLayout(new GridLayout(1, 3));
        statusPanel.add(message);
        statusPanel.add(scoreLabel);
        JButton newGameButton = new JButton("New Game");
        newGameButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                resetGame();
            }
        });
        statusPanel.add(newGameButton);
        add(statusPanel, BorderLayout.SOUTH);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton)e.getSource();
        if (button.getText().equals("")) {
            if (player1Turn) {
                button.setText("X");
                message.setText("Player 2's turn");
            } else {
                button.setText("O");
                message.setText("Player 1's turn");
            }
            player1Turn = !player1Turn;
            if (checkForWin()) {
                if (player1Turn) {
                    message.setText("Player 2 wins!");
                    player2Score++;
                } else {
                    message.setText("Player 1 wins!");
                    player1Score++;
                }
                updateScore();
                disableButtons();
            } else if (checkForDraw()) {
                message.setText("It's a draw!");
                disableButtons();
            }
        }
    }

    private boolean checkForWin() {
        String[][] board = new String[3][3];
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                board[row][col] = buttons[row][col].getText();
            }
        }

        // Check rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0].equals(board[row][1]) && board[row][1].equals(board[row][2]) && !board[row][0].equals("")) {
                return true;
            }
        }

        // Check columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col].equals(board[1][col]) && board[1][col].equals(board[2][col]) && !board[0][col].equals("")) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0].equals(board[1][1]) && board[1    ][1].equals(board[2][2]) && !board[0][0].equals("")) {
            return true;
        }
        if (board[0][2].equals(board[1][1]) && board[1][1].equals(board[2][0]) && !board[0][2].equals("")) {
            return true;
        }
    
        return false;
    }
    
    private boolean checkForDraw() {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (buttons[row][col].getText().equals("")) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void resetGame() {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                buttons[row][col].setText("");
                buttons[row][col].setEnabled(true);
            }
        }
        player1Turn = true;
        message.setText("Player 1's turn");
    }
    
    private void disableButtons() {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                buttons[row][col].setEnabled(false);
            }
        }
    }
    
    private void updateScore() {
        scoreLabel.setText("Score: " + player1Score + " - " + player2Score);
    }
    
    public static void main(String[] args) {
        new TicTacToe();
    }
}
    