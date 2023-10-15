import java.awt.event.*;
import javax.swing.*;


public class Signup {
    public void signupRegister(){
        JFrame f = new JFrame("Sign Up");
        f.setLocation(600, 200);
        f.setSize(300,400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);

        JLabel l1=new JLabel("Full Name:");
        l1.setBounds(10, 10, 100, 30);
        f.add(l1);
        JTextField t1=new JTextField();
        t1.setBounds(75, 15, 200, 20);
        f.add(t1);
        

        JLabel l2=new JLabel("Gender:");
        l2.setBounds(10, 50, 100, 30);
        f.add(l2);
        JRadioButton r1 = new JRadioButton("Male");
        JRadioButton r2 = new JRadioButton("Female");
        ButtonGroup g = new ButtonGroup();
        g.add(r1);
        g.add(r2);
        r1.setBounds(70,50,80,30);
        r2.setBounds(150,50,100,30);
        f.add(r1);
        f.add(r2);


        JLabel l3=new JLabel("Age:");
        l3.setBounds(10, 90, 100, 30);
        f.add(l3);        
        JTextField t2=new JTextField();
        t2.setBounds(75, 95, 200, 20);
        f.add(t2);


        JLabel l4=new JLabel("Email ID:");
        l4.setBounds(10, 130, 100, 30);
        f.add(l4);
        JTextField t3=new JTextField();
        t3.setBounds(75, 135, 200, 20);
        f.add(t3);


        JLabel l5=new JLabel("Phone:");
        l5.setBounds(10, 170, 100, 30);
        f.add(l5);        
        JTextField t4=new JTextField();
        t4.setBounds(75, 175, 200, 20);
        f.add(t4);


        JLabel l6=new JLabel("Username:");
        l6.setBounds(10, 210, 100, 30);
        f.add(l6);        
        JTextField t5=new JTextField();
        t5.setBounds(75, 215, 200, 20);
        f.add(t5);


        JLabel l7=new JLabel("Password:");
        l7.setBounds(10, 250, 100, 30);
        f.add(l7);        
        JTextField t6=new JTextField();
        t6.setBounds(75, 255, 200, 20);
        f.add(t6);


        JButton b1 = new JButton("Save");
        b1.setBounds(100,300,100,20);
        f.add(b1);

        b1.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent e) {;
                JOptionPane.showMessageDialog(f,"Welcome, you are being redirected to Home Page!");
                f.setVisible(false);
                Rent reg = new Rent();
                reg.rentACar();
            }
        });
        
        f.setVisible(true);
    } 
}
