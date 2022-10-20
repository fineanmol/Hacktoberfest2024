package prs;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.*;

public class Lists {

	public static void main(String[] args) {
		JFrame f = new JFrame();
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(800,800);
		f.setLayout(new FlowLayout());
		JLabel j = new JLabel("Enter item");
		JTextField t= new JTextField();
		t.setColumns(10);
		f.add(j);
		f.add(t);
		JButton b= new JButton("Submit");
		f.add(b);
		DefaultListModel lis = new DefaultListModel();
		JList list = new JList(lis);
		f.add(list);
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				lis.addElement(t.getText());
				t.setText("");
			}
		});
		
	}
}

