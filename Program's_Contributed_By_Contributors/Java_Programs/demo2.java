import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionListener;
import java.util.Random;
import java.awt.event.ActionEvent;

public class demo2 {
	
	static int count;
	static JLabel score;

	public static void main(String[] args) {
		
		count = 5;
		JFrame frame = new JFrame("Dice game");
		//creating frame
		frame.setSize(700,700);
		frame.setLayout(new GridLayout(3,1));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		//setting up frame
		JPanel scorePanel = new JPanel();
		JPanel buttonPanel = new JPanel();
		JPanel rulesPanel = new JPanel();
		JPanel compPanel1 = new JPanel();
		JPanel turnPanel = new JPanel();
		//creating panels
		rulesPanel.setBorder(new TitledBorder("Rules"));
		rulesPanel.setLayout(new FlowLayout());
		buttonPanel.setBorder(new TitledBorder("Actions"));
		buttonPanel.setLayout(new GridLayout(3,2));
		scorePanel.setBorder(new TitledBorder("Scoreboard"));
		scorePanel.setLayout(new GridLayout(2,2));
		compPanel1.setBorder(new TitledBorder("Turns and score"));
		compPanel1.setLayout(new GridLayout(1,2));
		turnPanel.setBorder(new TitledBorder("Turn"));
		turnPanel.setLayout(new FlowLayout());
		//setting up panels
		
		JLabel rules = new JLabel("<html><ul>" +
		        "<li>Select even or odd</li>" +             
		        "<li>Roll the dice</li>" + 
		        "<li>Each player has 5 turns</li>" + 
		        "<li>If player chooses EVEN and rolls an ODD number, +100 points</li>" + 
		        "<li>If player chooses ODD and rolls an EVEN number, -50 points</li>" + 
		        "<li>Thus, in general, when the user chooses what he rolls, +100, else -50</li>" + 
		        "<li>Click on Next Player to pass the chance</li>" + 
		        "</ul><html>");
		
		JLabel score1 = new JLabel("0");
		JLabel score2 = new JLabel("0");
		
		
		JLabel player = new JLabel("Player 1");
		player.setFont(new Font("Mono", Font.BOLD, 20));
		JLabel turn= new JLabel("Turns left: 5");
		JLabel result = new JLabel("Result: ");
		
		JLabel pl1 = new JLabel("Player 1");
		JLabel pl2 = new JLabel("Player 2");
		
		JButton next = new JButton("Next Player");
		JButton roll = new JButton("Roll Dice");
		
		JRadioButton even = new JRadioButton("Even",true);
		JRadioButton odd = new JRadioButton("Odd");
		ButtonGroup g = new ButtonGroup();
		g.add(even);
		g.add(odd);
		
		//--------------------------------------------- Panel additions ---------------------------------------------
				rulesPanel.add(rules);
				buttonPanel.add(even);
				buttonPanel.add(odd);
				buttonPanel.add(roll);
				buttonPanel.add(next);
				buttonPanel.add(turn);
				buttonPanel.add(result);
				scorePanel.add(pl1);
				scorePanel.add(pl2);
				scorePanel.add(score1);
				scorePanel.add(score2);
				turnPanel.add(player);
				compPanel1.add(scorePanel);
				compPanel1.add(turnPanel);
		//--------------------------------------------- Panel additions ---------------------------------------------
		//--------------------------------------------- Frame additions ---------------------------------------------
		frame.add(rulesPanel);
		frame.add(compPanel1);
		frame.add(buttonPanel);
		next.setEnabled(false);
		//--------------------------------------------- Frame additions ---------------------------------------------

		roll.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e)
			{
				Random random = new Random();
				
				int r = random.nextInt(1,6);
				count--;
				
				turn.setText("Turns left: " + count);
				result.setText("Result: " + r);
				
				if(player.getText().equals("Player 1"))
					score = score1;
				else 
					score = score2;
				
				int s = Integer.parseInt(score.getText());
				boolean isEven = r%2==0?true:false;
				boolean evenSelected = even.isSelected();
				if((isEven && evenSelected) || (!isEven && !evenSelected))
					s += 100;
				else
					s -= 50;
				score.setText(String.valueOf(s));
				
				if(count == 0 && player.getText().equals("Player 1"))
				{
					roll.setEnabled(false);
					next.setEnabled(true);
				}
				else if (count ==0 && player.getText().equals("Player 2"))
				{
					next.setEnabled(false);
					roll.setEnabled(false);
					int s1 = Integer.parseInt(score1.getText());
					int s2 = Integer.parseInt(score2.getText());
					String text = (s1==s2)? "Draw!" : (s1>s2 ? "Player 1": "Player 2")+" is the winner!";
					JOptionPane.showMessageDialog(null, text);
				}
				else
					next.setEnabled(false);
			}
		});
		next.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e)
			{
				if(player.getText().equals("Player 1"))
				{
					player.setText("Player 2");
					roll.setEnabled(true);
					next.setEnabled(false);
					count = 5;
					turn.setText("Turns left: " + count);
				}
			}
		});
	}
}
