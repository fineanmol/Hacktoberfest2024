package cars;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Ertiga {
    public void ertigaDet(){
        JFrame f = new JFrame("Ertiga");
        f.setLocation(550, 250);
        f.setSize(450, 350);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);
        JLabel l0 = new JLabel();
        f.add(l0);
        l0.setText("Maruti Ertiga 2020");
        l0.setFont(new Font("", Font.BOLD,14));
        l0.setBounds(50, 10, 1000, 30);

        JLabel l1=new JLabel("Transmission:");
        l1.setBounds(65,50,100,20);
        f.add(l1);
        JLabel l2=new JLabel("Manual");
        l2.setBounds(165,50,100,20);
        f.add(l2);               

        JLabel l3=new JLabel("Fuel:");
        l3.setBounds(65,90,100,20);
        f.add(l3);    
        JLabel l4=new JLabel("Petrol");
        l4.setBounds(165,90,100,20);
        f.add(l4); 

        JLabel l5=new JLabel("Number of seats:");
        l5.setBounds(65,130,100,20);
        f.add(l5);  
        JLabel l6=new JLabel("7");
        l6.setBounds(165,130,100,20);
        f.add(l6);       

        JLabel l7=new JLabel("Charge:");
        l7.setBounds(65,170,100,20);
        f.add(l7);    
        JLabel l8=new JLabel("₹133/hr");
        l8.setBounds(165,170,100,20);
        f.add(l8);     

        JButton b1 = new JButton("Rent");
        f.add(b1);
        b1.setBounds(150,225,100,20);

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog( b1, "The car has been booked, a confirmation mail and other details \n will be sent to your mail! Thank you :)");
                System.exit(0);
            }
        });

        f.setVisible(true);
    }
}