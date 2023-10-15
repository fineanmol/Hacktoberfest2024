import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Rent {
    public void rentACar(){
        JFrame f = new JFrame("RENT A CAR!");
        f.setLocation(550, 250);
        f.setSize(450, 350);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);
        JLabel l0 = new JLabel();
        f.add(l0);
        l0.setText("Please provide more details to rent!");
        l0.setFont(new Font("", Font.BOLD,14));
        l0.setBounds(50, 10, 1000, 30);

        JLabel l1=new JLabel("Choose your city:");
        l1.setBounds(65,50,100,20);
        f.add(l1);        
        String items1[]={"Chennai","Coimbatore","Madurai","Tiruchirapalli","Salem","Ambattur","Tirunelveli","Tiruppur","Avadi","Tiruvottiyur"};
        JComboBox list1 = new JComboBox(items1);
        list1.setBounds(180, 50, 100, 20);
        f.add(list1);

        JLabel l2=new JLabel("Choose the date:");
        l2.setBounds(65,90,100,20);
        f.add(l2);    
        JLabel l5=new JLabel("(DD/MM/YYYY)");
        l5.setBounds(65,105,100,20);
        f.add(l5);         
        String items2[]={"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
        JComboBox list2 = new JComboBox(items2);
        list2.setBounds(180, 90, 40, 20);
        f.add(list2);
        String items3[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        JComboBox list3 = new JComboBox(items3);
        list3.setBounds(220, 90, 80, 20);
        f.add(list3);
        String items7[]={"2023"};
        JComboBox list7 = new JComboBox(items7);
        list7.setBounds(300, 90, 60, 20);
        f.add(list7);

        JLabel l4=new JLabel("Choose the time:");
        l4.setBounds(65,130,100,20);
        f.add(l4);        
        JLabel l6=new JLabel("(hh/mm/A)");
        l6.setBounds(65,145,100,20);
        f.add(l6); 
        String items4[]={"00","01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
        JComboBox list4 = new JComboBox(items4);
        list4.setBounds(180, 130, 40, 20);
        f.add(list4);
        String items5[]={"00","01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59"};
        JComboBox list5 = new JComboBox(items5);
        list5.setBounds(220, 130, 40, 20);
        f.add(list5);
        String items6[]={"AM","PM"};
        JComboBox list6 = new JComboBox(items6);
        list6.setBounds(260, 130, 50, 20);
        f.add(list6);

        JLabel l7=new JLabel("Number of hours:");
        l7.setBounds(65,170,100,20);
        f.add(l7);        
        String items8[]={"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"};
        JComboBox list8 = new JComboBox(items8);
        list8.setBounds(180, 170, 50, 20);
        f.add(list8);

        JButton b1 = new JButton("Select");
        f.add(b1);
        b1.setBounds(150,225,100,20);

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setVisible(false);
                Available avl = new Available();
                avl.avlCars();
            }
        });
        f.setVisible(true);
    } 
}