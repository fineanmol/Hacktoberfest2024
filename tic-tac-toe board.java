package practical17;

import java.io.FileInputStream;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class Practical17 extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        // Create a GridPane layout for the game board
        GridPane root = new GridPane();

        Image img;
        ImageView img_view;

        // Loop to populate the game board with X or O randomly
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Generate a random number (0 or 1) to decide between X and O
                int n = (int) (Math.random() * 2);

                if (n == 0) {
                    // Load the X image
                    FileInputStream fin = new FileInputStream("C://Users//SI//OneDrive//Desktop//java_image/X.gif");
                    img = new Image(fin);
                    img_view = new ImageView(img);
                    root.add(img_view, j, i); // Add the X image to the GridPane
                } else if (n == 1) {
                    // Load the O image
                    FileInputStream fin = new FileInputStream("C://Users//SI//OneDrive//Desktop//java_image/O.gif");
                    img = new Image(fin);
                    img_view = new ImageView(img);
                    root.add(img_view, j, i); // Add the O image to the GridPane
                } else {
                    // Continue to the next iteration if n is neither 0 nor 1
                    continue;
                }
            }
        }

        // Create a scene to display the game board
        Scene scene = new Scene(root, 200, 200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Tic-Tac-Toe Board Demo");

        // Show the stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        // Launch the JavaFX application
        launch(args);
    }
}
