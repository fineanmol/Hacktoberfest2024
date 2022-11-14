import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;
public class calculate {
	public static void main(String[] args)
	{
		JFrame base= new JFrame("Calculator");
		base.setSize(400,600);
		base.setVisible(true);
		base.setLayout(new FlowLayout());
		base.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton add=new JButton("+");
		JButton sub = new JButton("-");
		JButton mul = new JButton("x");
		JButton div= new JButton("/");
		JLabel soln= new JLabel();
		JTextField n1= new JTextField();
		JTextField n2= new JTextField();
		n1.setColumns(10);
		n2.setColumns(10);
		base.add(n1);
		base.add(n2);
		base.add(soln);
		base.add(add);
		base.add(sub);
		base.add(mul);
		base.add(div);
		add.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				soln.setText(String.valueOf(Integer.parseInt(n1.getText())+Integer.parseInt(n2.getText())));
			}
		});
		sub.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				soln.setText(String.valueOf(Integer.parseInt(n1.getText())-Integer.parseInt(n2.getText())));
			}
		});
		mul.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				soln.setText(String.valueOf(Integer.parseInt(n1.getText())*Integer.parseInt(n2.getText())));
			}
		});
		div.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(n2.getText().equals("0"))
					soln.setText("math error");
				else	
				soln.setText(String.valueOf(Integer.parseInt(n1.getText())/Integer.parseInt(n2.getText())));
			
			}
			
		});
	}
}
