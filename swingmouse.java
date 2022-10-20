import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class prac02 implements MouseListener
{
Label label1, label2;
Frame frame;
String str;
prac02()
{
frame = new Frame("Window");
label1= new Label("Handling mouse events in the Frame window", Label.CENTER);
label2= new Label();
frame.setLayout(new FlowLayout());
frame.add(label1);
frame.add(label2);

//Registering class prac02 to catch and respond to mouse events 
frame.addMouseListener(this); 

frame.setSize(340,200);
frame.setVisible(true);
}
public void mouseClicked(MouseEvent we)
{
str+=" and Mouse button was clicked";
label2.setText(str);
frame.setVisible(true);
}
public void mouseEntered(MouseEvent we)
{
label2.setText("Mouse has entered the window area");
frame.setVisible(true);
}
public void mouseExited(MouseEvent we)
{
label2.setText("Mouse has exited the window area");
frame.setVisible(true);
}
public void mousePressed(MouseEvent we)
{
label2.setText("Mouse button is being pressed");
frame.setVisible(true);
}

public void mouseReleased(MouseEvent we)
{
str="Mouse button is released";
label2.setText(str);
frame.setVisible(true);
}
public static void main(String... ar)
{
new prac02();
}

}
