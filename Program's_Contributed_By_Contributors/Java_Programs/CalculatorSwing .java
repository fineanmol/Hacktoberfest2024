import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculatorapplication implements ActionListener {

    JTextField t1, t2, t3;
    JButton add, sub,pro;

    Calculatorapplication() {
        JFrame j = new JFrame("Calculator");
        t1 = new JTextField();
        t1.setBounds(50, 50, 150, 20);
        t2 = new JTextField();
        t2.setBounds(50, 100, 150, 20);
        t3 = new JTextField();
        t3.setBounds(50, 150, 150, 20);
        t3.setEditable(false);
        add = new JButton("+");
        add.setBounds(50, 200, 50, 50);
        sub = new JButton("-");
        sub.setBounds(120, 200, 50, 50);
        pro = new JButton("*");
        pro.setBounds(50, 270, 50, 50);
        add.addActionListener(this::actionPerformed);
        sub.addActionListener(this::actionPerformed);
        pro.addActionListener(this::actionPerformed);
        j.add(t1);
        j.add(t2);
        j.add(t3);
        j.add(add);
        j.add(sub);
        j.add(pro);
        j.setSize(1000, 1000);
        j.setLayout(null);
        j.setVisible(true);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        String s1 = t1.getText();
        String s2 = t2.getText();
        int n1 = Integer.parseInt(s1);
        int n2 = Integer.parseInt(s2);
        int c = 0;
        if (e.getSource() == add) {
            c = n1 + n2;
        } else if (e.getSource() == sub) {
            c = n1 - n2;
        }
        else if (e.getSource()== pro) {
            c= n1*n2;
        }
        String result = String.valueOf(c);
        t3.setText(result);

    }

    public static void main(String[] args) {
        new Calculatorapplication();
    }
}


