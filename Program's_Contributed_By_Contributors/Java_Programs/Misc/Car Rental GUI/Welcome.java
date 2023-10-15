import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Welcome {
    public static void main(String[] args) throws Exception{
        
        JFrame f = new JFrame("CAR RENTAL SERVICES!");
        f.setLocation(550, 250);
        f.setSize(465, 350);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);
        JLabel l0 = new JLabel();
        f.add(l0);
        l0.setText("Welcome to Car Rental Services!");
        l0.setFont(new Font("Arial", Font.BOLD,20));
        l0.setBounds(50, 10, 1000, 30);

        JLabel l1 = new JLabel("Username:");
        f.add(l1);
        l1.setBounds(75,100,100,20);
        JTextField t1 = new JTextField(10);
        f.add(t1);
        t1.setBounds(150,100,150,20);
        
        JLabel l2 = new JLabel("Password:");
        f.add(l2);
        l2.setBounds(75,150,100,20);
        JTextField t2 = new JTextField(10);
        f.add(t2);
        t2.setBounds(150,150,150,20);

        JButton b1 = new JButton("Login");
        f.add(b1);
        b1.setBounds(150,225,100,20);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String s1=t1.getText();
                String s2=t2.getText();
                if(s1.equals("Joe") && s2.equals("1018") || (s1.equals("Alwin") && s2.equals("1050"))){
                    JOptionPane.showMessageDialog(f,"Welcome "+s1+ ". You are being redirected to the Home Page!");
                    f.dispose();
                    Rent reg = new Rent();
                    reg.rentACar();
                }
                else{
                    JOptionPane.showMessageDialog(f, "Login Unsuccessful. If you don't have an account, please sign up!");
                }
            }
        });

        JButton b2 = new JButton("Signup");
        f.add(b2);
        b2.setBounds(350,50,100,20);
        b2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                    f.dispose();
                    Signup r = new Signup();
                    r.signupRegister();
            }           
        });
        f.setVisible(true);
    }
}