import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class Server extends JFrame implements ActionListener {
    JTextField input;
    JPanel messages;

    Box vertical  = Box.createVerticalBox();
 Server(){
setSize(500,700);
setLocation(400,20);
setLayout(null);
getContentPane().setBackground(Color.WHITE);


JPanel panelTop = new JPanel();

panelTop.setBackground(new Color(7,100,0));
panelTop.setSize(5500,100);

panelTop.setLayout(null);


ImageIcon img = new ImageIcon(ClassLoader.getSystemResource("Icons/3.png"));
Image img1 = img.getImage().getScaledInstance(25,25,Image.SCALE_DEFAULT);
ImageIcon newImg = new ImageIcon(img1);

JLabel backButton = new JLabel(newImg);

backButton.setBounds(-15,-20,100,150);



backButton.addMouseListener(new MouseAdapter() {
    @Override
    public void mouseClicked(MouseEvent e) {
        System.exit(0);
    }
});




     ImageIcon imgFace = new ImageIcon(ClassLoader.getSystemResource("Icons/brock.png"));
     Image imgFace1 = imgFace.getImage().getScaledInstance(50,50,Image.SCALE_DEFAULT);
     ImageIcon newImgFace = new ImageIcon(imgFace1);

     JLabel profile = new JLabel(newImgFace);

     profile.setBounds(70,25,50,50);



     ImageIcon v = new ImageIcon(ClassLoader.getSystemResource("Icons/video.png"));
     Image v1 = v.getImage().getScaledInstance(30,30,Image.SCALE_DEFAULT);
     ImageIcon newV = new ImageIcon(v1);

     JLabel video = new JLabel(newV);

     video.setBounds(350,35,30,30);


     ImageIcon p = new ImageIcon(ClassLoader.getSystemResource("Icons/phone.png"));
     Image p1 = p.getImage().getScaledInstance(30,30,Image.SCALE_DEFAULT);
     ImageIcon newP = new ImageIcon(p1);

     JLabel phone = new JLabel(newP);

     phone.setBounds(410,35,30,30);




     ImageIcon i = new ImageIcon(ClassLoader.getSystemResource("Icons/3icon.png"));
     Image i1 = i.getImage().getScaledInstance(10,25,Image.SCALE_DEFAULT);
     ImageIcon newI = new ImageIcon(i1);

     JLabel imgDots = new JLabel(newI);

     imgDots.setBounds(460,35,10,25);



     JLabel name = new JLabel("Your Friend");
     name.setBounds(140, 15, 130,60);
     name.setForeground(Color.WHITE);
    name.setFont(new Font("San Serif",Font.BOLD,20));


     JLabel status = new JLabel("Always Online");
     status.setBounds(140, 35, 130,60);
     status.setForeground(Color.WHITE);
     status.setFont(new Font("San Serif",Font.PLAIN,10));


      input = new JTextField();
     input.setBounds(5,632,320,50);
input.setSize(380,50);
input.setFont(new Font("San Serif", Font.PLAIN,20));


JButton button = new JButton("Send");
button.setSize(100,50);
button.setForeground(Color.WHITE);
button.setBackground(new Color(7,100,0));
button.setBounds(390,632,100,50);
button.setFont(new Font("San Serif",Font.PLAIN,20));
button.addActionListener(this);


messages = new JPanel();
     messages.setBounds(5,105,490,520);

     panelTop.add(backButton);
panelTop.add(profile);
panelTop.add(name);
panelTop.add(video);
panelTop.add(phone);
panelTop.add(imgDots);
panelTop.add(status);
add(panelTop);
add(input);
add(messages);
add(button);


setUndecorated(true);
panelTop.setVisible(true);
     setVisible(true);

 }

    public static void main(String[] args) {
        new Server();
    }



    @Override
    public void actionPerformed(ActionEvent e) {
String output = input.getText();
       // System.out.println(output);



JPanel helper = formatMessage(output);



 messages.setLayout(new BorderLayout());

 JPanel right = new JPanel(new BorderLayout());
 right.add(helper,BorderLayout.LINE_END);
 vertical.add(right);


 vertical.add(Box.createVerticalStrut(15));
 messages.add(vertical,BorderLayout.PAGE_START);

 repaint();
 invalidate();
 validate();


 }


 public static JPanel formatMessage(String output){
JPanel panel = new JPanel();
panel.setLayout(new BoxLayout(panel,BoxLayout.Y_AXIS));

JLabel label = new JLabel(output);
label.setFont(new Font("Tahoma",Font.PLAIN,20));
panel.add(label);

return panel;
 }
}
