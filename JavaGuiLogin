package LoginSystem;
import java.util.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.sql.*;
public class Login extends Jdbc implements ActionListener
{
    JFrame frame =new JFrame();
    JButton loginButton =new JButton("LOGIN");
    JButton reset =new JButton("RESET");
    JTextField userIDField= new JTextField();
    JPasswordField  userpasswordfield = new JPasswordField();
    JLabel userIDLabel=new JLabel("userID");
    JLabel password=new JLabel("Password");
    JLabel message=new JLabel();
    
    public Login()
    {
        
       userIDLabel.setBounds(50,100,75,25);
       password.setBounds(50,150,75,25);
       message.setBounds(125,250,250,35);
       message.setFont(new Font(null,Font.ITALIC,25));
       userIDField.setBounds(125,100,200,25);
       userpasswordfield.setBounds(125,150,200,25);
       loginButton.setBounds(125,200,100,25);
       loginButton.addActionListener(this);
       reset.setBounds(225,200,100,25);
       reset.addActionListener(this);
       frame.add(userIDLabel);
       frame.add(userIDField);
       frame.add(password);
       frame.add(userpasswordfield);
       frame.add(message);
       frame.add(loginButton);
       frame.add(reset);
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       frame.setSize(450,450);
       frame.setLayout(null);
       frame.setVisible(true);
       
       
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource()==reset)
        {
            userIDField.setText(" ");
            userpasswordfield.setText("");
        }
        if(e.getSource()==loginButton)
        {
            String userID=userIDField.getText();
            String userpassword=String.valueOf(userpasswordfield.getPassword());
            String s=userIDField.getText();
            String h=userpasswordfield.getText();
            Jdbc c1=new Jdbc();
                  String query;
                  
                  String query2="select * from data Where userid='"+s+"'";
                  String query3="select * from data Where password='"+h+"'";
            try
            {
                      Statement st=c.createStatement();
                      ResultSet rs=st.executeQuery(query2);
                      Statement mn= c.createStatement();
                      ResultSet pq=mn.executeQuery(query3);
                       if(rs.next())
                    {
                      if(pq.next())
                      {
                        message.setForeground(Color.green);
                        message.setText("login successful");
                        frame.dispose();
                       WelcomePage welcomepage=new WelcomePage(userID);
                    }
                       else
                     {
                       message.setForeground(Color.red);
                       message.setText("login unsuccessful");
              
                        }
                   }
            
               else
              {
    
                  message.setText("New User");
                  try
                  {
                     query="insert into data values('"+s+"','"+h +"')";
                     c1.s.executeUpdate(query);
                  }
                  catch(Exception eh)
                  {
                      System.out.println(eh);
                  }
            }
              }
             catch(Exception eq)
                  {
                      System.out.println(eq);
                }
                  }
                 
    
           
            
        
    }
}


