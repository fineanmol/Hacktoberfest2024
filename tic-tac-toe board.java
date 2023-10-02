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
        // Create a GridPane for arranging images in a grid layout.
        GridPane root = new GridPane();

        // Declare variables for image and image view.
        Image img;
        ImageView img_view;

        // Loop to generate a 3x3 grid of random X or O images.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Generate a random number (0 or 1).
                int n = (int) (Math.random() * 2);

                if (n == 0) {
                    // Load and display an X image.
                    FileInputStream fin;
                    fin = new FileInputStream("C://Users//SI//OneDrive//Desktop//java_image/X.gif");
                    img = new Image(fin);
                    img_view = new ImageView(img);
                    root.add(img_view, j, i);
                } else if (n == 1) {
                    // Load and display an O image.
                    FileInputStream fin;
                    fin = new FileInputStream("C://Users//SI//OneDrive//Desktop//java_image/O.gif");
                    img = new Image(fin);
                    img_view = new ImageView(img);
                    root.add(img_view, j, i);
                } else {
                    // This condition should never be reached, but it's here for completeness.
                    continue;
                }
            }
        }

        // Create a scene with the GridPane and set its dimensions.
        Scene scene = new Scene(root, 200, 200);
        primaryStage.setScene(scene);

        // Set the title for the stage.
        primaryStage.setTitle("Tic-Tac-Toe Board Demo");

        // Display the stage.
        primaryStage.show();
    }

    public static void main(String[] args) {
        // Launch the JavaFX application.
        launch(args);
    }
}
