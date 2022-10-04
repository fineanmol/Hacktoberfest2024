import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Client extends JFrame{
    Socket socket;
    BufferedReader reader;
    PrintWriter writer;

    private JLabel jLabel = new JLabel("Client");
    private JTextArea messageArea = new JTextArea();
    private JButton button = new JButton("Send");
    private JTextField messageInput = new JTextField();
    private Font font = new Font("Ubuntu",Font.PLAIN,20);

    public Client() {
        try {
              makeGUI();
//            System.out.println("Sending request to server...");
//            socket = new Socket("127.0.0.1", 6666);
//            System.out.println("Connection established");
//
//            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
//            writer = new PrintWriter(socket.getOutputStream());
//
//            read();
//            write();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private  void makeGUI() {
        this.setTitle("Client Messenger");
        this.setSize(800,700);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        jLabel.setFont(font);
        messageArea.setFont(font);
        messageInput.setFont(font);
        this.setLayout(new BorderLayout());
        this.add(jLabel,BorderLayout.NORTH);
        this.add(messageArea,BorderLayout.CENTER);
        this.add(messageInput,BorderLayout.SOUTH);
        this.add(button,BorderLayout.SOUTH);
        messageInput.setSize(60,60);
        messageInput.setMargin(new Insets(5,10,5,10));
        jLabel.setHorizontalAlignment(SwingConstants.CENTER);
        messageInput.setHorizontalAlignment(SwingConstants.LEFT);
        var hm = new HashMap<Integer,Integer>();
        hm.co
    }

    private void write() {
        Runnable runnable = () -> {
            System.out.println("Writer started");
            try {
                while (true) {
                    BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
                    String message = read.readLine();
                    writer.println(message);
                    writer.flush();
                    if(message.equals("exit")){
                         socket.close();
                         break;
                    }
                }

            } catch (Exception e) {
                System.out.println("Socket Connection terminated");
            }
            System.out.println("Connection Closed");
        };
        new Thread(runnable).start();
    }

    private void read() {
        Runnable runnable = () -> {
            try {
                while (!socket.isClosed()) {
                    String message = reader.readLine();
                    if (message.equals("exit")) {
                        System.out.println("Server terminated the chat");
                        socket.close();
                        break;
                    }
                    System.out.println("Server - " + message);
                }
            } catch (IOException e) {
                System.out.println("Socket Connection closed");
            }
        };
        new Thread(runnable).start();
    }

    public static void main(String[] args) {
        System.out.println("Client Started...");
        new Client();
    }
}
