import javax.swing.*;
import java.awt.event.*;
import java.net.*;

public class IPFinder extends JFrame{
    // JLabel l;
    String url;
    // JButton b;
    // JFrame f;

    IPFinder() {
        
        try {
            url = JOptionPane.showInputDialog("Enter Name");
            InetAddress ia = InetAddress.getByName(url);
            String ip = ia.getHostAddress();
            JOptionPane.showMessageDialog(this, ip);
        } catch (UnknownHostException e1) {
            JOptionPane.showMessageDialog(this, e1.toString());
        }
    }

    

    public static void main(String[] args) {
        new IPFinder();
    }
}
