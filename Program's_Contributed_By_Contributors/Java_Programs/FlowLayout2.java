import java.awt.*;
import javax.swing.*;
public class FlowLayout2
{
JFrame frameObj;

// constructor
FlowLayout2()
{
 // creating a frame object
 frameObj = new JFrame();

 // creating the buttons
 JButton b1 = new JButton("1");
 JButton b2 = new JButton("2");
 JButton b3 = new JButton("3");
 JButton b4 = new JButton("4");
 JButton b5 = new JButton("5");
 JButton b6 = new JButton("6");
 JButton b7 = new JButton("7");
 JButton b8 = new JButton("8");
 JButton b9 = new JButton("9");
 JButton b10 = new JButton("10");

 // adding the buttons to frame
 frameObj.add(b1); frameObj.add(b2); frameObj.add(b3); frameObj.add(b4);
 frameObj.add(b5); frameObj.add(b6); frameObj.add(b7); frameObj.add(b8);
 frameObj.add(b9); frameObj.add(b10);

 // parameterized constructor is used
 // where alignment is left
 // horizontal gap is 20 units and vertical gap is 25 units.
 frameObj.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 25));

 frameObj.setSize(300, 300);
 frameObj.setVisible(true);
}
// main method
public static void main(String argvs[])
{
 new FlowLayout2();
}
} 
