import javax.swing.*;

public class swing extends JFrame {

    public swing() {
        setTitle("GUI Example");

  ImageIcon icon = new ImageIcon("a.jpg");  // Replace "icon.png" with the path to your icon image
        setIconImage(icon.getImage());
        JLabel usernameLabel = new JLabel("Username:");
        usernameLabel.setBounds(50, 50, 80, 30);
        add(usernameLabel);

        JTextField usernameField = new JTextField();
        usernameField.setBounds(140, 50, 150, 30);
        add(usernameField);

        JLabel passwordLabel = new JLabel("Password:");
        passwordLabel.setBounds(50, 100, 80, 30);
        add(passwordLabel);

        JPasswordField passwordField = new JPasswordField();
        passwordField.setBounds(140, 100, 150, 30);
        add(passwordField);

        JButton loginButton = new JButton("Login");
        loginButton.setBounds(150, 150, 100, 30);
        add(loginButton);
        setSize(400, 400);
        setLayout(null);
        setVisible(true);

    }

    public static void main(String[] args) {
        swing example = new swing();
    }
}
