package prs;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
public class Radios {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame j=new JFrame("Demo");
		j.setVisible(true);
		j.setSize(500,500);
		j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		j.setLayout(new FlowLayout());
		JTabbedPane jt = new JTabbedPane();
		jt.setBounds(200,200,200,200);
		jt.add("Survey",new SurveyPanel());
		jt.add("Message",new MPanel());
		j.add(jt);
	}
}
class SurveyPanel extends JPanel
{
	SurveyPanel()
	{
		setLayout(new GridBagLayout());
		JLabel l = new JLabel("Did you make your 4 prs yet?");
		ButtonGroup bg = new ButtonGroup();
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.gridwidth = GridBagConstraints.REMAINDER;
		JRadioButton r1 = new JRadioButton("Yep!! The T-Shirt's mine >:)",true);
		JRadioButton r2 = new JRadioButton("Working on it :')");
		add(l,gbc);
		bg.add(r1);
		bg.add(r2);
		add(r1,gbc);
		add(r2,gbc);
	}
}
class MPanel extends JPanel
{
	MPanel()
	{
		JTextField t = new JTextField("Leave a nice message!");
		t.selectAll();
		JButton b= new JButton("Submit");
		add(t);
		add(b);
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e)
			{
				t.setText("Thank you for submitting");
			}
		});
	}
}

