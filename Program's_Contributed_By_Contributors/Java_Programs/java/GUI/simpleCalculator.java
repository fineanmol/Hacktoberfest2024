//GUI program to accept two numbers from the user and calculate the sum,difference,multiplication & division 
//on the clicks of specific button.
package src.college.understanding_GUI;

import java.awt.*;
import java.awt.event.*;

class SimpleCalculator extends Frame implements ActionListener {
    Label l, l2, l3;
    TextField tf, tf2, tf3;
    Button a, s, m, d, c;

    SimpleCalculator(String s) {
        super(s);
    }

    void createWindow() {
        l = new Label("Number 1");
        l2 = new Label("Number 2");
        l3 = new Label("Result");
        tf = new TextField(12);
        tf2 = new TextField(12);
        tf3 = new TextField(12);
        a = new Button("Add(+)");
        s = new Button("Sub(-)");
        m = new Button("Multy(x)");
        d = new Button("Div(/)");
        c = new Button("Clear");

        setLayout(new FlowLayout());
        add(l);
        add(tf);
        add(l2);
        add(tf2);
        add(l3);
        add(tf3);
        add(a);
        add(s);
        add(m);
        add(d);
        add(c);

        setSize(240, 350);
        setVisible(true);
        setBackground(Color.pink);

        a.addActionListener(this);
        s.addActionListener(this);
        m.addActionListener(this);
        d.addActionListener(this);
        c.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        int n1 = Integer.parseInt(tf.getText());
        int n2 = Integer.parseInt(tf2.getText());

        if (e.getSource() == a) {
            setBackground(Color.red);
            tf3.setText("" + (n1 + n2));
        }
        if (e.getSource() == s) {
            setBackground(Color.green);
            tf3.setText("" + (n1 - n2));
        }
        if (e.getSource() == m) {
            setBackground(Color.blue);
            tf3.setText("" + (n1 * n2));
        }
        if (e.getSource() == d) {
            setBackground(Color.yellow);
            tf3.setText("" + (n1 / n2));
        }
        if (e.getSource() == c) {
            setBackground(Color.black);
            tf.setText("");
            tf2.setText("");
            tf3.setText("");
        }
    }

    public static void main(String[] args) {
        SimpleCalculator c = new SimpleCalculator("Simple Calculator");
        c.createWindow();
    }
}