import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Practical17 extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {

        GridPane root = new GridPane();

        // Set the background color of the Scene to light gray
        Scene scene = new Scene(root, 200, 200);
        scene.setFill(Color.LIGHTGRAY);

        Image img;
        ImageView img_view;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int n = (int) (Math.random() * 2);

                if (n == 0) {
                    FileInputStream fin;
                    fin = new FileInputStream("C://Users//SI//OneDrive//Desktop//java_image/X.gif");
                    img = new Image(fin);
                    img_view = new ImageView(img);
                    root.add(img_view, j, i);
                } else if (n == 1) {
                    FileInputStream fin;
                    fin = new FileInputStream("C://Users//SI//OneDrive//Desktop//java_image/O.gif");
                    img = new Image(fin);
                    img_view = new ImageView(img);
                    root.add(img_view, j, i);
                } else {
                    continue;
                }
            }
        }

        primaryStage.setScene(scene);
        primaryStage.setTitle("Tic-Tac-Toe Board Demo");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
