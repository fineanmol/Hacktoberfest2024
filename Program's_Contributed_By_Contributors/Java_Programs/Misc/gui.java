import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
 
public class driverClass extends Application{
 
public static void main(String[] args) {
// TODO Auto-generated method stub
launch(args);
}
 
@Override
public void start(Stage primaryStage) throws Exception {
// TODO Auto-generated method stub
primaryStage.setTitle("Open Source For You - First program");
TextField textField = new TextField();
Button btn = new Button("Click me to reveal the above text");
btn.setOnAction(new EventHandler<ActionEvent>() {
 
@Override
public void handle(ActionEvent event) {
// TODO Auto-generated method stub
System.out.println("Entered text is " + textField.getText());
textField.clear();
}
});
BorderPane pane = new BorderPane();
pane.setPadding(new Insets(70));
VBox paneCenter = new VBox();
paneCenter.setSpacing(10);
pane.setCenter(paneCenter);
paneCenter.getChildren().add(textField);
paneCenter.getChildren().add(btn);
Scene scene= new Scene(pane, 400, 200);
primaryStage.setScene(scene);
primaryStage.show();
}
 
}
