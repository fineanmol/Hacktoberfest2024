import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
import cars.*;

public class Available {
    public void avlCars(){
        JFrame f = new JFrame("VIEW AVAILABLE CARS!");
        f.setLocation(300, 50);
        f.setSize(850, 700);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);

        JLabel l0 = new JLabel();
        f.add(l0);
        l0.setText("Pick your desired car!");
        l0.setFont(new Font("", Font.BOLD,16));
        l0.setBounds(50, 10, 1000, 30);

        ImageIcon img1 = new ImageIcon("/workspaces/Hacktoberfest2023/Program's_Contributed_By_Contributors/Java_Programs/Misc/Car Rental GUI/Car/Thar.jpg");
        JLabel il1 = new JLabel(img1);
        il1.setBounds(10, 50, 400,200);
        f.add(il1);
        JButton b1 = new JButton("Mahindra Thar 2021");
        b1.setBounds(120,260,200,20);
        f.add(b1);
        b1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setVisible(false);
                Thar thar = new Thar();
                thar.tharDet();
            }
        });

        ImageIcon img2 = new ImageIcon("/workspaces/Hacktoberfest2023/Program's_Contributed_By_Contributors/Java_Programs/Misc/Car Rental GUI/Car/Amaze.jpg");
        JLabel il2 = new JLabel(img2);
        il2.setBounds(420, 50, 400,200);
        f.add(il2);
        JButton b2 = new JButton("Honda Amaze 2018");
        b2.setBounds(530,260,200,20);
        f.add(b2);
        b2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setVisible(false);
                Amaze amaze = new Amaze();
                amaze.amazeDet();
            }
        });

        ImageIcon img3 = new ImageIcon("/workspaces/Hacktoberfest2023/Program's_Contributed_By_Contributors/Java_Programs/Misc/Car Rental GUI/Car/Nexon.jpg");
        JLabel il3 = new JLabel(img3);
        il3.setBounds(10, 300, 400,200);
        f.add(il3);
        JButton b3 = new JButton("Tata Nexon 2020");
        b3.setBounds(120,510,200,20);
        f.add(b3);
        b3.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setVisible(false);
                Nexon nexon = new Nexon();
                nexon.nexonDet();
            }
        });

        ImageIcon img4 = new ImageIcon("/workspaces/Hacktoberfest2023/Program's_Contributed_By_Contributors/Java_Programs/Misc/Car Rental GUI/Car/Ertiga.jpg");
        JLabel il4 = new JLabel(img4);
        il4.setBounds(420, 300, 400,200);
        f.add(il4);
        JButton b4 = new JButton("Maruti Ertiga 2021");
        b4.setBounds(530,510,200,20);
        f.add(b4);
        b4.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setVisible(false);
                Ertiga ertiga = new Ertiga();
                ertiga.ertigaDet();
            }
        });

        f.setVisible(true);
    }
}
