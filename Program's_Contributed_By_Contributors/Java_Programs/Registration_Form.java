import javax.swing.*;
import java.awt.*;
import java.awt.Color;
import java.awt.event.*;

public class Registration_Form implements ActionListener {

    public  JFrame frame,frame2;
    public JLabel label1, label2, label3, label4, label5, label6, label7, label8,l1,l2;
    JTextField text1, text2, text3, text4;
    JTextArea area=new JTextArea();
    JComboBox combo;
    JRadioButton male, female;
    JCheckBox chck;
    JPasswordField pass;
    JButton Register, Clear;

    public Registration_Form() {
        ImageIcon image = new ImageIcon("logo.png");
        frame = new JFrame("Admission Form");
        frame.setIconImage(image.getImage());

        label1 = new JLabel("REGISTRATION FORM");
        label1.setFont(new Font(null, Font.BOLD, 20));
        label1.setBounds(130, 20, 235, 50);


        label2 = new JLabel("Username:");
        label2.setFont(new Font(null, Font.PLAIN, 20));
        label2.setBounds(70, 125, 200, 50);

        text1 = new JTextField();
        text1.setBounds(200, 140, 200, 20);

        label3 = new JLabel("Password:");
        label3.setFont(new Font(null, Font.PLAIN, 20));
        label3.setBounds(70, 190, 200, 20);

        pass = new JPasswordField();
        pass.setBounds(200, 190, 200, 20);

        label4 = new JLabel("Email:");
        label4.setFont(new Font(null, Font.PLAIN, 20));
        label4.setBounds(70, 260, 200, 50);

        text2 = new JTextField();
        text2.setBounds(200, 280, 200, 20);

        label5 = new JLabel("Gender:");
        label5.setFont(new Font(null, Font.PLAIN, 20));
        label5.setBounds(70, 215, 200, 50);

        male = new JRadioButton();
        male.setBounds(200, 232, 80, 15);
        male.setText("male");
        male.setBackground(Color.lightGray);
        male.setFocusable(false);
        male.addActionListener(this);
        male.setOpaque(false);

        female = new JRadioButton();
        female.setText("female");
        female.setBackground(Color.lightGray);
        female.setBounds(300, 232, 80, 15);
        female.setFocusable(false);
        female.addActionListener(this);
        female.setOpaque(false);

        ButtonGroup group = new ButtonGroup();
        group.add(male);
        group.add(female);

        label6 = new JLabel("City:");
        label6.setFont(new Font(null, Font.PLAIN, 20));
        label6.setBounds(70, 300, 200, 50);

        String Cities[] = {"Hyderabad", "Lahore", "Dadu", "Karachi", "Larkano", "Jamshoro", "Sukkur"};
        combo = new JComboBox(Cities);
        combo.setBounds(200, 320, 200, 20);

        label7 = new JLabel("Country:");
        label7.setFont(new Font(null, Font.PLAIN, 20));
        label7.setBounds(70, 340, 200, 50);

        text3 = new JTextField();
        text3.setBounds(200, 360, 200, 20);

        label8 = new JLabel("Phone#");
        label8.setFont(new Font(null, Font.PLAIN, 20));
        label8.setBounds(70, 380, 200, 50);

        text4 = new JTextField();
        text4.setBounds(200, 395, 200, 20);

        chck = new JCheckBox();
        chck.setText("Accept terms and Conditions ");
        chck.setFont(new Font(null, Font.BOLD, 20));
        chck.setBounds(90, 460, 320, 25);
        chck.setOpaque(false);
        chck.addActionListener(this);

        Register = new JButton("Register");
        Register.setFont(new Font("Arial", Font.BOLD, 15));
        Register.setBounds(180, 500, 100, 40);
        Register.setFocusable(false);
        Register.setEnabled(false);
        Register.addActionListener(this);

        Clear = new JButton("Clear");
        Clear.setFont(new Font("Arial", Font.BOLD, 15));
        Clear.setBounds(300, 500, 100, 40);
        Clear.setFocusable(false);
        Clear.addActionListener(this);

        frame.setSize(500, 700);
        frame.setLayout(null);
        frame.setResizable(true);
        frame.getContentPane().setBackground(Color.YELLOW);//light blue color
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(label1);
        frame.add(label2);
        frame.add(text1);
        frame.add(label3);
        frame.add(pass);
        frame.add(label4);
        frame.add(text2);
        frame.add(label5);
        frame.add(male);
        frame.add(female);
        frame.add(label6);
        frame.add(combo);
        frame.add(label7);
        frame.add(text3);
        frame.add(label8);
        frame.add(text4);
        frame.add(chck);
        frame.add(Register);
        frame.add(Clear);
        frame.setResizable(false);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == chck) {
            if (chck.isSelected()) {
                Register.setEnabled(true);
            }
            else{
                Register.setEnabled(false);
            }
        }
        else if(e.getSource()==Register){
            String gender="",city="",Country="",number="";
            boolean found=false;
            String user=text1.getText();
            String email=text2.getText();

            int n= email.indexOf("@",0);
            if(n!=-1) {
                if (male.isSelected()) {
                    gender = "Male";
                } else if (female.isSelected()) {
                    gender = "Female";
                }
                city = String.valueOf(combo.getSelectedItem());
                Country = String.valueOf(text3.getText());
                number = text4.getText();
                if (!number.matches("[0-9]+")) {

                    JOptionPane.showMessageDialog(frame,
                            "Phone number must be in digits", "Error", JOptionPane.ERROR_MESSAGE);
                }
                else {
                    JOptionPane.showMessageDialog(frame, "Registration Successful");

                    area.setBounds(0, 0, 450, 420);
                    area.setText("\n\n\nUsername:\t" + user + "\nEmail:\t" + email + "\nGender:\t" + gender +
                            "\nCity:\t" + city + "\nCountry:\t" + Country + "\nPhone no#:\t" + number);
                    area.setFont(new Font("Arial", Font.BOLD, 15));
                    area.setBackground(Color.white);

                    JOptionPane.showMessageDialog(null,area);
                }
            }
            else{
                JOptionPane.showMessageDialog(frame,
                        "provide @ in email","Error",JOptionPane.ERROR_MESSAGE); }
        }
        else if(e.getSource()==Clear){
            area.setText("");
            text1.setText("");
            pass.setText("");
            text2.setText("");
            text3.setText("");
            text4.setText("");
        }
    }
    public static void main(String[] args) {
        new Registration_Form();
    }
}

