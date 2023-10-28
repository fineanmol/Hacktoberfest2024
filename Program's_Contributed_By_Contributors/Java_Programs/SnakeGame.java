import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.Random;

public class SnakeGame extends JPanel implements ActionListener, KeyListener {

    private static final int GAME_WIDTH = 1500;
    private static final int GAME_HEIGHT = 800;
    private static final int SPEED = 90;
    private static final int SPACE_SIZE = 50;
    private static final int BODY_PARTS = 3;
    private static final Color SNAKE_COLOR = new Color(0, 255, 0);
    private static final Color FOOD_COLOR = new Color(255, 0, 0);
    private static final Color BACKGROUND_COLOR = new Color(0, 0, 0);

    private ArrayList<Point> snake;
    private Point food;
    private char direction;
    private int score;

    public SnakeGame() {
        setPreferredSize(new Dimension(GAME_WIDTH, GAME_HEIGHT));
        setBackground(BACKGROUND_COLOR);
        setFocusable(true);
        addKeyListener(this);

        snake = new ArrayList<>();
        direction = 'd'; // Start by moving right
        score = 0;

        initializeGame();
        Timer timer = new Timer(SPEED, this);
        timer.start();
    }

    private void initializeGame() {
        snake.clear();
        for (int i = 0; i < BODY_PARTS; i++) {
            snake.add(new Point(0, 0));
        }
        spawnFood();
    }

    private void spawnFood() {
        Random rand = new Random();
        int x = rand.nextInt(GAME_WIDTH / SPACE_SIZE) * SPACE_SIZE;
        int y = rand.nextInt(GAME_HEIGHT / SPACE_SIZE) * SPACE_SIZE;
        food = new Point(x, y);
    }

    private void move() {
        Point head = snake.get(0);
        Point newHead = (Point) head.clone();

        if (direction == 'w') {
            newHead.translate(0, -SPACE_SIZE);
        } else if (direction == 's') {
            newHead.translate(0, SPACE_SIZE);
        } else if (direction == 'a') {
            newHead.translate(-SPACE_SIZE, 0);
        } else if (direction == 'd') {
            newHead.translate(SPACE_SIZE, 0);
        }

        snake.add(0, newHead);

        if (newHead.equals(food)) {
            score++;
            spawnFood();
        } else {
            snake.remove(snake.size() - 1);
        }
    }

    private boolean checkCollision() {
        Point head = snake.get(0);

        if (head.x < 0 || head.x >= GAME_WIDTH || head.y < 0 || head.y >= GAME_HEIGHT) {
            return true; // Hit the wall
        }

        for (int i = 1; i < snake.size(); i++) {
            if (head.equals(snake.get(i))) {
                return true; // Collided with itself
            }
        }

        return false;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        move();
        if (checkCollision()) {
            gameOver();
        }
        repaint();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(SNAKE_COLOR);
        for (Point p : snake) {
            g.fillRect(p.x, p.y, SPACE_SIZE, SPACE_SIZE);
        }
        g.setColor(FOOD_COLOR);
        g.fillOval(food.x, food.y, SPACE_SIZE, SPACE_SIZE);
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.PLAIN, 40));
        g.drawString("Score: " + score, 20, 40);
    }

    private void gameOver() {
        JOptionPane.showMessageDialog(this, "Game Over! Your Score: " + score);
        initializeGame();
        direction = 'd'; // Start by moving right again
        score = 0;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();
        if ((key == KeyEvent.VK_W || key == KeyEvent.VK_UP) && direction != 's') {
            direction = 'w';
        } else if ((key == KeyEvent.VK_S || key == KeyEvent.VK_DOWN) && direction != 'w') {
            direction = 's';
        } else if ((key == KeyEvent.VK_A || key == KeyEvent.VK_LEFT) && direction != 'd') {
            direction = 'a';
        } else if ((key == KeyEvent.VK_D || key == KeyEvent.VK_RIGHT) && direction != 'a') {
            direction = 'd';
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void keyReleased(KeyEvent e) {
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Snake Game");
        SnakeGame snakeGame = new SnakeGame();
        frame.add(snakeGame);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
